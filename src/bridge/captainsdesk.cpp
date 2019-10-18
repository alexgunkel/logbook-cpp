#include "bridge.hpp"

#include <memory>
#include <iostream>
#include <stdexcept>
#include <boost/uuid/uuid_io.hpp>

using std::make_shared;

namespace logbook {

CaptainsDesk::CaptainsDesk(): CaptainsDesk{make_shared<BookShelf>(100)} {};

CaptainsDesk::CaptainsDesk(shared_ptr<BookShelf> shelf): bookShelf{shelf} {};

void CaptainsDesk::receive(const Message& msg)
{
    try {
            bookShelf->findByShipName(msg.LogbookName()).Write(msg);
    } catch (std::out_of_range oor) {
        std::cerr << oor.what() << " for identifier" << msg.LogbookName() << std::endl;
    }
}

} // namespace logbook
