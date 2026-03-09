class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        int ans = 0;
        int cnt = 0; 
        for(auto it:m){
            if(cnt==0){
                cnt++;
                ans = max(ans,cnt);
                continue;
            }
            if(m[it.first-1]) cnt++;
            else cnt = 1;
            ans = max(ans,cnt);
        }
        return ans;
    }
};