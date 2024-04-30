#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

vector<string> gen_subs(string &str, string current, int index, int n)
{
    vector<string> res;

    if(n == 0)
    {
        res.push_back(current);
        return res;
    }

    if(index == str.length())
    {
        return res;
    }

    vector<string> withCurrent = gen_subs(str, current + str[index], index + 1, n - 1);
    res.insert(res.end(), withCurrent.begin(), withCurrent.end());

    vector<string> withoutCurrent = gen_subs(str, current, index + 1, n);
    res.insert(res.end(), withoutCurrent.begin(), withoutCurrent.end());

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("BriefWords_2.txt", "r", stdin);
        freopen("../output/output2.txt", "w", stdout);
    #endif

    int n;
    set<string> short_forms;

    cin >> n;

    vector<vector<string>> ans;
    for(int i = 0; i < n; i++)
    {
        string word;
        cin >> word;

        vector<string> temp;
        for(int i = 1; i <= 4; ++i)
        {
            vector<string> subsq = gen_subs(word, "", 0, i);
            for(int j = 0; j < subsq.size(); j++)
            {
                if(short_forms.find(subsq[j]) == short_forms.end())
                {
                    temp.push_back(subsq[j]);
                    short_forms.insert(subsq[j]);
                }
            }
        }

        ans.push_back(temp);
    }

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "\n";
        }
        cout << "\n" << "\n";
    }

	return 0;
}
