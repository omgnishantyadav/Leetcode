class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        long long l=0, lc=0, lct=0, t=0, ct=0, c=0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='L') l++;
            else if(s[i]=='C') {lc += l; c++;}
            else if(s[i]=='T') {lct += lc; t++; ct += c;}
        }

        long long ans1 = ct + lct;
        long long ans3 = lc + lct;
        cout<<lct<<" ";
        long long ans2 = lct;
        l=0;
        for(int i=0; i<n-1; i++){
            if(s[i]=='L') l++;
            if(s[i]=='T') t-- ;
            ans2 = max(ans2, lct+l*t);
        }
         cout<<ans1<<" "<<ans2<<" "<<ans3;
        return max({ans1,ans2,ans3}); 
       
    }
};