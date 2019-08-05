#include "bridge.hpp"

#include <memory>
#include <iostream>
#include <stdexcept>

using std::unique_ptr;
using std::forward;

namespace logbook {

BookShelf::BookShelf(): BookShelf{100} {};

BookShelf::BookShelf(size_t capacity): maxNumberOfBooks{capacity} {};

BookShelf::~BookShelf() {};

void BookShelf::add(unique_ptr<BookInterface> bookPtr)
{
    listOfBooks.push_back(forward<unique_ptr<BookInterface>>(bookPtr));
}

BookInterface & BookShelf::findByShipName(logbook::ship_name_t ship) const
{
    for (auto it = listOfBooks.begin(); it != listOfBooks.end(); ++it)  {
        return **it;
    }
    
    throw std::out_of_range{"no log-book found for ship-name"};
}

} // namespace logbook
