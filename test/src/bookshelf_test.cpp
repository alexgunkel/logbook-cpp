
#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "bridge/bridge.hpp"
#include "mocks.h"

using namespace logbook;
using testing::_;
using testing::Return;
using testing::AtLeast;
using testing::AtMost;

TEST(bookshelftest, testcreate) {
    BookShelf shelf{12};
    auto bookOfHope = std::make_unique<MockBook>();
    auto titanic = std::make_unique<MockBook>();

    boost::uuids::random_generator gen;
    auto uuidOne = gen();
    auto uuidTwo = gen();

    EXPECT_CALL(*bookOfHope, Write(_)).Times(AtLeast(1));
    EXPECT_CALL(*bookOfHope, LogbookName()).WillRepeatedly(Return(uuidOne));
    EXPECT_CALL(*titanic, Write(_)).Times(AtMost(0));
    EXPECT_CALL(*titanic, LogbookName()).WillRepeatedly(Return(uuidTwo));
    
    shelf.add(std::move(bookOfHope));
    shelf.add(std::move(titanic));
    shelf.findByShipName(uuidTwo).Write(Message{"test message", uuidTwo, "test"});
}
