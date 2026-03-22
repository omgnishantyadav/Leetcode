class Solution {
public:
    long long countStableSubarrays(vector<int>& c) {
        int n = c.size();
        long long pre = 0;

        unordered_map<long long, unordered_map<long long, long long>> m;
        long long count = 0;

        for(int i=0; i<n; i++){
            if(m.count(c[i]) && m[c[i]].count(pre - c[i])){
                count += m[c[i]][pre-c[i]];
            }

            pre+=c[i];
            m[c[i]][pre]++;

            if(i>0 && c[i]==0 && c[i-1]==0){
                count--;
            }
        }

        return count;
    }
};