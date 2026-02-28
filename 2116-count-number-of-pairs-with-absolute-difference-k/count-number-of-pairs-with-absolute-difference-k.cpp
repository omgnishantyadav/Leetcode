class Solution {
public:
    int countKDifference(vector<int>& b, int k) {
        int n = b.size();
        unordered_map<int,int> m;

        int count = 0;
        for(int i=0; i<n; i++){
            if(m[b[i]+k]){
                count += m[b[i]+k];
            }
            if(m[b[i]-k]){
                count += m[b[i]-k];
            }
            m[b[i]]++;
        }
        
        return count;
    }
    
};