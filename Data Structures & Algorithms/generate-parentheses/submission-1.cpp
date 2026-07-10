class Solution {
private:
    void helper(int i, int a, int n, string s, vector<string> &ans){
        
        if(a < 0) return;

        if(i == 2*n && a == 0){
            ans.push_back(s);
            return;
        }
        if(i < 2*n)
            helper(i+1, a+1, n, s+"(", ans);
        if(a > 0)
            helper(i+1, a-1, n, s+")", ans);

        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, 0, n, "", ans);
        return ans;
    }
};
