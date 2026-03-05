class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> g(n,vector<int>());
        for(int i=0; i<n-1; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> d(n);
        queue<int> q;

        int N = n;

        for(int i=0; i<n; i++){
            d[i] = g[i].size();
            if(d[i]==1 && coins[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int u = q.front();
            q.pop();
            N--;
            int parent = -1;
            for(auto v : g[u]){
                d[v]--;
                parent = v; 
                if(d[v]==1 && coins[v]==0) q.push(v);
            }
            if(parent == -1) break;
            g[u].erase(find(g[u].begin(), g[u].end(), parent));
            g[parent].erase(find(g[parent].begin(), g[parent].end(), u));

        }

        for(int i = 0; i<2; i++){

            while(!q.empty()) q.pop();

            for(int i=0; i<n; i++){
                d[i] = g[i].size();
                if(d[i]==1){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int u = q.front();
                q.pop();
                N--;
                int parent = -1;
                for(auto v: g[u]){
                    d[v]--;
                    parent = v;
                }
                if(parent == -1) break;
                g[u].erase(find(g[u].begin(), g[u].end(), parent));
                g[parent].erase(find(g[parent].begin(), g[parent].end(), u));
            }
        }
        return max(0,2*(N-1));

        
    }
};