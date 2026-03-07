class Solution {
public:

    //kandane's algorithm => ig modified
    int solve(vector<int>& a, int i, int j, int len){

        if(j-i+1<len) return 0;

        int best = 0;
        int curr = 0;
        int left = i; //pointer

        for(int k = i; k<=j; k++){
            if(k-left+1<=len) curr += max(a[k],0);
            else {
                curr -= max(0, a[left]);
                left++;
                k--;
            }
            best = max(best, curr);
        }
        return best;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        
        int ans  = 0;
        for(int i=0; i<=n-2; i++){ // each partition of prefix array
            int left = solve(nums,0,i,firstLen);
            int right = solve(nums, i+1, n-1,secondLen);
            ans =  max(ans,left+right);
        }

        for(int i=0; i<=n-2; i++){ // each partition of prefix array
            int left = solve(nums,0,i,secondLen);
            int right = solve(nums, i+1, n-1,firstLen);
            ans =  max(ans,left+right);
        }

        return ans;
    }
};