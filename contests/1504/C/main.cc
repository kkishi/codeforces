#include <bits/stdc++.h>

#include "codeforces_multi.h"

pair<bool, pair<string, string>> Solve() {
  ints(n);
  strings(s);
  int one = 0, zero = 0;
  each(e, s)(e == '1' ? one : zero)++;
  pair<string, string> ret;
  if (!even(one) || !even(zero)) return {false, ret};
  string a, b;
  int A = 0, B = 0;
  int seen_one = 0;
  rep(i, n) {
    if (s[i] == '1') {
      ++seen_one;
      if (seen_one <= one / 2) {
        ++A, ++B;
        a += '(';
        b += '(';
      } else {
        --A, --B;
        a += ')';
        b += ')';
      }
    } else {
      if (A == B) {
        ++A, --B;
        a += '(';
        b += ')';
      } else {
        assert(A == B + 2);
        --A, ++B;
        a += ')';
        b += '(';
      }
    }
    if (A < 0 || B < 0) return {false, ret};
  }
  return {true, {a, b}};
}

void Main() {
  auto [ok, res] = Solve();
  wt(ok);
  if (ok) {
    wt(res.first);
    wt(res.second);
  }
}
