#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  if (n == 1) {
    wt(-1);
    return;
  }
  set<int> st;
  rep(i, n) st.insert(i + 1);
  V<int> ans;
  rep(i, n) {
    auto it = st.begin();
    if (*it == p[i]) ++it;
    if (it == st.end()) {
      ans.pb(*prev(it));
      swap(ans[n - 2], ans[n - 1]);
    } else {
      ans.pb(*it);
      st.erase(it);
    }
  }
  wt(ans);
}
