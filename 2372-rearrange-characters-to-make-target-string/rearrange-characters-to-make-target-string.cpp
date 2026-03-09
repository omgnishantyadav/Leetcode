class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int count  = INT_MAX;
        unordered_map<char,int> m1,m2;
        for(int i = 0; i<s.size(); i++){
            m1[s[i]]++;
        }

        for(int i=0; i<target.size(); i++){
            m2[target[i]]++;
        }

        for(int i=0; i<target.size(); i++){
            int val = m1[target[i]]/m2[target[i]];
            count = min(count, val);
        }

        return count;
    }
};