#include "main.h"

Main::Main() {
   this->msg = "Test Message";
}

void Main::printMsg() {
   std::cout << this->msg << "\n";
}

