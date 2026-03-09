class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int count = 0;
        unordered_map<int,int> m;
        int prefixSum = 0;
        m[0]++; 
        for(int i=0; i<n; i++){
            prefixSum += (nums[i]%2);
            if(m.find(prefixSum-k) != m.end()){
                count += m[prefixSum-k];
            }
            m[prefixSum]++;
        }
        return count; 
    }
};