#include "bridge.hpp"

#include <ctime>

namespace logbook {

Message::Message(const message_t& msg, const ship_name_t& ship, const journey_t& journey): msg{msg}, shipName{ship}, journey{journey} {
    
};

Message::~Message()
{
}


ship_name_t Message::ShipName() const noexcept
{
    return shipName;
}

journey_t Message::Journey() const noexcept
{
  return journey;
}

message_t Message::Content() const noexcept
{
  return msg;
}

} // namespace logbook
