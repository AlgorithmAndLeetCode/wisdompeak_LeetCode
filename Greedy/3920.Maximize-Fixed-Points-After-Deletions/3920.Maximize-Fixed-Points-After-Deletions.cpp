class Solution {
public:
    int LIS_LEN(vector<pair<int,int>>&arr) {
        sort(arr.begin(), arr.end(), [](const auto&x, const auto&y){
            if (x.first!=y.first)
                return x.first<y.first;
            return x.second>y.second;
        });
        vector<int>lis;
        for (auto &[a,b]: arr) {
            auto iter = upper_bound(lis.begin(), lis.end(), b);
            if (iter == lis.end()) 
                lis.push_back(b);
            else
                *iter = b;
        }
        return lis.size();
    }
    
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>d;
        for (int i=0; i<n; i++) {
            if (nums[i]<=i)
                d.push_back({nums[i], i-nums[i]});
        }

        return LIS_LEN(d);
    }
};
