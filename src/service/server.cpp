#include "server.h"

wslib::service::server::server( boost::asio::io_service& io_service, short port ) 
   : io_service_( io_service ),
   acceptor_( io_service, tcp::endpoint( tcp::v4(), port ) ) {
      session *new_session = new session( io_service_ );
      acceptor_.async_accept( 
         new_session->socket(),
         boost::bind( 
            &server::handle_accept, 
            this, new_session,
            boost::asio::placeholders::error 
         ) 
      );
}


void wslib::service::server::handle_accept( session* new_session,
   const boost::system::error_code& error ) {
   if ( ! error ) {
      new_session->start();
      new_session = new session( io_service_ );
      acceptor_.async_accept( new_session->socket(),
      boost::bind( &server::handle_accept, this, new_session,
      boost::asio::placeholders::error ) );
   } else {
      delete new_session;
   }
}
