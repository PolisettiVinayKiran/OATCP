## Problem Explanation:

The problem "Bersu Ball" involves finding the maximum number of pairs that can be formed from a group of boys and girls for a ballroom dance. Each boy has a certain dancing skill, as does each girl. However, for a pair to be formed, the difference in dancing skill between the boy and the girl must be at most one.

## Explanation:
- The function `calc_pairs` aims to determine the maximum number of pairs that can be formed from a group of boys and girls for a ballroom dance.
- It sorts the arrays of boys' and girls' dancing skills to facilitate the comparison.
- A 2D dynamic programming array `dp` of size (n x m) is initialized to store the maximum number of pairs for different combinations of boys and girls.
- The function iterates through each boy and girl pair and updates the `dp` array based on certain conditions:
  - If both indexes are greater than 0, it updates `dp[i][j]` with the maximum value from the diagonal element `dp[i-1][j-1]`.
  - If the absolute difference between a boy's and a girl's dancing skills is at most one, it increments `dp[i][j]` by 1 modulo `mod`.
  - If the index `i-1` is valid, it updates `dp[i][j]` with the maximum value from the above element `dp[i-1][j]`.
  - If the index `j-1` is valid, it updates `dp[i][j]` with the maximum value from the left element `dp[i][j-1]`.
- Finally, the function returns `dp[n-1][m-1]`, representing the largest possible number of pairs that can be formed from the given group of boys and girls.
- Memoization is utilized implicitly through the use of the `dp` array, which stores the results of previously solved subproblems.
- By efficiently storing and reusing intermediate results, the dynamic programming approach optimizes the solution by eliminating redundant computations.

## Pseudocode:
![Logo](https://github.com/PolisettiVinayKiran/OATCP/blob/main/DiceProblem/assets/Screenshot%202024-03-12%20183854.png)

## Dynamic Programming (DP) Explanation:

# Overlapping Subproblems: 
In this problem, the overlapping subproblems occur when we try to compute the maximum number of pairs that can be formed considering different combinations of boys and girls. This is because the same subproblem may be encountered multiple times in the recursion tree.

# Optimization:
 Dynamic programming is used to optimize the solution by storing the results of already solved subproblems in the dp array. When a subproblem is encountered again, its result is directly retrieved from the dp array, eliminating the need for redundant computations.

# Identifying Subproblems: 
Each cell dp[i][j] in the dp array represents the maximum number of pairs that can be formed considering the first i boys and the first j girls. By breaking down the problem into smaller subproblems and solving them iteratively, we can build up the solution to the original problem.

## Input and Output:

The code takes input from a file, which contains the number of boys, their dancing skills, the number of girls, and their dancing skills.
It outputs the largest possible number of pairs that can be formed from the given group of boys and girls.