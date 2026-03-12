class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> m;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                m[nums1[i]+nums2[j]]++;
            }
        }

        int count = 0;

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                count += m[-(nums3[j]+nums4[k])];
            }
        }

        return count;       
    }
};