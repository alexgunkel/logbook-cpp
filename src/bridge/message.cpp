#include "bridge.hpp"

#include <ctime>
#include <cstring>
#include <string>
#include <stdexcept>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace logbook {

static boost::uuids::string_generator gen;

using InvalidInput = std::runtime_error;

Message::Message(
  const message_t& msg,
  const logbook_name_t& identifier,
  const journey_t& journey
  ): msg{msg}, logbookName{identifier}, journey{journey} {
    
};

Message *Message::fromBufferString(char buf[], size_t length) {
  auto pos = std::strchr(buf, ':');

  if (pos-buf > length) {
    throw new InvalidInput{"could not read identifier"};
  }

  severity_t sev = *(pos+2) - '0';
  if (sev > 7) {
    throw new InvalidInput{"severity value is invalid"};
  }

  std::string uuid{buf, pos};

  try {
    auto result = new Message{"test", gen(uuid), "asd"};
    result->severity = sev;

    return result;
  } catch (std::runtime_error e) {
    throw new InvalidInput{e.what()};
  }
}

Message::~Message()
{
}


logbook_name_t Message::LogbookName() const noexcept
{
    return this->logbookName;
}

journey_t Message::Journey() const noexcept
{
  return this->journey;
}

message_t Message::Content() const noexcept
{
  return this->msg;
}

const time_t Message::Created() const noexcept
{
  return this->created;
}

severity_t Message::Severity() const noexcept
{
  return this->severity;
}

} // namespace logbook
