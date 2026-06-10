class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int l, r, count;
        l = r = count = 0;
        int st = -1;
        int minLen = INT_MAX;
        for(int i=0; i<t.size(); i++){
            hash[t[i]]++;
        }

        while(r < s.size()){
            if(hash[s[r]] > 0)
                count++;

            hash[s[r]]--;
            while(count == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    st = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }
        return st == -1?"": s.substr(st, minLen);
    }
};
