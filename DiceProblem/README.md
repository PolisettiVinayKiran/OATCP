
The given problem asks to count the number of ways to construct a sum 'n' by throwing a dice one or more times, where each throw produces an outcome between 1 and 6.

## Explanation:

The function calc_ways recursively calculates the number of ways to reach the target sum 'target' using the given faces of the dice.
It initializes a dynamic programming array dp to store the number of ways to reach each target sum.
The base case of the recursion is when the target sum becomes 0, in which case there is one way to reach it (by not throwing the dice at all).
For each face of the dice, it recursively calculates the number of ways to reach the remaining sum after subtracting the current face value from the target sum.
The total number of ways to reach the target sum is then calculated by summing up the number of ways obtained from each face.
Memoization is used to optimize the recursive solution by storing and reusing intermediate results.

## Pseudocode:
![Logo]()

        
This code takes input for the target sum 'n' and calculates the number of ways to construct the sum using the given dice. It then outputs the result, and this process is repeated for each test case.