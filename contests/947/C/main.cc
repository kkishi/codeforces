#include <bits/stdc++.h>

#include "binary_trie.h"
#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n), p(n);
  cin >> a >> p;
  BinaryTrie t;
  rep(i, n) t.Insert(p[i]);
  V<int> ans;
  rep(i, n) {
    int x = t.MinElement(a[i]);
    t.Erase(x);
    ans.pb(a[i] ^ x);
  }
  wt(ans);
}
