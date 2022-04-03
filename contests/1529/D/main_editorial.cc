#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

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

void Main() {
  ints(n);
  V<mint> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  V<mint> sdp(n + 2);
  sdp[1] = 1;
  sdp[2] = 2;
  Sieve s(1e6 + 1);
  rep(i, 2, n + 1) {
    dp[i] += 1;
    dp[i] += sdp[i];
    dp[i] += s.Factors(i) - 2;  // rep(j, 2, i) if (i % j == 0) ++dp[i];
    sdp[i + 1] = sdp[i] + dp[i];
  }
  wt(dp[n]);
}
