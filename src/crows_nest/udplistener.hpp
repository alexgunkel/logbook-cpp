#ifndef UDPLISTENER_HPP
#define UDPLISTENER_HPP

#include <memory>

#include <boost/asio.hpp>

#include "bridge/bridge.hpp"

using namespace boost::asio::ip;

using std::shared_ptr;
using std::unique_ptr;
using boost::asio::io_context;

namespace logbook
{

class UdpListener: public CrowsNestInterface
{
public:
  UdpListener() {
    io_context io{1};
    so = std::make_unique<udp::socket>(io, udp::endpoint{udp::v4(), 55155});
  };
  ~UdpListener();

  UdpListener(const UdpListener& rhs) = delete;
  UdpListener& operator=(const UdpListener& rhs) = delete;

  void attachReceiver(shared_ptr<ReceiverInterface> receiver) override {
    this->receiver = receiver;
  };
  
  void Run() {
        for (;;) {
            char data[1024];
            udp::endpoint sender_endpoint;
            size_t received = so->receive_from(boost::asio::buffer(data, 1024), sender_endpoint);
            
            std::string got{data, received};
            receiver->receive(Message{got, "MSS Hope", "street of Gibraltar"});
        }
    };
  
  private:
  shared_ptr<ReceiverInterface> receiver;
  
  unique_ptr<udp::endpoint> ep;
  unique_ptr<udp::socket> so;
};

}

#endif // UDPLISTENER_HPP
