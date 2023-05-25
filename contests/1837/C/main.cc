#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  strings(s);
  Fix([&](auto rec, int l, int r, bool flipped) -> void {
    auto flip = [&](int i) {
      int offset = i - l;
      return r - 1 - offset;
    };
    auto get = [&](int i) -> char& {
      if (!flipped) {
        return s[i];
      } else {
        return s[flip(i)];
      }
    };
    auto set = [&](int i, char c) {
      if (get(i) == '?') get(i) = c;
    };
    int one = -1;
    rep(i, l, r) {
      if (get(i) == '1') {
        one = i;
        break;
      }
    }
    int zero = -1;
    rrep(i, l, r) {
      if (get(i) == '0') {
        zero = i;
        break;
      }
    }
    if (one != -1 && zero != -1) {
      if (one > zero) {
        rep(i, l, one) set(i, '0');
        rep(i, one, r) set(i, '1');
        return;
      }
      rep(i, l, one) set(i, '0');
      rep(i, zero, r) set(i, '1');
      if (flipped) {
        rec(flip(zero) + 1, flip(one), !flipped);
      } else {
        rec(one + 1, zero, !flipped);
      }
    } else if (one != -1) {
      rep(i, l, r) set(i, '1');
    } else {
      rep(i, l, r) set(i, '0');
    }
  })(0, sz(s), false);
  wt(s);
}
