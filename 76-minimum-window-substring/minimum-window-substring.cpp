class Solution {
public:
    
    bool isEqual(unordered_map<char,int>& ms, unordered_map<char,int>& mt){
        for(auto x: mt){
            if(ms[x.first]<x.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int start = 0;
        int g = INT_MAX;
        int m = s.size();
        int n = t.size();

        

        unordered_map<char,int> mt;
        unordered_map<char,int> ms;
        for(int i=0; i<n; i++){
            mt[t[i]]++;
        }
        
        int left = 0;
        for(int i = 0; i<m;){
            while(i<m && !isEqual(ms,mt)){
                if(mt[s[i]]) ms[s[i]]++;
                i++;
            }

            while(left<i){
                if(!isEqual(ms,mt)){
                    break;
                }

                //match toh hain yaha pe
                int cnt = i - left;
                if(cnt<g){
                    g = cnt;
                    start = left;
                }
                if(mt[s[left]]){
                    ms[s[left]]--;
                }
                left++;                            
            }
        }

        if(g==INT_MAX) return "";

        return s.substr(start, g);
    }
};