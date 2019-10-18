#ifndef WEBSOCKET_HPP
#define WEBSOCKET_HPP

#include "App.h"
#include "bridge/bridge.hpp"
#include "bridge/portauthority.hpp"
#include <memory>

namespace logbook
{

class websocket
{
public:
  websocket(const websocket& rhs) = delete;
  websocket& operator=(const websocket& rhs) = delete;

  websocket(std::shared_ptr<BookShelf> bookShelf);
  ~websocket();

  void run(int port);
  
private:
  uWS::App httpListener;
  std::shared_ptr<BookShelf> bookShelf;
  PortAuthority auth;
  
  const std::string rootDir;
  const std::string indexPage;
};

}

#endif // WEBSOCKET_HPP
