#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


int get_max_prod(vector<int>& v) 
{
    int n = v.size();
    if(n == 0)
    {
        return 0;
    }
    int maxi = INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi, v[i]);
    }
    ll res = maxi;
    ll cur_min = 1;
    ll cur_max = 1;
    for(int i=0;i<n;i++)
    {
        if(v[i] == 0)
        {
            cur_min = 1;
            cur_max = 1;
        }
        else
        {
            ll temp1 = (cur_max * v[i]) % mod;
            ll temp2 =  (cur_min * v[i]) % mod;
            cur_max = max((ll)v[i], max(temp1, temp2));
            cur_min = min((ll)v[i], min(temp1, temp2));
            res = max(res, cur_max);
        }
    }
    return res;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Max_Prod_SubArray_input_2.txt", "r", stdin);
        freopen("../output/output2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    } 

    ll res = get_max_prod(v);

    cout << res << "\n";
}