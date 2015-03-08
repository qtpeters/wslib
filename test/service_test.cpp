#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "../src/service/server.h"
#include "../src/service/session.h"

using boost::asio::ip::tcp;

int main( int argc, char* argv[] ) {
   
   try {

      if ( argc != 2)  {
         std::cerr << "Usage: server_connect <port>\n";
         return 1;
      }

      boost::asio::io_service io_service;

      using namespace std;
      wslib::service::server s(io_service, atoi(argv[1]));
      io_service.run();

   } catch ( std::exception& e ) {
      std::cerr << "Exception: " << e.what() << "\n";
   }

   return 0;
}
