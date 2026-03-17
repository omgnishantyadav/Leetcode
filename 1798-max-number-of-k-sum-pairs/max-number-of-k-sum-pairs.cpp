class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        unordered_map<int,int> visited;
        int count = 0; 

        for(int i=0; i<nums.size(); i++){
            if(!visited[nums[i]] && m[k-nums[i]]){
                if(2*nums[i] == k ){
                    count += m[nums[i]]/2;
                }
                else count += min(m[nums[i]],m[k-nums[i]]);
                visited[nums[i]]=1;
                visited[k-nums[i]]=1;
            }
        }


        return count;
    }
};