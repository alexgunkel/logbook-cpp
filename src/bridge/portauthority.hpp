#ifndef PORTAUTHORITY_HPP
#define PORTAUTHORITY_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

namespace logbook
{

struct registryEntry {
  std::string shipname;
  bool isOccupied;
};
  
class PortAuthority
{
public:
  PortAuthority(const PortAuthority& rhs) = delete;
  PortAuthority& operator=(const PortAuthority& rhs) = delete;

  PortAuthority()
  {
  }
  ~PortAuthority()
  {
  }
  
  std::string NewName()
  {
    auto found = std::find_if(
      shipRegistry.begin(),
      shipRegistry.end(),
      [](registryEntry entry) -> bool {
        return !entry.isOccupied;
      }
    );
    
    if (found == shipRegistry.end()) {
      throw std::out_of_range{"no ship-name available"};
    }
    
    found->isOccupied = true;
    
    return found->shipname;
  }
  
  void release(std::string shipName) {
    auto found = std::find_if(
      shipRegistry.begin(),
      shipRegistry.end(),
      [&shipName](registryEntry entry) -> bool {
        return shipName == entry.shipname;
      }
    );
    
    found->isOccupied = false;
  }

  private:
  static std::vector<registryEntry> shipRegistry;
};

}

#endif // PORTAUTHORITY_HPP
