#include "books/websocket/message.hpp"

#include <string>
#include <memory>
#include <gtest/gtest.h>

#include "mocks.h"

using WsMessage = logbook::ws::Message;
using std::string;

TEST(WsMessageTest, to_json) {
  WsMessage msg{"some content", 4, "context"};
  msg.requestId = "test";
  msg.requestUri = "/data";
  msg.logger = "PHP-Logger";
  msg.application = "some nasty PHP-App";
  
  EXPECT_EQ(
    string{"{\"message\":\"some content\",\"context\":\"context\",\"severity\":4,\"logger\":\"PHP-Logger\",\"application\":\"some nasty PHP-App\",\"request_uri\":\"/data\",\"request_id\":\"test\"}"},
    msg.toJson()
  ) << "test serializing";
}
