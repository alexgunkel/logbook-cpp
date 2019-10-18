#ifndef LOGBOOK_MESSAGE_HPP_
#define LOGBOOK_MESSAGE_HPP_
#include <set>
#include <string>
#include <ctime>
#include <boost/uuid/uuid.hpp>

namespace logbook {

typedef boost::uuids::uuid logbook_name_t;
typedef const char* journey_t;
typedef uint severity_t;
typedef std::time_t time_t;
typedef std::string message_t;
typedef const char* passenger_t;
typedef std::set<passenger_t> passenger_list_t;

class Message {
public:
    Message(const message_t& msg, const logbook_name_t& ship, const journey_t& journey);
    ~Message();

    static Message *fromBufferString(char buf[], size_t length);

    logbook_name_t LogbookName() const noexcept;
    journey_t Journey() const noexcept;
    const time_t Received() const noexcept;
    const time_t Created() const noexcept;
    message_t Content() const noexcept;
    severity_t Severity() const noexcept;

private:
    message_t msg;
    logbook_name_t logbookName;
    journey_t journey;
    severity_t severity{0};
    time_t received;
    time_t created;
    passenger_list_t passengerList;
};

} // namespace logbook

#endif