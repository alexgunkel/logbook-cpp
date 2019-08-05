/*
 * Copyright 2019 <copyright holder> <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include "bridge.hpp"

using namespace logbook;

class MessageTest : public ::testing::Test {
protected:
    Message m_1{"SOS", "MSS Hope", "street of gibraltar"};
};

TEST_F(MessageTest, getters) {
  EXPECT_STREQ( "MSS Hope", m_1.ShipName()) << "test ship-name";
  EXPECT_STREQ( "street of gibraltar", m_1.Journey()) << "test ship-name";
  EXPECT_EQ( "SOS", m_1.Content()) << "test ship-name";
}
