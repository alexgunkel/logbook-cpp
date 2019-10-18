#include "bridge/portauthority.hpp"

#include <gtest/gtest.h>

using namespace logbook;


TEST(PortAuthorityTest, test_basic) {
  PortAuthority auth;
  
  auto name = auth.NewName();
  EXPECT_EQ("MSS Hope", name) << "first name";
  EXPECT_EQ("Titanic", auth.NewName()) << "second name";
  auth.release(name);
  EXPECT_EQ("MSS Hope", auth.NewName()) << "first name freed again";
  EXPECT_EQ("Sloop Revenge", auth.NewName()) << "third name";
  }
  