class Solution {
public:
    long long help(vector<int>& nums, long long k, unordered_map<int,int>& m) {
        long long count = 0; 
        unordered_map<int,int> visited;
        for(int i=0; i<nums.size(); i++){
            if(!visited[nums[i]] && m[k-nums[i]]){
                long long n1 = m[nums[i]];
                long long n2 = m[k-nums[i]];
                if(2LL*nums[i] == k ){
                    count += (n1*(n1-1))/2;
                }
                else count += n1*n2;

                visited[nums[i]] = 1;
                visited[k-nums[i]] = 1; 
            }
        }

        return count;
    }


    int countPairs(vector<int>& deliciousness) {

        unordered_map<int,int> m;
        int MOD = 1e9+7;
        
        for(int i=0; i<deliciousness.size(); i++){
            m[deliciousness[i]]++;
        }

        long long answer = 0;
        for(int i=0; i<=26; i++){
            long long k = 1LL<<i;
            answer = (answer + help(deliciousness, k, m)) % MOD;
        }
        return (int) answer;
    }
};