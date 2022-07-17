#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  rep(n - 1) {
    map<int, int> nmp;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      if (int x = it->second; x > 1) {
        nmp[0] += x - 1;
      }
      if (auto jt = next(it); jt != mp.end()) {
        ++nmp[jt->first - it->first];
      }
    }
    swap(mp, nmp);
  }
  wt(mp.begin()->first);
}
