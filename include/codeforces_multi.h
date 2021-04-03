#include <iomanip>

#include "macros.h"

void Main();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  yes_str = "YES", no_str = "NO";

  int t;
  std::cin >> t;
  for (int i = 1; i <= t; ++i) {
#ifdef DEBUG
    std::cerr << "Test case " << i << ":\n";
#endif
    Main();
  }
  return 0;
}

using namespace std;

#define int i64
