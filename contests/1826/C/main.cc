#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "sieve.h"

Sieve sieve(10000000);

bool Solve() {
  ints(n, m);
  if (n == 1 || m == 1) return true;
  if (m >= n) return false;
  return sieve.Factors(n).begin()->first > m;
}

void Main() { wt(Solve()); }
