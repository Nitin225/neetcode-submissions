class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int l = 0;
        int ans = 0;

        for(int i = 0; i < s.length(); i++) {
            if(m.count(s[i])) {
                l = max(l, m[s[i]] + 1);
            }
            m[s[i]] = i;
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};