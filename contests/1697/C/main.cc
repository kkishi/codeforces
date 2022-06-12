#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([] {
    ints(n);
    strings(s, t);
    multiset<char> S(all(s)), T(all(t));
    if (S != T) {
      return false;
    }
    int i = 0;
    while (i < n) {
      if (t[i] == s[i]) {
        ++i;
        continue;
      }
      if (t[i] == 'a') {
        return false;
      } else if (t[i] == 'b') {
        if (s[i] != 'a') return false;
        int j = i;
        while (j < n && s[j] != 'c' && t[j] != 'c') ++j;
        dbg(i, j, s.substr(i, j - i), t.substr(i, j - i));
        V<int> S, T;
        rep(k, i, j) {
          if (s[k] == 'b') S.pb(k);
          if (t[k] == 'b') T.pb(k);
        }
        if (sz(S) != sz(T)) return false;
        rep(i, sz(S)) if (S[i] < T[i]) return false;
        i = j;
      } else if (t[i] == 'c') {
        if (s[i] != 'b') return false;
        int j = i;
        while (j < n && s[j] != 'a' && t[j] != 'a') ++j;
        dbg(i, j, s.substr(i, j - i), t.substr(i, j - i));
        V<int> S, T;
        rep(k, i, j) {
          if (s[k] == 'c') S.pb(k);
          if (t[k] == 'c') T.pb(k);
        }
        if (sz(S) != sz(T)) return false;
        rep(i, sz(S)) if (S[i] < T[i]) return false;
        i = j;
      }
    }
    return true;
  }());
}
