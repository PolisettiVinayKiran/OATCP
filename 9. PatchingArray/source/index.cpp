#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int min_patches(vector<int> &nums, int n)
{
    int num_patches = 0, i = 0;
    ll cur_max = 1;
    while(cur_max <= n)
    {
        if(i < nums.size() && nums[i] <= cur_max)
        {
            cur_max += nums[i];
            i++;
        }
        else
        {
            cur_max *= 2;
            num_patches++;
        }
    }
    return num_patches;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Patching_Array_input_1.txt", "r", stdin);
        freopen("../output/output1.txt", "w", stdout);
    #endif
    
    vector<int> nums;
    int num;
    while(cin >> num) 
    {
        nums.push_back(num);
    }
    nums.pop_back();

    int n = num;

    ll res = min_patches(nums, n);

    cout << res << "\n";
}