#include "logbookserver.hpp"
#include "bridge/bridge.hpp"
#include "crows_nest/udplistener.hpp"
#include "books/ostreamwriter.h"
#include "books/websocket.hpp"

logbook::LogbookServer::LogbookServer()
{
  this->bookshelf = std::make_shared<logbook::BookShelf>(120);
  
  auto desk = std::make_shared<CaptainsDesk>(this->bookshelf);
  
  listener = std::make_unique<logbook::UdpListener>(1409);
  listener->attachReceiver(desk);
}

void logbook::LogbookServer::Run() {
  
  std::thread udp([this]() {this->listener->Run();});
  std::thread ws([this]() {
    auto websocket = std::make_unique<logbook::websocket>(this->bookshelf);
    websocket->run(1410);
  });
  
  udp.join();
  ws.join();
}

logbook::LogbookServer::~LogbookServer()
{
}

