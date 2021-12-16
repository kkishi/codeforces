#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  strings(s, t);
  sort(all(s));
  if (t == "abc") {
    map<char, int> m;
    each(e, s)++ m[e];
    if (m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {
      sort(all(s), [](char a, char b) {
        if (set{a, b} == set{'b', 'c'}) return a > b;
        return a < b;
      });
    }
  }
  wt(s);
}
