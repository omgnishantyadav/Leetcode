class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        int ans=0;
        int prev=0;
        int prevCnt=-1;
        for(auto x:m){
            if(prevCnt!=-1) {
                if(x.first==prev+1) ans=max(ans,prevCnt+x.second);
            }
            prev=x.first;
            prevCnt=x.second;
        }

        return ans;
        
    }
};