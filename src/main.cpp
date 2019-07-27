#include <iostream>
#include "LogbookConfig.h"
#include "logbookserver.hpp"

int main() {
  logbook::LogbookServer application;
  application.Run();
}
