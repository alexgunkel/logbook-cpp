#ifndef LOGBOOK_BRIDGE_BRIDGE_HPP_
#define LOGBOOK_BRIDGE_BRIDGE_HPP_

#include "message.hpp"

#include <memory>
#include <ctime>
#include <string>
#include <set>
#include <vector>

namespace logbook {

using std::unique_ptr;
using std::shared_ptr;

class ReceiverInterface
 {
public:
    virtual void receive(const Message&) = 0;
};

/**
 * Crow's nests are the sources of logbook-input.
 */
class CrowsNestInterface {
  public:
    /**
     * attaches a callback function to the crow's nest.
     */
    virtual void attachReceiver(std::shared_ptr<ReceiverInterface> receiver) = 0;
    virtual void Run() = 0;
};

class BookInterface {
    public:
    virtual ~BookInterface() {};
    /**
     * Writes the message to the book.
     */
    virtual void Write(const Message&) = 0;

    /**
     * Individual logbook users are identified by ship-names.
     */
    virtual const logbook_name_t LogbookName() = 0;
};

class BookShelf {
public:
    BookShelf();
    explicit BookShelf(size_t maxNumberOfBooks);
    BookShelf(const BookShelf&) = delete;
    BookShelf& operator=(const BookShelf&) = delete;

    BookShelf(BookShelf&& bs);
    BookShelf& operator=(BookShelf&& bs);

    ~BookShelf();

    void add(unique_ptr<BookInterface> bookPtr);
    BookInterface& findByShipName(logbook_name_t ship) const;
private:
    std::size_t maxNumberOfBooks;
    std::vector<std::unique_ptr<BookInterface>> listOfBooks;
};

class CaptainsDesk: public ReceiverInterface
 {
public:
    CaptainsDesk();
    explicit CaptainsDesk(shared_ptr<BookShelf>);

    void receive(const logbook::Message & ) override;
private:
    shared_ptr<BookShelf> bookShelf;
};

} // namespace logbook

#endif

