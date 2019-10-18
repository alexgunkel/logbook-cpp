
#include <memory>
#include <gtest/gtest.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "bridge/bridge.hpp"
#include "mocks.h"

using namespace logbook;

using testing::_;
using testing::Return;

TEST(CaptainsDesk, testdispatch)
{
  boost::uuids::random_generator gen;
  boost::uuids::uuid logbookName = gen();
  auto book = std::make_unique<MockBook>();
  
  EXPECT_CALL(*book, LogbookName()).WillRepeatedly(Return(logbookName));
  EXPECT_CALL(*book, Write(_));
  
  auto shelf = std::make_shared<BookShelf>(3);
  shelf->add(std::move(book));
  
  CaptainsDesk desk{shelf};
  
  Message msg{"SOS", logbookName, "journey"};
  desk.receive(msg);
}