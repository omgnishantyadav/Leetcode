class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int right = 0;
        int n = cardPoints.size();
        int j=n-1;
        while(j>=n-k){
            right += cardPoints[j];
            j--;
        }
        j++;
        int ans = right;
        int left = 0; 
        for(int i = 0; i<k; i++){
            left += cardPoints[i];
            right -= cardPoints[j];
            ans = max(ans, left+right);
            j++;
        } 

        return ans;
    }
};