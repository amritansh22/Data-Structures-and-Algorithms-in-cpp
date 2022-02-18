class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string sub = "";
        helper(sub, n, n, 0);
        return res;
    }
    void helper(string &sub,int l, int r , int b){
        if(l == 0 && r == 0){
            res.push_back(sub);
            return;
        }
        if(b < 0){
            return;
        }
        if(l > 0){
            sub.push_back('(');   
            helper(sub, l-1, r, b+1);
            sub.pop_back();
        }
        if(r > 0){
            sub.push_back(')');   
            helper(sub, l, r-1, b-1);
            sub.pop_back();
        }
    }
    vector<string> res;
};
