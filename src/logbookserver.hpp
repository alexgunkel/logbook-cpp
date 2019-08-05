#ifndef LOGBOOKSERVER_HPP
#define LOGBOOKSERVER_HPP

#include <memory>
#include "bridge/bridge.hpp"

namespace logbook {
  
class LogbookServer
{
public:
  LogbookServer();
  LogbookServer(const LogbookServer& rhs) = delete;
  LogbookServer& operator=(const LogbookServer& rhs) = delete;

  ~LogbookServer();

  void Run();

private:
  std::unique_ptr<CrowsNestInterface> listener;
};

} // namespace logbook

#endif // LOGBOOKSERVER_HPP
