# 解法

半分全列挙をする。片方の山には最大で16人おり、可能なトーナメントの結果は2^15通り(15回ゲームが行われるので）。

# 補足

トーナメントの結果の列挙は、全ゲームの結果をbit全探索し、シミュレーションするとよい。
