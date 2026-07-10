class Solution {
private:
    int hammingWeight(int n) {
        int count = 0;
        for(int i=0; i<32; i++){
            count += (n >> i) & 1;
        }
        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<=n; i++){
            int count = hammingWeight(i);
            ans.push_back(count);
        }
        return ans;
    }
};
