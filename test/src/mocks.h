#ifndef LOGBOOK_TEST_MOCKS_H_
#define LOGBOOK_TEST_MOCKS_H_

#include <gmock/gmock.h>
#include "bridge/bridge.hpp"

class MockBook : public logbook::BookInterface {
public:
  MOCK_METHOD(void, Write, (const logbook::Message&), (override));
  MOCK_METHOD(const logbook::logbook_name_t, LogbookName, (), (override));
};

class MockCrowsNest: public logbook::CrowsNestInterface {
public:
  MOCK_METHOD(void, attachReceiver, (std::shared_ptr<logbook::ReceiverInterface> receiver), (override));
  MOCK_METHOD(void, Run, (), (override));
};

#endif
