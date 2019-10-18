#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#define RAPIDJSON_HAS_STDSTRING true // activate string-usage in rapidJSON

#include <string>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace logbook
{

namespace ws
{

class Message
{
public:
  Message(const Message& rhs) = delete;
  
  Message& operator=(const Message& rhs) = delete;

  Message(std::string content, int severity, std::string context): message{content}, severity{severity}, context{context}
  {
    
  }
  
  ~Message()
  {
  }
  
  std::string toJson() {
    rapidjson::StringBuffer sb;
    rapidjson::Writer<rapidjson::StringBuffer> w{sb};
    
    w.StartObject();
    w.Key("message");
    w.String(message);
    w.Key("context");
    w.String(context);
    w.Key("severity");
    w.Uint(severity);
    w.Key("logger");
    w.String(logger);
    w.Key("application");
    w.String(application);
    w.Key("request_uri");
    w.String(requestUri);
    w.Key("request_id");
    w.String(requestId);
    w.EndObject();
    
    return sb.GetString();
  };

  const std::string message;
  const int severity;
  const std::string context{};
  std::string requestId{};
  std::string logger{};
  std::string application{};
  std::string requestUri{};
};

}

}

#endif // MESSAGE_HPP
