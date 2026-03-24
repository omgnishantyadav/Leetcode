class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        
        int count = 0;

        for(int i =0; i<n; i++){

            if(m.find(nums[i]) != m.end() ){
                if(m[nums[i]]==1 && k==0){
                    count++;
                    m[nums[i]]++;
                }
                continue;
            }

            if(m.find(nums[i]-k)!=m.end()){
                count ++;
            }
            if(m.find(nums[i]+k)!=m.end()){
                count ++;
            }
            
            
            m[nums[i]]++;

        }
        return count;
    }
};