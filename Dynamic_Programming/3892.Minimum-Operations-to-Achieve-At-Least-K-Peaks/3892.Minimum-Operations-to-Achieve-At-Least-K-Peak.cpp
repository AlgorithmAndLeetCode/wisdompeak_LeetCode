using LL = long long;
class Solution {
public:
    LL solve(vector<LL>&cost, int l, int r, int k) {        
        if (k==0) return 0;
        int m = r-l+1;
        if (m<=0) return LLONG_MAX/2;

        vector<vector<LL>>dp(m+1, vector<LL>(k+1, LLONG_MAX/2));

        dp[0][0] = 0;
        
        for (int i=1; i<=m; i++) {
            int idx = l+i-1;
            for (int j=0; j<=k;j++) {
                dp[i][j] = dp[i-1][j];
                if (i>=2 && j>=1)
                    dp[i][j] = min(dp[i][j], dp[i-2][j-1] + cost[idx]);
                if (j==1)
                    dp[i][j] = min(dp[i][j], cost[idx]);
            }
        }
        return dp[m][k];
    }
    
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k==0) return 0;
        if (k>n/2) return -1;

        vector<LL>cost(n);
        for (int i=0; i<n; i++) {
            int l = (i-1+n)%n;
            int r = (i+1+n)%n;
            LL need = max(nums[l],nums[r])+1;
            cost[i] = max(0LL, need-nums[i]);
        }

        return min(solve(cost, 1, n-1, k), cost[0]+solve(cost,2,n-2,k-1));
    }
};
