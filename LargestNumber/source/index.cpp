#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

bool custom_comparator(string str1, string str2)
{
    string temp1 = str1 + str2;
    string temp2 = str2 + str1;
    return (temp1 > temp2);
}

string generate_largest_number(vector<int> &nums)
{
    vector<string> stringified_nums;
    for(int i=0;i<nums.size();i++)
    {
        stringified_nums.push_back(to_string(nums[i]));
    }

    sort(stringified_nums.begin(), stringified_nums.end(), custom_comparator);

    if (stringified_nums[0] == "0")
    {
        return "0";
    }
    string res = "";
    for(int i=0;i<stringified_nums.size();i++)
    {
        res += stringified_nums[i];
    }
    return res;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Largest_Number_2.txt", "r", stdin);
        freopen("../output/output2.txt", "w", stdout);
    #endif
    
    vector<int> nums;
    int num;
    while(cin >> num) 
    {
        nums.push_back(num);
    }

    string res = generate_largest_number(nums);

    cout << res << "\n";
}