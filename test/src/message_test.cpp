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

#include <boost/uuid/uuid_io.hpp>

#include "bridge/message.hpp"

using namespace logbook;

TEST(MessageFactoryTest, TestFromStringBuffer) {
  char input[] = "882b3240-d74e-4f18-b68c-1667c645194b: 3 1566749699 [Test - 8bff0b0fd50db220f8a986bfa892932d - TestLogger] Test log entry";

  try
  {
    auto msg = Message::fromBufferString(input, 120);

    EXPECT_EQ("882b3240-d74e-4f18-b68c-1667c645194b", to_string(msg->LogbookName())) << "correct logbookname";
    EXPECT_EQ(1566749699, int(msg->Created())) << "time detection";
    EXPECT_EQ(3, msg->Severity()) << "test severity";
    EXPECT_EQ("Test log entry", msg->Content()) << "correct message-content";
  }
  catch(const std::runtime_error& e)
  {
    FAIL() << e.what();
  } 
}
