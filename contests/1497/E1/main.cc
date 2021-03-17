#include <bits/stdc++.h>

#include "codeforces.h"

class Sieve {
 public:
  Sieve(i64 n) : v_(n + 1) {
    iota(all(v_), 0);
    for (i32 i = 2; i * i <= n; ++i) {
      if (v_[i] == i) {
        for (i32 j = i * i; j <= n; j += i) {
          v_[j] = i;
        }
      }
    }
  }
  map<int, int> Factors(int n) {
    map<int, int> m;
    while (n > 1) {
      ++m[v_[n]];
      n /= v_[n];
    }
    return m;
  }

 private:
  V<i32> v_;
};

Sieve sieve(10000000);

void Solve() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  set<int> st;
  each(e, a) {
    int x = 1;
    each(k, v, sieve.Factors(e)) if (!even(v)) x *= k;
    if (st.count(x)) {
      st.clear();
    }
    if (st.empty()) {
      ++ans;
    }
    st.insert(x);
  }
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
