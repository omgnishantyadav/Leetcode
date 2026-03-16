class Solution {
public:
    int longestMountain(vector<int>& arr) {

        if(arr.size()<3) return 0;
        int maxLen  = 0;
        for(int i=1; i<=arr.size()-2; i++){
            int j=i;
            while(j > 0 && arr[j-1]<arr[j]){
                j--;
            }
            int k=i;
            while(k+1<arr.size() && arr[k]>arr[k+1]){
                k++;
            }
            if(k>i && j<i )  maxLen = max(maxLen, k-j+1);
        }
        return maxLen;
    }
};