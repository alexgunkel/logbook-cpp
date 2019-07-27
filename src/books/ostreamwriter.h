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

#ifndef LOGBOOK_BOOKS_OSTREAMWRITER_H
#define LOGBOOK_BOOKS_OSTREAMWRITER_H

#include <iostream>
#include <bridge/bridge.hpp>

namespace logbook {
    
/**
 * @todo write docs
 */
class OstreamWriter: public BookInterface
{
public:
    /**
     * Default constructor
     */
    explicit OstreamWriter(ship_name_t title): OstreamWriter{title, std::cout} {};
    
    OstreamWriter(ship_name_t t, ::std::ostream& o): out{o}, title{t} {};

    /**
     * Copy Constructor
     *
     * @param other TODO
     */
    OstreamWriter(const OstreamWriter& other);

    /**
     * Destructor
     */
    ~OstreamWriter() override {};
    
    void Write(const Message& msg) override {
      out << msg.Content() << std::endl;
    };
    
    const ship_name_t ShipName() override {
        return title;
    };

private:
    std::ostream& out;
    const ship_name_t title;
    const char* timeFormat{"%Y-%m-%d %H:%M:%S %Z"};
};

}  // namespace logbook

#endif // LOGBOOK_BOOKS_OSTREAMWRITER_H
