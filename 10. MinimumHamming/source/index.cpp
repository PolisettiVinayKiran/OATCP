#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


int min_hamming(vector<int>& nums)
{
    int dist = 0;
    int n = nums.size();

    for (int i = 0; i < 32; i++)
    {
        int num_set = 0, num_unset = 0;

        for (auto num : nums)
        {
            if (num & (1 << i))
            {
                num_set++;
            }
        }

        num_unset = n - num_set;
        dist += (num_set * num_unset);
    }

    return dist;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("HammingDistance_2.txt", "r", stdin);
        freopen("../output/output2.txt", "w", stdout);
    #endif

    vector<int> nums;
    int num;
    while(cin >> num) 
    {
        nums.push_back(num);
    }

    int res = min_hamming(nums);

    cout << res << "\n";
}