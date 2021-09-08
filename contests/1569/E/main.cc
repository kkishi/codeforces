#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(k, a, h);
  V<mint> ap(100);
  ap[0] = 1;
  rep(i, sz(ap) - 1) ap[i + 1] = ap[i] * a;
  rep(winner_is_in_right, 2) {
    VV<mint> vv(2);
    V<map<mint, V<int>>> m(2);
    rep(is_right, 2) {
      // There are 2^(k-1) players in this half.
      int N = 1 << (k - 1);
      // There are N-1 games to be played.
      rep(mask, 1 << (N - 1)) {
        V<int> idx(N);
        rep(i, N) idx[i] = i;
        V<int> v(N);
        int played_games = 0;
        rep(round, k - 1) {
          int games = 1 << (k - 2 - round);
          V<int> nidx(games);
          rep(j, games) {
            int w = idx[j * 2], l = idx[j * 2 + 1];
            if (hasbit(mask, played_games + j)) swap(w, l);
            v[l] = 1 + (1 << (k - 1 - round));
            nidx[j] = w;
          }
          swap(idx, nidx);
          played_games += games;
        }
        v[idx[0]] = (is_right == winner_is_in_right) ? 1 : 2;
        mint sum = 0;
        rep(i, 1 << (k - 1)) {
          int I = i + 1;
          if (is_right) I += (1 << (k - 1));
          sum += I * ap[v[i]];
        }
        vv[is_right].pb(sum);
        m[is_right][sum] = v;
      }
      sort(all(vv[is_right]));
    }
    rep(i, sz(vv[0])) {
      mint x = h - vv[0][i];
      auto it = lower_bound(all(vv[1]), x);
      if (it != vv[1].end() && *it == x) {
        V<int> ans;
        each(e, m[0][vv[0][i]]) ans.pb(e);
        each(e, m[1][x]) ans.pb(e);
        {
          mint sum = 0;
          rep(i, 1 << k) sum += (i + 1) * ap[ans[i]];
          assert(sum == h);
        }
        wt(ans);
        return;
      }
    }
  }
  wt(-1);
}
