#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

class Sieve {
 public:
  Sieve(int64_t n) : v_(n + 1) {
    for (int32_t i = 1; i <= n; ++i) {
      for (int32_t j = i; j <= n; j += i) {
        ++v_[j];
      }
    }
  }
  int Factors(int64_t n) { return v_[n]; }

 private:
  std::vector<int32_t> v_;
};

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  Sieve s(1000100);
  V<int> v;
  rep(i, 1, 1000100) v.pb(s.Factors(i + 1) - s.Factors(i));
  mint ans = 1;
  rep(i, 1, n) {
    ans *= 2;
    ans += v[i - 1];
  }
  wt(ans);
}
