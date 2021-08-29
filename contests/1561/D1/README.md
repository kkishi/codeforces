# 典型要素

* 平方分割
* floor(x/y)の商とその個数を√xで求める

# 解説

[公式](https://codeforces.com/blog/entry/94216)

# 解法

`f(i) = n番目のcellから出発してi番目のcellにたどり着く方法の数`を考えると、自明なO(N^2)のDPで計算できる。これを高速化する。

Subtractionは累積和を用いて高速化できる。  
Florred divisionは、正整数x, z (z <= x) に対して、floor(x / z)はO(√(x))通りの値しかとらず、またそれを高速に求められることを利用する。以下これを説明する。  
z <= √(x) であるようなzについては、愚直にfloor(x / z)を求めればよい。  
z > √(x) であるようなzについて考える。あるcについて、`c=floor(x/z)`となるようなzの個数を数えたい。   
floorの定義から`c <= x/z < c+1`  
⇔ `x/(c+1) < z <= x/c`  
⇔ `floor(x/(c+1)) + 1 <= z <= floor(x/c)`  
つまり、そのようなzは`floor(x/c) - floor(x/(c+1))`個ある。
