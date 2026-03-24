class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& a, vector<int>& c, int left, int i){
        if(left<0) return;
        if(left==0){
            ans.push_back(a);
        }
        else{
            for(int j=i; j<c.size() && left>=c[j]; j++){
                if(j>i && c[j]==c[j-1]) continue;

                a.push_back(c[j]);
                solve(ans,a,c,left-c[j], j+1);
                a.pop_back();
            }
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& c, int tar) {
        vector<vector<int>> ans;
        sort(c.begin(), c.end()); // what is the need of sorting ?
        vector<int> a;
        solve(ans,a,c,tar,0);
        return ans;
    }
};