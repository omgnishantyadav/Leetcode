class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;

        vector<int> suffixLargest(n);
        suffixLargest[n-1]=nums[n-1];
        for(int i =n-2; i>=0; i--){
            suffixLargest[i]=max(suffixLargest[i+1],nums[i]); 
        }
        int prefixSmallest = nums[0];
        for(int j=1; j<=n-2; j++){
            if(prefixSmallest<nums[j] && nums[j]<suffixLargest[j+1]) return  true;
            prefixSmallest = min(prefixSmallest, nums[j]);
        }
        return false;
    }
};