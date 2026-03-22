class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int odd = INT_MAX;
        int even = INT_MAX;
        
        for(int i =0; i<nums.size(); i++){
            if(nums[i]%2){
                odd = min(odd, nums[i]);
            }
            else even = min(even, nums[i]);
        } 
        
        if(even==INT_MAX||odd == INT_MAX) return true;
        return even>odd;
    }
};