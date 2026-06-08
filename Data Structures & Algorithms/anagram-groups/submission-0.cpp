class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> v;
        for(auto x: strs){
            sort(x.begin(), x.end());
            v.push_back(x);
        }
        vector<bool> vis(strs.size(), false);
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++){
            if(vis[i]) continue;
            vector<string> a;
            a.push_back(strs[i]);
            vis[i] = true;
            for(int j=i+1; j<strs.size(); j++){
                if(v[i] == v[j]){
                    a.push_back(strs[j]);
                    vis[j] = true;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};
