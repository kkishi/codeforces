#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> b(n);
  cin >> b;
  set<int> st;
  st.insert(b[0]);
  auto it = st.begin();
  rep(i, 1, n) {
    if (b[i] == *it) {
      continue;
    } else if (b[i] < *it) {
      if (it == st.begin()) {
        st.insert(b[i]);
        it = st.begin();
      } else {
        --it;
        if (*it > b[i]) {
          wt("NO");
          return;
        }
        if (*it != b[i]) {
          st.insert(b[i]);
          it = st.find(b[i]);
        }
      }
    } else {
      if (next(it) == st.end()) {
        st.insert(b[i]);
        it = prev(st.end());
      } else {
        ++it;
        if (*it < b[i]) {
          wt("NO");
          return;
        }
        if (*it != b[i]) {
          st.insert(b[i]);
          it = st.find(b[i]);
        }
      }
    }
    dbg(st);
  }
  wt("YES");
}
