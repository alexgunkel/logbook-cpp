#include "bridge.hpp"

#include <memory>

using std::make_shared;

namespace logbook {

CaptainsDesk::CaptainsDesk(): CaptainsDesk{make_shared<BookShelf>(100)} {};

CaptainsDesk::CaptainsDesk(shared_ptr<BookShelf> shelf): bookShelf{shelf} {};

void CaptainsDesk::receive(const Message& msg)
{
    bookShelf->findByShipName(msg.ShipName()).Write(msg);
}

} // namespace logbook
