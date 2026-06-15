### 3961.Maximize-Sum-of-Device-Ratings

很明显，无论把globalMin放到哪里，它所在的device的最终贡献就是globalMin。既然这个device的贡献是锁死的，那么我们就可以贪心地将其他device的最小值都扔到这个device（而不会对其产生任何影响），并且能提升自身的贡献值。

所以本题的关键就是思考该把globalMin扔到哪个device。

在不考虑globalMin归属的情况下，每个device的贡献值就是其SecondMin的元素值。此时再考虑globalMin所在的device，其本质就是将贡献值从SecondMin拉低到了globalMin。所以我们只要找全局最小的`SecondMin-globalMin`，从而减小该损失。

最终的答案就是：`sum(SecondMin) - min(SecondMin) + globalMin`.

特别注意，当n=1时需要特殊处理。
