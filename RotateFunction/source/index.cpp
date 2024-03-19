#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


int get_rotate_max(vector<int>& arr, int n) 
{
    ll total_sum = 0;
    ll prev = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum = (total_sum + arr[i]) % mod;
        prev = (prev + (i * arr[i])) % mod;
    }
    ll res = INT_MIN;
    res = max(res, prev);
    for (int k = n - 1; k >= 0; k--)
    {
        ll temp = (((prev + total_sum) % mod) - ((n * arr[k]) % mod)) % mod;
        res = max(res, temp);
        prev = temp;
    }
    return res;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Rotate_Function_input_3.txt", "r", stdin);
        freopen("../output/output3.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    } 

    ll res = get_rotate_max(arr, n);

    cout << res << "\n";
}