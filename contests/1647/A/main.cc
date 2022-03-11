#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  if (n % 3 == 2) {
    cout << 2;
    rep(n / 3) cout << 12;
  } else if (n % 3 == 1) {
    cout << 1;
    rep(n / 3) cout << 21;
  } else {
    rep(n / 3) cout << 21;
  }
  cout << endl;
}
