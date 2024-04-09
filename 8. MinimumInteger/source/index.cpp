#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

string remove_k_digits(string num, int k)
{
    int n = num.size();
    stack<char> s;
    
    for(char c : num)
    {
        while (!s.empty() && k > 0 && s.top() > c)
        {
            s.pop();
            k -= 1;
        }
        if (!s.empty() || c != '0')
        {
            s.push(c);
        }
    }

    while (!s.empty() && k--)
    {
        s.pop();
    }

    if (s.empty())
    {
        return "0";
    }

    string res(n, '-');
    while (!s.empty())
    {
        res[n - 1] = s.top();
        s.pop();
        n -= 1;
    }

    return res.substr(n);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Minimum_Integer_input_2.txt", "r", stdin);
        freopen("../output/output2.txt", "w", stdout);
    #endif

    int num;
    cin >> num;

    int k;
    cin >> k;

    string res = remove_k_digits(to_string(num), k);

    cout << res << "\n";
}