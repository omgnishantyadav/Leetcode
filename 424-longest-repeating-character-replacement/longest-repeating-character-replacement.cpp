class Solution {
public:


    int solve(string s, int k, int c){
        vector<int> a;
        for(int i = 0; i<s.size(); i++){
            if(s[i]==c) a.push_back(0);
            else a.push_back(1);
        }

        int sum = 0;
        int l=0; 
        int ans = 0;
        for(int r=0; r<a.size(); r++){
            sum+=a[r];

            while(sum>k){
                sum-=a[l];
                l++;
            }

            ans = max(ans,r-l+1);
        }

        return ans;
    }
    int characterReplacement(string s, int k) {
        unordered_map<int,int> m;
        int ans = 0; 
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) == m.end()){
                ans = max(ans, solve(s,k,s[i]));
                m[s[i]]++;
            }
        }
        return   ans;
    }
};


/*
observations
there can be different characters also
return the maximum window with sum k
*/