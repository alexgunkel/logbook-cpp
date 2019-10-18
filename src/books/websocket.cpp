#include "websocket.hpp"

#include "App.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include "books/websocket/message.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace logbook {

static std::string findCwd() {
  char buff[120];
  getcwd(buff, 120);
  return std::string{buff};
}

static std::string fetchIndexPage(std::string path) {
      std::ifstream ifs(path, std::ifstream::in);
      std::string indexPage( (std::istreambuf_iterator<char>(ifs) ),
                          (std::istreambuf_iterator<char>()    ) );
                          
      return indexPage;
}

static boost::uuids::random_generator gen;

class middleware : public BookInterface
{
  private:
  const boost::uuids::uuid name;
  uWS::WebSocket<false, true> *ws;
  public:
  middleware(uWS::WebSocket<false, true> *socket): name{gen()}, ws{socket} {
          ws::Message msg{to_string(name), 4, "context"};
          msg.application = "application";
          msg.logger = "logger";
          msg.requestUri = "http://www.google.de";
          std::cout << msg.toJson() << std::endl;
          ws->send(msg.toJson());
    };
  
    /**
     * Writes the message to the book.
     */
    void Write(const Message& input) override {
      ws::Message msg{input.Content(), 4, input.Content()};
      msg.application = "application";
      msg.logger = "logger";
      msg.requestUri = "/email";
      std::cout << "write " << msg.toJson() << std::endl;
      ws->send(msg.toJson());
      };

    /**
     * Individual logbook users are identified by ship-names.
     */
    const logbook_name_t LogbookName() override {
      return name;
    };
};

websocket::websocket(std::shared_ptr<BookShelf> shelf): bookShelf{shelf}, httpListener{uWS::App()},
  rootDir{findCwd()},
  indexPage{fetchIndexPage(rootDir + "/public/Index.html")}
{
  this->httpListener.get("/", [this](auto *res, auto *req) {
    res->end(this->indexPage);
    });
    
  this->httpListener.get("/public/*", [this](auto *res, auto *req) {
    std::string path = this->rootDir + static_cast<std::string>(req->getUrl());
      std::cout << "receiving on port 55155 from " << this->rootDir << std::endl;
      std::ifstream ifs(path, std::ifstream::in);
      std::string content( (std::istreambuf_iterator<char>(ifs) ),
                          (std::istreambuf_iterator<char>()    ) );
    res->end(content);
    });
    
    this->httpListener.ws<uWS::WebSocketData>("/data", {
    /* Settings */
    .compression = uWS::DEDICATED_COMPRESSOR,
    .maxPayloadLength = 16 * 1024,
    .idleTimeout = 120,
        .open = [this](auto *ws, auto *req) {
          this->bookShelf->add(
            std::make_unique<middleware>(ws)
          );
        },
        .message = [](auto *ws, std::string_view message, uWS::OpCode opCode) {
          ws->send(message, opCode);
        },
        .drain = [](auto *ws) {
          std::cout << "drain" << std::endl;
        },
        .ping = [](auto *ws) {
          std::cout << "ping" << std::endl;
        },
        .pong = [](auto *ws) {
          std::cout << "pong" << std::endl;
        },
      .close = [](auto *ws, int code, std::string_view message) {
          std::cout << "close" << message << std::endl;
      }
    });
}

websocket::~websocket()
{
      std::cout << "stop listening on port 55155" << std::endl;
}

void websocket::run(int port)
{
  this->httpListener.listen(port, [&port](auto *token) {
      std::cout << "listening on port " << port << std::endl;
      }).run();
}

} // namespace logbook
