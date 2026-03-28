class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int mn = arr[0];
        int mx = arr[0];
        int ans = arr[0];
        for(int i=1; i<n; i++){
            int temp = max({arr[i], arr[i] * mx, arr[i] * mn });
            mn = min({arr[i], arr[i]*mx, arr[i]*mn});
            mx=temp;
            ans=max(ans,mx);
        }

        return ans;
    }
};