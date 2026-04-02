class Solution {
public:

    int solve(vector<vector<int>>& dp, string& t1, string t2, int i, int j){

        if(i<=0||j<=0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(t1[i-1]==t2[j-1]){
            return dp[i][j] = 1+solve(dp,t1,t2,i-1,j-1);
        }

        return dp[i][j] = max(solve(dp,t1,t2,i-1,j), solve(dp,t1,t2,i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        solve(dp,text1,text2,n,m);
        return dp[n][m];
    }
};