class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto x: nums){
            m[x]++;
        }

        vector<pair<int,int>> v;
        for(pair<int,int> x: m){
            v.push_back(x);
        }

        sort(v.begin(), v.end(), 
        [](pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
        });

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
