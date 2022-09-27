#include "covert.h"

#if defined(PLACEHOLDERS)||defined(NO_SDL)
#include <iostream>
#endif

int main( int argc, char* argv[] ) {
#ifdef PLACEHOLDERS
#pragma message("DEBUG: use image placeholders")
  std::cout << "Image placeholders are enabled.\n";
#endif
#ifdef NO_SDL
#pragma message("DEBUG: disable SDL")
  std::cout << "SDL functions are bypassed.\n";
#endif

  return do_covert();
}
