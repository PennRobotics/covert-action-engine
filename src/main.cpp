#include "covert.h"

#ifdef PLACEHOLDERS
#include <iostream>
#endif

int main( int argc, char* argv[] ) {
#ifdef PLACEHOLDERS
  std::cout << "Image placeholders are enabled.\n";
#endif

  return do_covert();
}
