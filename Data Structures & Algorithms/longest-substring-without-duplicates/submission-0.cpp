class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int mx = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++) {
            while(st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);

            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};
