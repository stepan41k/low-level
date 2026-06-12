#include <iostream>

using namespace std;

template <typename T> T myMax(T a, T b) { return (a > b) ? a : b; }

int main() {
  std::cout << myMax(3, 7) << std::endl;     // int
  std::cout << myMax(3.1, 7.8) << std::endl; // double
  std::cout << myMax(std::string("hello"), std::string("world"))
            << std::endl; // string
  return 0;
}
