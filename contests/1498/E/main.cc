#include <bits/stdc++.h>

#include "macros.h"

void Main();

int main() {
  Main();
  return 0;
}

using namespace std;

void Main() {
  ints(n);
  V<int> k(n);
  cin >> k;
  V<pair<int, int>> l(n);
  rep(i, n) l[i] = {k[i], i + 1};
  sort(all(l), greater{});
  int i = 0;
  int ng = n;
  while (i < n) {
    if (l[i].first != ng) break;
    ++i;
    --ng;
  }
  while (i < n) {
    auto [KI, I] = l[i];
    int j = n - 1;
    while (j > i) {
      auto [KJ, J] = l[j];
      cout << "? " << I << " " << J << endl;
      cout.flush();
      string res;
      cin >> res;
      if (res == "Yes") {
        cout << "! " << I << " " << J << endl;
        cout.flush();
        return;
      }
      --j;
    }
    ++i;
  }
  cout << "! 0 0" << endl;
  cout.flush();
}
