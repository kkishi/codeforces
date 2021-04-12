#include <bits/stdc++.h>

#include "codeforces.h"

int cost(const string& s) {
  int ans = 0;
  rep(i, sz(s))
      rep(j, i + 1, sz(s) - 1) if (s[i] == s[j] && s[i + 1] == s[j + 1]) {
    ++ans;
  }
  return ans;
}

void Main() {
  ints(n, k);
  if (k == 1) {
    wt(string(n, 'a'));
    return;
  }
  string walk;
  auto ch = [](int i) { return (char)('a' + i); };
  rep(i, k) walk += string(2, (char)('a' + i));
  walk += 'a';
  set<pair<int, int>> seen;
  rep(i, 2, k) {
    if (gcd(i, k) != 1) continue;
    int curr = 0;
    rep(k) {
      rep(l, 2, k) if (gcd(l, k) != 1) {
        int next = (curr + l) % k;
        if (!seen.count({curr, next})) {
          int C = curr;
          do {
            int N = (C + l) % k;
            assert(!seen.count({C, N}));
            seen.insert({C, N});
            walk += ch(N);
            C = N;
          } while (C != curr);
        }
      }
      int next = (curr + i) % k;
      walk += ch(next);
      curr = next;
    }
    assert(curr == 0);
  }
  walk = walk.substr(0, sz(walk) - 1);
  dbg(walk);
  dbg(cost(walk));
  string ans;
  while (sz(ans) < n) ans += walk;
  ans = ans.substr(0, n);
  wt(ans);
  dbg(cost(ans));
}
