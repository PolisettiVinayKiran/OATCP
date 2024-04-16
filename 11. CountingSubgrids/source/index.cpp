#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

const int N = 32; // Define the block size. 32 is for Unsigned Int.

int one_count(int num)
{
    int ctr = 0;
    while (num != 0)
    {
        num = num & (num - 1);
        ctr++;
    }
    return ctr;
}

int naive_sol(vector<vector<int>> &grid, int n)
{
    int subgrids = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int count = 0;
            for (int k = 0; k < n; k++)
            {
                if ((grid[i][k] == 1) && (grid[j][k] == 1))
                {
                    count++;
                }
            }
            subgrids += ((count - 1) * count) / 2;
        }
    }
    return subgrids;
}

vector<vector<unsigned int>> preprocess_grid(vector<vector<int>>& grid, int n)
{
    vector<vector<unsigned int>> processed_grid(n, vector<unsigned int>((n / N) + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                processed_grid[i][j / N] |= (1 << (j % N));
            }
        }
    }
    return processed_grid;
}

int count_subgrid(const vector<vector<unsigned int>>& processed_grid, int n)
{
    int subgrids = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            int count = 0;
            for (int k = 0; k < (n / N) + 1; k++)
            {
                count += one_count(processed_grid[a][k] & processed_grid[b][k]);
            }
            subgrids += ((count - 1) * count)/2;
        }
    }
    return subgrids;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("CountingSubgrids_2.txt", "r", stdin);
        freopen("../output/output2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];
        }
    }

    //cout << "Naive Solution - " << naive_sol(grid, n) << "\n";
    
    vector<vector<unsigned int>> processed_grid = preprocess_grid(grid, n);

    int res = count_subgrid(processed_grid, n);
    cout << res << "\n";

    return 0;
}