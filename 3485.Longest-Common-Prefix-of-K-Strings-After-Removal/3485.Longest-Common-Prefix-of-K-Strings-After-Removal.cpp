class TrieNode {
    public:
    TrieNode* next[26];   
    int count = 0;
    TrieNode()
    {
        for (int i=0; i<26; i++)
            next[i]=NULL;        
    }
};

class Solution {
    TrieNode* root;
    int k;
    map<int,int>Map;
public:
    void add(string& s, int delta) {
        TrieNode* node = root;
        int depth = 0;
        for (auto ch: s) {
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node = node->next[ch-'a'];
            node->count+=delta;
            depth++;

            int oldValue = node->count-delta;
            int newValue = node->count;
            if (oldValue<k && newValue>=k) {
                Map[depth]++;
            } else if (oldValue>=k && newValue<k) {
                Map[depth]--;
                if (Map[depth]==0)
                    Map.erase(depth);
            }
        }
    }

    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        this->k = k;
        root = new TrieNode();
        for (auto& word: words)
            add(word, 1);        

        vector<int>rets;
        for (auto& word: words) {
            add(word, -1);            

            if (Map.empty())
                rets.push_back(0);
            else
                rets.push_back(Map.rbegin()->first);
            
            add(word, 1);
        }
        return rets;
    }
};
