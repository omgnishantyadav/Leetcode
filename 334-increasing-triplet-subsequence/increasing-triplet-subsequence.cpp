class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;//minimum
        int min2 = INT_MAX; // second minimum
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] <= min1){
                min1 = nums[i];   
            }
            else if(nums[i]<=min2){
                min2 = nums[i];
            }
            else return true;
        }
        return false;
    }
};