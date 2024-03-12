#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


int calc_ways(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& dp) 
{
    if (i == 0 && j == 0)
    {
        return 1;
    }

    if (i < 0 || j < 0)
    {
        return 0;
    }

    if(grid[i][j] == '*')
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int left = calc_ways(i - 1, j, grid, dp);

    int up = calc_ways(i, j - 1, grid, dp);

    return dp[i][j] = up + left;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("../output/output1.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    
    vector<vector<char>> grid(n, vector<char>(n,'\0'));

    for(int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < n; j++) {
            grid[i][j] = line[j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << calc_ways(n - 1, n - 1, grid, dp) << "\n";
}