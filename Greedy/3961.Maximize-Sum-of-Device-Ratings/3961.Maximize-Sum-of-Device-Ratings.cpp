using ll = long long;
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();

        if (n==1) {
            ll ret = 0;
            for (int i=0; i<m; i++)
                ret += units[i][0];
            return ret;
        }

        int globalMin = INT_MAX;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                globalMin = min(globalMin, units[i][j]);

        ll sum = 0;
        int gap = INT_MAX;
        for (int i=0; i<m; i++) {
            int mn1 = INT_MAX, mn2 = INT_MAX;
            for (int j=0; j<n; j++) {
                if (units[i][j] <= mn1) {
                    mn2 = mn1;
                    mn1 = units[i][j];
                } else if (units[i][j] < mn2) {
                    mn2 = units[i][j];
                }
            }
            sum += mn2;
            gap = min(gap, mn2-globalMin);
        }

        return sum - gap;
    }
};
