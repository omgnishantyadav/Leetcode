class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int round = 0;
        unordered_map<int,int> m;
        for(int i=0; i<tasks.size(); i++){
            m[tasks[i]]++;
        }

        for(auto it:m){
            int x = it.second;
            if(x==1) return -1;
            int cnt = x/6;
            cnt*=2;
            x%=6;
            if(x%2==0){
                cnt += x/2;
            }
            else if(x==3) cnt++;
            else if(x==5) cnt+=2; 
            if(x==1) cnt++;
            round += cnt;
        }
        return round;
    }
};