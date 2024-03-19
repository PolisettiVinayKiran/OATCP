#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


int calc_pairs(int n, int m, vector<int>& boys, vector<int>& girls, vector<vector<int>>& dp) 
{
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i-1>=0 && j-1>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            if(abs(boys[i] - girls[j])<=1)
            {
                dp[i][j] = (dp[i][j] + 1) % mod;
            }
            if(i-1>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            if(j-1>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
    return dp[n-1][m-1];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("BersuBall_input_3.txt", "r", stdin);
        freopen("../output/output3.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> boys(n);
    for(int i=0;i<n;i++)
    {
        cin >> boys[i];
    }
    int m;
    cin >> m;
    vector<int> girls(m);
    for(int i=0;i<m;i++)
    {
        cin >> girls[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    if(n == 0 || m == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << calc_pairs(n, m, boys, girls, dp) << "\n";
    }
}