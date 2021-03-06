#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n & 1) {
    bool has_odd = false;
    for (int i = 0; i < n; i += 2) if ((s[i] - '0') & 1) has_odd = true;
    cout << (has_odd ? 1 : 2) << endl;
  } else {
    bool has_even = false;
    for (int i = 1; i < n; i += 2) if ((s[i] - '0') % 2 == 0) has_even = true;
    cout << (has_even ? 2 : 1) << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
