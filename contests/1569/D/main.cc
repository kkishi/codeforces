#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "compress.h"

void Main() {
  ints(n, m, k);
  V<int> x(n), y(m);
  cin >> x >> y;
  V<pair<int, int>> p(k);
  cin >> p;

  int X, Y;
  {
    V<int> ax = x, ay = y;
    each(X, Y, p) {
      ax.pb(X);
      ay.pb(Y);
    }
    V<int> cx = Compress(ax), cy = Compress(ay);
    V<pair<int, int>> cp;
    each(x, y, p) cp.eb(Uncompress(cx, x), Uncompress(cy, y));
    V<int> nx;
    each(e, x) nx.pb(Uncompress(cx, e));
    V<int> ny;
    each(e, y) ny.pb(Uncompress(cy, e));
    x = nx;
    y = ny;
    p = cp;
    X = sz(cx) + 1;
    Y = sz(cy) + 1;
  }

  V<bool> hx(X), hy(Y);
  each(e, x) hx[e] = true;
  each(e, y) hy[e] = true;

  auto f = [](const V<int>& v, const V<bool>& w) {
    assert(sz(v) == sz(w));
    int sum = 0;
    int ret = 0;
    rep(i, sz(v)) {
      if (w[i]) {
        sum = 0;
      } else {
        ret += sum * v[i];
        ret += v[i] * (v[i] - 1) / 2;
        sum += v[i];
      }
    }
    return ret;
  };
  int ans = 0;
  {
    V<int> v(Y);
    each(x, y, p) {
      if (hx[x] && !hy[y]) {
        ++v[y];
      }
    }
    ans += f(v, hy);
  }
  {
    V<int> v(X);
    each(x, y, p) {
      if (!hx[x] && hy[y]) {
        ++v[x];
      }
    }
    ans += f(v, hx);
  }
  int extra = 0;
  auto g = [](const VV<int>& v, const V<bool>& w) {
    assert(sz(v) == sz(w));
    int ret = 0;
    map<int, int> m;
    rep(i, sz(w)) {
      if (w[i]) {
        each(_, v, m) ret += v * (v - 1) / 2;
        m.clear();
      } else {
        each(e, v[i])++ m[e];
      }
    }
    return ret;
  };
  {
    VV<int> v(Y);
    each(x, y, p) {
      if (hx[x] && !hy[y]) {
        v[y].pb(x);
      }
    }
    extra += g(v, hy);
  }
  {
    VV<int> v(X);
    each(x, y, p) {
      if (!hx[x] && hy[y]) {
        v[x].pb(y);
      }
    }
    extra += g(v, hx);
  }
  ans -= extra;
  wt(ans);
}
