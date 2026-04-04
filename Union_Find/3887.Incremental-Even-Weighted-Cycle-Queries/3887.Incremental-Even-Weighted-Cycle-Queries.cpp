struct DSU {
    vector<int> p, r, d;
    DSU(int n): p(n,-1), r(n,0), d(n,0) {
        iota(p.begin(), p.end(), 0);
    }
    pair<int,int> find(int x) {
        if (p[x]==x)
            return {x, 0};
        auto [root, dist] = find(p[x]);
        p[x] = root;
        d[x] = (dist+d[x])%2;            
        return {p[x], d[x]};
    }
    void unite(int a, int b, int w) {
        auto [ra, da] = find(a);
        auto [rb, db] = find(b);        
        p[a] = rb;
        p[ra] = rb;
        d[a] = (w+db)%2;
        d[ra] = (da+w+db)%2;
    }
};

class Solution {
public:
    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ret = 0;
        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            auto [ru, du] = dsu.find(u);
            auto [rv, dv] = dsu.find(v);
            if (ru==rv) {                
                ret += ((du+dv+w)%2==0);
            }                
            else {
                dsu.unite(u,v,w);
                ret += 1;
            }
        }
        return ret;
    }
};
