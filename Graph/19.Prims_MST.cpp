// Problem link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        vector<bool> is_node_in_MST(V, false);
        int ans = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            int node = top.second;
            int wt = top.first;
            pq.pop();
            
            if(is_node_in_MST[node] == true) continue;
            
            is_node_in_MST[node] = true;
            ans += wt;
            
            for(auto x: adj[node]) {
                
                int neighbour = x[0];
                int neighbour_wt = x[1];
                
                if(is_node_in_MST[neighbour] == false) {
                    
                    pq.push({neighbour_wt, neighbour});
                    
                }
                
            }
        }
        
        return ans;
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


// } Driver Code Ends