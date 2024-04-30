#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void dfs(int u, unordered_map<int, int>& out, unordered_map<int, vector<int>>& graph, vector<pair<int, int>>& ans)
{
    while(out[u])
    {
        int v = graph[u][--out[u]];
        dfs(v, out, graph, ans);
        ans.push_back({u, v});
    }
}

vector<pair<int, int>> eulerian_traversal(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& in, unordered_map<int, int>& out)
{
    int start = -1;
    for(auto &edge : graph)
    {
        if(out[edge.first] - in[edge.first] == 1)
        {
            start = edge.first;
            break;
        }
        else if(out[edge.first] > 0)
        {
            start = edge.first;
        }
    }

    vector<pair<int, int>> ans;
    dfs(start, out, graph, ans);

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("ValidPairs_1.txt", "r", stdin);
        freopen("../output/output1.txt", "w", stdout);
    #endif

    int n; 
    cin >> n;
    
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> in, out;
    for(int i=0;i<n;i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        out[u]++;
        in[v]++;
    }

    vector<pair<int, int>> res = eulerian_traversal(graph, out, in);
    
    if(res.size() == n)
    {
        for(int i=0;i<res.size();i++)
        {
            cout << res[i].first << " " << res[i].second << " ";
        }
    }
    else
    {
        cout << "-1" << "\n";
    }

	return 0;
}
