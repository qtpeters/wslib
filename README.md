
Playing around with making a websocket library

This should work:
cd test
g++ \
   -I /boost/1.55.0 \ # Point to where boost was installed
   -L /boost/1.55.0/bin.v2/libs/system/build/darwin-4.2.1/release/link-static/threading-multi \ # After building boost, here is where the system.o file is.
   -lboost_system \ # Tell the linker to include the boost_system library
   server_connect.cpp \ # Here is the source file to compile
   -o server_connect # The output file
