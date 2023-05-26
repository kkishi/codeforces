#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(k);
  int n = 1 << k;
  V<int> seed(n);
  cin >> seed;

  auto kind = [](int i) { return i == 1 ? 0 : (64 - __builtin_clzll(i - 1)); };
  V<int> remaining(k + 1);
  rep(kind, 1, k + 1) remaining[kind] = (1 << (kind - 1));
  each(e, seed) if (e != -1) {
    --remaining[kind(e)];
    e = kind(e);  // Knowing the kind is sufficient.
  }

  mint ans = 1;
  rrep(curr, 1, k + 1) {
    int a = 0;
    V<int> nseed(sz(seed) / 2);
    rep(j, 1 << (curr - 1)) {
      int L = seed[j * 2];
      int R = seed[j * 2 + 1];
      int cnt_curr = (L == curr) + (R == curr);
      bool L_less = (L != -1 && L < curr);
      bool R_less = (R != -1 && R < curr);
      int cnt_less = L_less + R_less;
      if (cnt_curr > 1 || cnt_less > 1) {
        wt(0);
        return;
      }
      if (L == -1 && R == -1) ++a;
      if (L_less) {
        nseed[j] = L;
      } else if (R_less) {
        nseed[j] = R;
      } else {
        assert(L == -1 || R == -1);
        nseed[j] = -1;
      }
    }
    ans *= mint(2).Pow(a) * mint::Fact(remaining[curr]);
    swap(seed, nseed);
  }
  wt(ans);
}
