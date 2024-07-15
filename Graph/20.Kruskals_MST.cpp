#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> parent;
	vector<int> rank;
	
	int find(int x) {
	    if(parent[x] == x) return x;
	    
	    return parent[x] = find(parent[x]);
	}
	
	void Union(int x, int y) {
	    int parent_x = find(x);
	    int parent_y = find(y);
	    
	    if(parent_x == parent_y) return;
	    
	    if(rank[parent_x] > rank[parent_y]) {
	        parent[parent_y] = parent_x;
	    }
	    else if(rank[parent_x] < rank[parent_y]) {
	        parent[parent_x] = parent_y;
	    }
	    else {
	        parent[parent_y] = parent_x;
	        rank[parent_x]++;
	    }
	}
	
	int Kruskals( vector<vector<int>> edges_vec) {
	    int sum = 0;
	    
	    for(auto x: edges_vec) {
	        
	        int u = x[0];
	        int v = x[1];
	        int wt = x[2];
	        
	        int parent_u = find(u);
	        int parent_v = find(v);
	        
	        if(parent_u != parent_v) {
	            Union(u, v);
	            sum += wt;
	        }
	        
	    }
	    return sum;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        parent.resize(V);
        rank.resize(V, 0);
        
        for(int i = 0; i < V; i++) {
            parent[i] = i;
        }
        
        vector<vector<int>> edges_vec;
        for(int i = 0; i < V; i++) {
            for(auto x: adj[i]) {
                
                int u = i;
                int v = x[0];
                int wt = x[1];
                
                edges_vec.push_back({u, v, wt});
                
            }
        }
        
        auto comparator = [&](vector<int> v1, vector<int> v2) {
          return v1[2] < v2[2];  
        };
        sort(edges_vec.begin(), edges_vec.end(), comparator);
        
        return Kruskals(edges_vec);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
