class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int l = 0;
        int maxLen = 0;
        int maxf = 0;

        for(int r=0; r<s.length(); r++){
            m[s[r]]++;
            maxf = max(maxf, m[s[r]]);

            while(r-l+1 - maxf > k){
                m[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
