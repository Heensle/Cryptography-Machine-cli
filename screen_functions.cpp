#include <iostream>

using std::cout;

namespace ScreenFunctions {
  void clear_screen() {
    cout << "\033[H\033[2J\033[3J";
  }
}