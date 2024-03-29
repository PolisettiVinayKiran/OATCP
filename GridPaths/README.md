## Explanation:

This problem asks to calculate the number of paths from the upper-left square to the lower-right square in an n x n grid, where each square may or may not have traps. It is not allowed to move to a square with a trap. You can only move right or down.

The function calc_ways recursively calculates the number of paths from the upper-left square to the current square (i, j) while avoiding squares with traps.
It initializes a dynamic programming array dp to store the number of paths to reach each square.
The base case of the recursion is when the current square is the upper-left square (0, 0), in which case there is one path.
If the current square is out of bounds or contains a trap, it returns 0.
If the number of paths to reach the current square (i, j) has already been calculated, it returns the value from dp[i][j].
Otherwise, it recursively calculates the number of paths by summing up the number of paths from the square above (i-1, j) and from the square to the left (i, j-1).
Memoization is used to optimize the recursive solution by storing and reusing intermediate results.

## Pseudocode:
![Logo](https://github.com/PolisettiVinayKiran/OATCP/blob/main/GridPaths/assets/Screenshot%202024-03-12%20183950.png)


This program takes input for the size of an n x n grid and the configuration of the grid where each square may or may not contain a trap. It calculates the number of paths from the upper-left square to the lower-right square while avoiding squares with traps. It then outputs the total number of paths, and this process is repeated for each test case.