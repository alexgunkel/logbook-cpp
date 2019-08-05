#include "logbookserver.hpp"
#include "bridge/bridge.hpp"
#include "crows_nest/udplistener.hpp"
#include "books/ostreamwriter.h"

logbook::LogbookServer::LogbookServer()
{
  auto shelf = std::make_shared<logbook::BookShelf>(120);
  shelf->add(std::make_unique<logbook::OstreamWriter>("MSS Hope"));
  
  auto desk = std::make_shared<CaptainsDesk>(shelf);
  
  listener = std::make_unique<logbook::UdpListener>();
  listener->attachReceiver(desk);
}

void logbook::LogbookServer::Run() {
  listener->Run();
}

logbook::LogbookServer::~LogbookServer()
{
}

