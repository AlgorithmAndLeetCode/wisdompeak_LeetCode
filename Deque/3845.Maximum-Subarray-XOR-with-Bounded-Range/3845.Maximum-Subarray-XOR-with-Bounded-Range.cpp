class TrieNode {
    public:
        TrieNode* next[2];        
        int count;
    TrieNode()
    {
        for (int i=0; i<2; i++)
            next[i]=NULL;        
        count = 0;
    }
};

class Solution {
    void updateTrie(int x, int delta) {        
        TrieNode* node = root;
        for (int i=30; i>=0; i--) {
            int b = ((x>>i)&1);
            if (!node->next[b])
                node->next[b] = new TrieNode();
            node = node->next[b];
            node->count += delta;
        }
    }

    int find(int x) {
        TrieNode* node = root;
        int ret = 0;
        for (int i=30; i>=0; i--) {
            int b = ((x>>i)&1);            
            if (node->next[1-b] && (node->next[1-b]->count)>0) {                
                ret += ((1-b)<<i);
                node = node->next[1-b];
            } else if (node->next[b] && (node->next[b]->count)>0) {
                ret += (b<<i);
                node = node->next[b];
            }
        }
        return ret^x;
    }
    
    TrieNode* root;    
public:
    int maxXor(vector<int>& nums, int k) {
        root = new TrieNode();
        updateTrie(0, 1);

        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int>prefix(n+1, 0);
        for (int i=1; i<=n; i++)
            prefix[i] = prefix[i-1]^nums[i];
        
        int L = 1;
        int ret = 0;
        deque<int>mindq, maxdq;
        for (int r=1; r<=n; r++) {
            while (!mindq.empty() && nums[mindq.back()]>=nums[r])
                mindq.pop_back();
            mindq.push_back(r);
            while (!maxdq.empty() && nums[maxdq.back()]<=nums[r])
                maxdq.pop_back();
            maxdq.push_back(r);      

            updateTrie(prefix[r], 1);

            while (L<r && !mindq.empty() && !maxdq.empty() && nums[maxdq.front()]-nums[mindq.front()]>k) {
                if (L-1>=0) {                    
                    updateTrie(prefix[L-1], -1);
                }
                if (!mindq.empty() && mindq.front()==L) mindq.pop_front();
                if (!maxdq.empty() && maxdq.front()==L) maxdq.pop_front();
                L++;
            }

            ret = max(ret, find(prefix[r]));
        }

        return max(ret, nums[1]);
    }
};
