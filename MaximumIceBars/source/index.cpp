#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int get_max_icebars(vector<int> costs, int coins, int n)
{
    int count = 0;
    sort(costs.begin(), costs.end());
    for(int i=0;i<n;i++)
    {
        if (costs[i] <= coins)
        {
            coins -= costs[i];
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Maximum_Ice_Bars_3.txt", "r", stdin);
        freopen("../output/output3.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    
    vector<int> costs(n);
    for(int i=0;i<n;i++)
    {
        cin >> costs[i];
    } 

    int coins;
    cin >> coins;

    ll res = get_max_icebars(costs, coins, n);

    cout << res << "\n";
}