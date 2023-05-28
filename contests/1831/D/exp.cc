#include <bits/stdc++.h>

#include "codeforces.h"

int Solve(const V<int>& a, const V<int>& b) {
  int n = sz(a);
  int N = n * 2;
  int M = sqrt(N);
  map<int, map<int, int>> mp;
  rep(i, n) mp[a[i]][b[i]]++;
  VV<pair<int, int>> v(n + 1);
  each(a, mp, mp) each(b, cnt, mp) v[a].eb(b, cnt);

  auto count = [&](int ai, int aj) -> int {
    int A = ai * aj;
    const auto& bi = v[ai];
    const auto& bj = v[aj];
    if (bi.empty() || bj.empty()) return 0;
    auto it = bi.rbegin();
    int ret = 0;
    each(bj, cntj, bj) {
      while (it != bi.rend() && it->first + bj > A) {
        ++it;
      }
      if (it != bi.rend() && it->first + bj == A) {
        ret += it->second * cntj;
      }
    }
    return ret;
  };

  int sum = 0;
  rep(i, 1, M + 1) rep(j, 1, M + 1) sum += count(i, j);

  int self = 0;
  rep(i, n) if (a[i] <= M && a[i] * a[i] == b[i] + b[i])++ self;

  int small = (sum - self) / 2;

  int big = 0;
  rep(i, M + 1, n + 1) for (int j = 1; i * j <= N; ++j) big += count(i, j);

  return small + big;
}

int Naive(const V<int>& a, const V<int>& b) {
  int n = sz(a);
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) {
    if (a[i] * a[j] == b[i] + b[j]) ++ans;
  }
  return ans;
}

void Main() {
  rep(n, 2, 8) {
    V<int> a(n), b(n);
    Fix([&](auto rec, int depth) -> void {
      if (depth == n) {
        assert(Solve(a, b) == Naive(a, b));
      } else {
        rep(i, 1, n + 1) rep(j, 1, n + 1) {
          a[depth] = i;
          b[depth] = j;
          rec(depth + 1);
        }
      }
    })(0);
    dbg(n);
  }
}
