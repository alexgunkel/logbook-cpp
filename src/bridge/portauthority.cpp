#include "portauthority.hpp"
#include <vector>

namespace logbook {
std::vector<registryEntry> PortAuthority::shipRegistry = {
  #include "shipNames.inc"
};

} // namespace logbook
