#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

bool bfs(vector<vector<int>>& residual_g, int n, int src, int sink, vector<int>& parent)
{
    vector<bool> visited(n, 0);
	queue<int> q;
	q.push(src);
	visited[src] = true;
	parent[src] = -1;

	while(!q.empty()) 
    {
		int u = q.front();
		q.pop();

		for(int v = 0; v < n; v++) 
        {
			if(visited[v] == false && residual_g[u][v] > 0) 
            {
				if(v == sink) 
                {
					parent[v] = u;
					return true;
				}
                else
                {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
			}
		}
	}

	return false; //return false if we cant reach sink
}

int ford_fulkerson(vector<vector<int>>& graph, int n, int src, int sink)
{
	vector<vector<int>> residual_g(n, vector<int> (n, 0));// Residual graph indiacting capacity
	residual_g = graph;

	vector<int> parent(n, 0);

	int src_sink_flow = 0;

	while(bfs(residual_g, n, src, sink, parent) != 0) 
    {
		int min_flow = INT_MAX;

        int i = sink;
        while(i != src)
        {
            int j = parent[i];
			min_flow = min(min_flow, residual_g[j][i]);
            i = parent[i];
        }
		
        i = sink;
        while(i != src)
        {
            int j = parent[i];
			residual_g[j][i] -= min_flow;
			residual_g[i][j] += min_flow;
            i = parent[i];
        }

		src_sink_flow += min_flow;
	}

	return src_sink_flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("MaxFlow.txt", "r", stdin);
        freopen("../output/output.txt", "w", stdout);
    #endif

    int n; 
    cin >> n;
    int src, dst;
    cin >> src >> dst;
    vector<vector<int>> graph(n, vector<int> (n, 0));
    int node1, node2, weight;
    while (cin >> node1 >> node2 >> weight) {
        graph[node1-1][node2-1] = weight;
    }

    auto start = std::chrono::high_resolution_clock::now();
    cout << ford_fulkerson(graph, n, src-1, dst-1) << "\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << duration.count();

	return 0;
}
