class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0;
        unordered_map<int,int> m;
        m[0]++;
        int count = 0;
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        for(int r=0; r<nums.size(); r++){
            if(m.find(nums[r]-goal) != m.end()){
                count += m[nums[r]-goal];
            }
            m[nums[r]]++;
        }
        return count;
    }
};

/*
observation

longest nahi number of subarray with goal
[0,1,0,1,0,1] => [0,1,1,2,2,3]

*/