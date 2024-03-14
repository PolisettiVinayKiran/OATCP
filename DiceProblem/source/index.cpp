#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int calc_ways(int target, vector<int>& faces, vector<int>& dp)
{
    if(target == 0)
    {
        return 1;
    }
    
    if(dp[target] != -1)
    {
        return dp[target];
    }
        
    int ways = 0;
    
    for(int i=0;i<faces.size();i++)
    {
        if(faces[i] <= target)
        {
            ways = (ways + calc_ways(target-faces[i], faces, dp)) % mod;
        }
    }

    return dp[target] = ways;
}

void solve()
{
    vector<int> faces = {1,2,3,4,5,6};
    int n = faces.size();
    int target;
    cin >> target;
    if(target < 0)
    {
        cout << 0 << "\n";
        return;
    }
    vector<int> dp(target+1, -1);
    int ans = calc_ways(target, faces, dp);
    cout << ans << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("../output/output.txt", "w", stdout);
    #endif

    ll test=1;
    cin >> test;
    
    while(test--)
    {
        solve();
    }

    return 0;
}