class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i]%2;
        }

        int count = 0;
        unordered_map<int,int> m;

        for(int i=0; i<=n; i++){
            if(m.find(prefix[i]-k) != m.end()){
                count += m[prefix[i]-k];
            }
            m[prefix[i]]++;
        }
        return count; 
    }
};