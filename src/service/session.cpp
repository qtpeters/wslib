#include "session.h"

wslib::service::session::session( boost::asio::io_service& io_service ) 
   : socket_( io_service ) {}

tcp::socket& wslib::service::session::socket() {
   return socket_;
}

void wslib::service::session::start() {
   socket_.async_read_some( 
      boost::asio::buffer( data_, max_length ),
      boost::bind( 
         &session::handle_read, this,
         boost::asio::placeholders::error,
         boost::asio::placeholders::bytes_transferred 
      ) 
   );
}

void wslib::service::session::handle_read(
   const boost::system::error_code& error,
   size_t bytes_transferred ) {

   if ( ! error ) {
      boost::asio::async_write( socket_,
      boost::asio::buffer( data_, bytes_transferred ),
      boost::bind( &session::handle_write, this,
      boost::asio::placeholders::error));
   } else {
      delete this;
   }
}

void wslib::service::session::handle_write( const boost::system::error_code& error ) {
   if ( ! error ) {
      socket_.async_read_some( boost::asio::buffer( data_, max_length ),
      boost::bind(&session::handle_read, this,
      boost::asio::placeholders::error,
      boost::asio::placeholders::bytes_transferred));
   } else {
      delete this;
   }
}
