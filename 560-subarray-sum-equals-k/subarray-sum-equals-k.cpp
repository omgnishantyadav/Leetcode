class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i=1; i<=n; i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }

        int count = 0;

        map<int,int> m;
        for(int i=0; i<=n; i++){
            if(m[prefix[i]-k]){
                count += m[prefix[i]-k];
            }
            
            
            m[prefix[i]]++;
        }
        return count;
    }
};