
#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "bridge.hpp"
#include "mocks.h"

using namespace logbook;

TEST(bookshelftest, testcreate) {
    {
    BookShelf shelf{12};
    auto bookOfHope = std::make_unique<MockBook>();
    auto titanic = std::make_unique<MockBook>();

    EXPECT_CALL(*bookOfHope, Write(testing::_)).Times(testing::AtLeast(1));
    EXPECT_CALL(*bookOfHope, ShipName()).WillRepeatedly(testing::Return("MSS Hope"));
    
    EXPECT_CALL(*titanic, Write(testing::_)).Times(testing::AtMost(0));
    EXPECT_CALL(*titanic, ShipName()).WillRepeatedly(testing::Return("Titanic"));

    shelf.add(std::move(bookOfHope));
    shelf.add(std::move(titanic));
    shelf.findByShipName("MSS Hope").Write(Message{"hello world", "MSS Hope", "Northwest Passage"});
    }

    ASSERT_FALSE( false );
}
