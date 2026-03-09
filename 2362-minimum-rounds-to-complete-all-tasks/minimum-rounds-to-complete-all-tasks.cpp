class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int round = 0;
        unordered_map<int,int> m;
        for(int i=0; i<tasks.size(); i++){
            m[tasks[i]]++;
        }

        for(auto it:m){
            int f = it.second;
            if(f==1) return -1;
            round += ceil( (f+2) / 3);
        }
        return round;
    }
};

//gredy approach 