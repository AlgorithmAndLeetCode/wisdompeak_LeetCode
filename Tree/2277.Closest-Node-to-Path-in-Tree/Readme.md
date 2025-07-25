### 2277.Closest-Node-to-Path-in-Tree

#### 解法1：DFS

本题的时间复杂度要求是o(N^2)，所以常规解法是，从node开始dfs得到所有节点到node的距离dist2node。然后从start开始dfs整棵树，对于能够通往end的这个分支上的节点，取最小的dist2node。

本题还有一种比较精彩的解法。先遍历所有的点作为起点，dfs整棵树，这样得到全局的matrix[i][j]表示任意两点之间的距离。然后对于start，我们遍历它的邻居j，发现如果有```matrix[start][end]==matrix[j][end]+1```，说明j是位于从start到end的路径上。依次递归下去，就能直接从start走向end，沿途中取最小的matrix[j][node].

#### 解法2：LCA + Binary Lifting
一个非常好用的结论：在一棵树里，w点到u->v路径最近的点，其实就是以下三个点里深度最大的那一个：lca(u,v), lca(u,w), lca(v,w)

我们用binary lifting模板就可以很容易地得到这三个点的位置，取depth最大的那个即可。

