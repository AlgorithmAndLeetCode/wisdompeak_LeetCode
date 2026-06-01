class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>gain(n, 1);
        for (int i=0; i<n; i++) 
            for (int j=0; j<n; j++) {
                if (i==j) continue;
                if (items[j][0]%items[i][0]==0)
                    gain[i]++;
            }

        vector<int>dp(budget+1, -1);
        dp[0] = 0;
        for (int i=0; i<n; i++)
            for (int b=budget; b>=0; b--) {
                if (b>=items[i][1] && dp[b-items[i][1]]!=-1)
                    dp[b] = max(dp[b], dp[b-items[i][1]]+gain[i]);
            }

        vector<int>p;
        for (auto x: items) p.push_back(x[1]);
        int minPrice = *min_element(p.begin(), p.end());

        int ret = 0;
        for (int b=0; b<=budget; b++) {
            int rem = budget - b;
            ret = max(ret, dp[b]+rem/minPrice);
        }
        return ret;
    }
};
