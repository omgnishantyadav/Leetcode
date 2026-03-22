class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        unordered_map<char,int> mt,ms;

        for(auto x: t){
            mt[x]++;
        }

        int required = mt.size();
        int formed = 0;
        int g = INT_MAX;
        int left = 0;
        int start = left;

        for(int right = 0; right <m; right++){

            ms[s[right]]++; 

            if(mt.count(s[right]) && ms[s[right]] == mt[s[right]] ) formed++;
             
            while(formed == required){

                if(right-left+1<g){
                    g = right - left+1;
                    start = left;
                }


                char ch = s[left];
                ms[ch]--;

                if(mt.count(ch) && ms[ch]<mt[ch]){
                    formed--;
                }

                left++;
            }
        } 

        if(g==INT_MAX) return "";
        return s.substr(start, g);
    }
};