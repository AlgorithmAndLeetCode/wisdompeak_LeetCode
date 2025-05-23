### 131.Palindrome-Partitioning

首先预处理字符串，用区间型dp计算出任意两个index之间的substring是否是回文串，记做dp[i][j].

然后从第一个字符开始进行深度优先搜索。设计dfs(i,temp)，表示考虑以当前的位置i为substring的开头，遍历有哪些位置j满足[i:j]的字符串满足回文（即dp[i][j]=1），就将该字符串收录进temp，然后递归搜索第j+1个位置。如果dfs的参数i走到了n，说明恰好将整个s分割成了若干段回文串，就将这组分割的子串temp加入最终答案。

特别注意，这个dfs在回溯的时候需要将temp末尾加入的子串弹出。

[Leetcode Link](https://leetcode.com/problems/palindrome-partitioning/)
