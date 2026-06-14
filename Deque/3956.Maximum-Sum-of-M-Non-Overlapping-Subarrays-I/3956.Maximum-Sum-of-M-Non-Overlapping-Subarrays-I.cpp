using ll = long long;
class Solution {    
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        // dp[k][i] = max{dp[k][i-1], dp[k-1][i-d] + presum[i]-presum[i-d]}    l<=d<=r;
        int n = nums.size();
        vector<ll>presum(n+1);
        nums.insert(nums.begin(), 0);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1] + nums[i];
        
        vector<vector<ll>>dp(m+1, vector<ll>(n+1, LLONG_MIN/2));
        for (int i=0; i<=n; i++)
            dp[0][i] = 0;

        ll ret = LLONG_MIN/2;
        for (int k=1; k<=m; k++) {
            if (k*l>n) break;
            deque<pair<int,ll>>dq;
            for (int i=1; i<=n; i++) {
                if (i>=l) {
                    ll val = dp[k-1][i-l]  - presum[i-l];
                    while (!dq.empty() && dq.back().second<=val)
                        dq.pop_back();
                    dq.push_back({i-l, val});
                }
                if (i>=r) {
                    while (!dq.empty() && dq.front().first<i-r)
                        dq.pop_front();
                }
                                                
                if (!dq.empty())
                    dp[k][i] = max(dp[k][i-1], dq.front().second + presum[i]);

            }
            ret = max(ret, dp[k][n]);
        }

        return ret;


    }
};
