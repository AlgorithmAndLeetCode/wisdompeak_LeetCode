# 定义允许递归的的lamda函数
std::function<void(int,int)> dfs = [&](int l, int r) {
  int mid = (l+r)/2;
  dfs(l, mid-1);
  dfs(mid, r));
}

# 定义允许递归的、带有返回值的lamda函数
std::function<ll(int,int)> dfs = [&](int l, int r) -> ll {
    int mid = (l+r)/2;
    return min(dfs(l, mid-1) + dfs(mid, r));
};

return dfs(0, n-1);

