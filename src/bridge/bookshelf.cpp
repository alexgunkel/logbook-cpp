#include "bridge.hpp"

#include <memory>
#include <iostream>
#include <stdexcept>
#include <boost/uuid/uuid_io.hpp>

using std::unique_ptr;
using std::forward;

namespace logbook {

BookShelf::BookShelf(): BookShelf{100} {};

BookShelf::BookShelf(size_t capacity): maxNumberOfBooks{capacity} {};

BookShelf::~BookShelf() {};

void BookShelf::add(unique_ptr<BookInterface> bookPtr)
{
  std::cout << "register book " << bookPtr->LogbookName() << std::endl;
    listOfBooks.push_back(forward<unique_ptr<BookInterface>>(bookPtr));
}

BookInterface & BookShelf::findByShipName(logbook::logbook_name_t ship) const
{
    for (auto it = listOfBooks.begin(); it != listOfBooks.end(); ++it)  {
      std::cout << "found a log-book for " << ship << std::endl;
        return **it;
    }
    
    throw std::out_of_range{"no log-book found for ship-name"};
}

} // namespace logbook
