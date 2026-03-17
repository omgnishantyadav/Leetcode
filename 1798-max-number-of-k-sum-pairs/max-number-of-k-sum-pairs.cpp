class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count = 0; 
        for(int i=0; i<nums.size(); i++){
            if(m.find(k-nums[i]) != m.end()){
                count ++;
                m[k-nums[i]]--;
                if(m[k-nums[i]]==0) m.erase(k-nums[i]);   
            }
            else{
                m[nums[i]]++;
            }
        }

        return count;
    }
};