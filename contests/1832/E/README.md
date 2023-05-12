# 典型要素

* 二項係数を分解して畳み込み(要素数が大きい場合)

# 解法

式変形をすると[Maximum Diameter](https://atcoder.jp/contests/abc290/tasks/abc290_f)と同様に畳み込める。ただし畳み込みの結果の数列の要素数が最大で $2 \times 10^7$ となってACLのconvolutionを使うことができない( $998244353 = 2^{23} \times 119 + 1$ なので、 $2^{23} = 8388608$ 程度までが限界。assertで落ちないが正しくない結果が返る)。[Convolution (Large)](https://judge.yosupo.jp/problem/convolution_mod_large)への[suisenさんの高速な提出](https://judge.yosupo.jp/submission/87828)を借りると通すことができた。
