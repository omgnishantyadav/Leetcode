class Solution {
public:


    void solve(unordered_map<int, vector<char>>& m, string& d, vector<string>& ans, int i, string& s){
        if(d.size() == s.size()){
            ans.push_back(s);
            return;
        }

        for(auto ch : m[d[i]-'0']){
            s.push_back(ch);
            solve(m,d,ans,i+1,s);
            s.pop_back();
        }

        return ;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> m;
        m[2] = {'a','b','c'};
        m[3] = {'d','e','f'};
        m[4] = {'g','h','i'};
        m[5] = {'j','k','l'};
        m[6] = {'m','n','o'};
        m[7] = {'p','q','r','s'};
        m[8] = {'t','u','v'};
        m[9] = {'w','x','y','z'};

        vector<string> ans;
        string s = "";
        solve(m,digits,ans, 0,s);
        return ans;
    }
};