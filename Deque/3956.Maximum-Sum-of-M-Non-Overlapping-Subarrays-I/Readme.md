### 3956.Maximum-Sum-of-M-Non-Overlapping-Subarrays-I

题意整体看上去像个动态规划。我们令dp[k][i]表示前i个元素里选取k个subarray所能得到的sum最优解。那么对于第i个元素，有两种策略：
1. 不取。于是`dp[k][i]=dp[k][i-1]`
2. 取。我们需要考虑最后一个subarray的范围，假设长度为d，则我们需要在l<=d<=r的范围内找到最优解，故有`dp[k][i] = max{dp[k-1][i-d] + presum[i]-presum[i-d]}`.

我们在外层已经有两层循环控制变量k和i，如果再加一层循环遍历d，时间复杂度是不够用的。

我们发现，如果固定k和i，我们实际在一个新数组`dp[k-1][j]-presum[j]`里求一个窗口范围`j=[i-r,i-l]`里寻找最大值。随着i的变化，这个滑窗是sliding且定长的。我们已经知道，我们可以用deque求滑动窗口的最大值。这样对于i而言，其对应滑窗内最优解的计算，可以均摊到o(1).

代码框架大致是：
```
for (int k=1; k<=m; k++) {
  // 构造dq，里面存放 dp[k-1][j]-presum[j].
  for (int i=0; i<n; i++) {
      0. dp[k][i]在“不取”决策下，有初始解 dp[k][i-1].
      1. 将加入i-l处的元素加入dq，保持dq递减。
      2. 将i-r点及其之前的元素移出dq
      3. 当前dq的首元素就是区间[i-r,i-l]里的最大值。
      4. dq.front() + presum[i] 就是“取”决策下的最优解，更新dp[k][i].
  }
}


