#include <iostream>

int main() {
#if defined(NDEBUG)
  std::cout << "Release build" << std::endl;
#else
  std::cout << "Debug build" << std::endl;
#endif
  std::cout << "sizeof(int, long, long long): ";
  std::cout << sizeof(int) << " ";
  std::cout << sizeof(long) << " ";
  std::cout << "sale je kralj" << std::endl;
  std::cout << "pavle je car!!" << std::endl;
  std::cout << "Dual CI test." << std::endl;
  std::cout << sizeof(long long) << std::endl;
  // Kick off travis.
  // Add
}
