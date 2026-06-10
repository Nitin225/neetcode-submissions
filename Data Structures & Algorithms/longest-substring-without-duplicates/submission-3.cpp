class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int mx = 0;
        int l = 0;
        for(int i = 0; i < s.length(); i++) {
            while(st.count(s[i])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);

            mx = max(mx, i - l + 1);
        }
        return mx;
    }
};
