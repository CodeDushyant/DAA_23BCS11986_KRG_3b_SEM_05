class Solution {
public:
void generateParentheses(string s,vector<string>&v,int n,int close,int open){
if(close==n&&open==n){
    v.push_back(s);
    return;
}
if(open<n){
    generateParentheses(s+"(",v,n,close,open+1);
}
if(close<open){
    generateParentheses(s+")",v,n,close+1,open);
}
}
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string s="";
        generateParentheses(s,v,n,0,0);
        return v;
    }
};
