#ifndef WEBSOCKET_HPP
#define WEBSOCKET_HPP

namespace logbook
{

class websocket
{
public:
  websocket(const websocket& rhs) = delete;
  websocket& operator=(const websocket& rhs) = delete;

  websocket();
  ~websocket();

};

}

#endif // WEBSOCKET_HPP
