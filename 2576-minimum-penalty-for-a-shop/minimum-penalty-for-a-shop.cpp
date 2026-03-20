class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.size();

        vector<int> suffix(n+1,0); // count of Y after i
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y') suffix[i] = 1;
            else suffix[i] = 0;

            suffix[i] += suffix[i+1];
        }

        int prefix = 0; //count of N till i
        int hour = 0;
        int maxpen =suffix[0];

        for(int i=1; i<=n; i++){
            if(i>0 && customers[i-1]=='N') prefix++;
            if(prefix+suffix[i]<maxpen){
                hour = i;
                maxpen = prefix+suffix[i];
            }  
        }
        return hour;
    }
};