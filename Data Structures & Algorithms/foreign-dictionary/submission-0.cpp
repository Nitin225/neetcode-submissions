class Solution {
public:
    vector<int> kahnAlgo(int n, vector<vector<int>> &adj){
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans; 
    }

    string foreignDictionary(vector<string>& dict) {
        
        set<char> chars;
        for(auto& word : dict)
            for(char c : word)
                chars.insert(c);
        int k = chars.size();

        int N = dict.size();

        vector<vector<int>> adj(26);
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];

            if(s1.length() > s2.length() && s1.substr(0, s2.length()) == s2)
                return "";

            int len = min(s1.length(), s2.length());
            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }

        

        vector<int> topo = kahnAlgo(26, adj);
        if(topo.size() != 26) return "";

        string ans = "";
        for(auto it : topo){
            if(chars.count(char(it + 'a')))
            ans += char(it + 'a');
        }

        return ans;
    }
};
