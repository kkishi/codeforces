#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(k);
  int n = 1 << k;
  V<int> seed(n);
  cin >> seed;
  auto kind = [](int i) {
    if (i == 1) {
      return 0;
    } else {
      return 64 - __builtin_clzll(i - 1);
    }
  };
  map<int, int> seen;
  each(e, seed) if (e != -1)++ seen[kind(e)];
  mint ans = 1;
  rep(i, k) {
    int curr_kind = k - i;
    int a = 0;
    int b = (1 << (curr_kind - 1)) - seen[curr_kind];
    V<int> nseed(sz(seed) / 2);
    rep(j, 1 << (k - 1 - i)) {
      int l = j * 2;
      int r = l + 1;
      if (seed[l] == -1 && seed[r] == -1) {
        ++a;
        nseed[j] = -1;
      } else {
        bool L = kind(seed[l]) == curr_kind;
        bool R = kind(seed[r]) == curr_kind;
        if (seed[l] == -1) {
          nseed[j] = R ? -1 : seed[r];
        } else if (seed[r] == -1) {
          nseed[j] = L ? -1 : seed[l];
        } else {
          if ((L && R) || (!L && !R)) {
            wt(0);
            return;
          }
          nseed[j] = seed[L ? r : l];
        }
      }
    }
    ans *= mint(2).Pow(a) * mint::Fact(b);
    swap(seed, nseed);
  }
  wt(ans);
}
