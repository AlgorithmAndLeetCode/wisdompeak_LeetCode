### 3593.Minimum-Increments-to-Equalize-Leaf-Paths

很明显，为了减少increment的操作，我们会将所有root-to-leaf的路径与最长的那条路径对齐。但是我们并不需要显式地先求全局最长的路径，我们只需要用dfs函数将每一棵子树内的所有root-to-leaf路径长度拉齐即可。

具体地，对于根节点为u的子树，我们设计dfs返回该子树最终的最长路径maxPath，以及将其所有root-to-leaf的路径拉齐至maxPath所需要的操作数totalChanged. 我们做后序遍历，先对所有子节点都做一遍dfs。那么以u为根的maxPath就是所有子节点里最长的路径mx加上cost[u]；以u为根的totalChanged就是所有子节点的totalChanged之和，再加上需要将路径长度拉高至mx的子路径的个数。
