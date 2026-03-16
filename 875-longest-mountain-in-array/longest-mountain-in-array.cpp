class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n), suffix(n);

        for(int i = 0; i<n; i++){
            if(i>0 && arr[i-1]<arr[i]){
                prefix[i] = prefix[i-1] + 1;
            }
            else prefix[i]=1;
        }
        for(int i=n-1; i>=0; i--){
            if(i+1<n && arr[i]>arr[i+1]) {
                suffix[i] = suffix[i+1]+1;
            }
            else suffix[i] = 1;
        }
        int maxlen = 0;
        for(int i=0; i<n; i++){
            if(prefix[i]>1 && suffix[i]>1)maxlen = max(maxlen, prefix[i] + suffix[i] - 1);
        }
        return maxlen;
    }
};