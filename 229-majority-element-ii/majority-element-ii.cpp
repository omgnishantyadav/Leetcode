class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //boore morey majority element
        int n1,n2,m1,m2; 
        n1 =0; n2 =0;
        m1 = 0; m2 = 1;

        for(auto m: nums){
            if(m==m1) n1++;
            else if(m==m2) n2++;
            else if(n1==0){
                m1=m; n1=1;
            }
            else if(n2==0){
                m2=m; n2=1;
            }
            else {
                n1--;
                n2--;
            }
        }

        vector<int> ans;
        if(3*count(nums.begin(), nums.end(), m1) > nums.size()) ans.push_back(m1);
        if(3*count(nums.begin(), nums.end(), m2) > nums.size()) ans.push_back(m2);

        return ans;
    }
};