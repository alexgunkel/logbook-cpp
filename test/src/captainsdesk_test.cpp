
#include <memory>
#include <gtest/gtest.h>

#include "bridge.hpp"
#include "mocks.h"

using namespace logbook;

using testing::_;
using testing::Return;

TEST(CaptainsDesk, testdispatch)
{
  MockCrowsNest nest;
  EXPECT_CALL(nest, attachReceiver(testing::_));
  
  auto book = std::make_unique<MockBook>();
  EXPECT_CALL(*book, ShipName()).WillRepeatedly(Return("MSS Hope"));
  EXPECT_CALL(*book, Write(_));
  
  auto shelf = std::make_shared<BookShelf>(3);
  shelf->add(std::move(book));
  
  CaptainsDesk desk{shelf};
  
  Message msg{"SOS", "MSS Hope", "journey"};
  desk.receive(msg);
}