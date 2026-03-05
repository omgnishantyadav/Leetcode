class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> d(n);
        vector<vector<int>> g(n, vector<int> ());
        for(int i=0; i<n-1; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        queue<int> q;
        int N = n;
        for(int i=0; i<n; i++){
            d[i] = g[i].size();
            if(d[i]==1 && !hasApple[i] && i!=0) q.push(i);
        }

        while(!q.empty()){
            N--;
            int u = q.front();
            q.pop();

            for(auto v: g[u]){
                d[v]--;
                if(d[v]==1 && !hasApple[v] && v!=0) q.push(v);
            }
        }

        return max(0,2*(N-1));
    }
};