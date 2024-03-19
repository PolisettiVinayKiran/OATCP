**Problem Explanation:**

The problem "Maximum Product Subarray" involves finding the maximum product that can be obtained from contiguous subarrays of a given array. 


**Explanation**

- The function `get_max_prod` calculates the maximum product of subarrays from the given array `v`.
- It initializes a variable `maxi` to negative infinity to store the maximum element encountered in the array.
- It then iterates through the array to find the maximum element and stores it in `maxi`.
- After finding the maximum element, it initializes variables `cur_min` and `cur_max` to 1.
- It iterates through the array again, updating `cur_min` and `cur_max` based on the current element and the minimum and maximum products computed so far.
- If the current element is 0, it resets `cur_min` and `cur_max` to 1, as the product of any subarray containing 0 would be 0.
- Finally, it returns the maximum product obtained from the subarrays.

**Pseudocode:**
![Logo](https://github.com/PolisettiVinayKiran/OATCP/blob/main/MaximumProductSubarray/assets/Screenshot%202024-03-19%20164648.png)


**Dynamic Programming (DP) Explanation:**

- **Overlapping Subproblems:** In this problem, the overlapping subproblems occur because the maximum product of subarrays ending at each index is used to compute the maximum product of subarrays ending at the next index.
  
- **Optimization:** Dynamic programming is used to optimize the solution by maintaining two variables `cur_min` and `cur_max`, which represent the minimum and maximum product of subarrays ending at the current index. These variables are updated based on the current element of the array and the minimum and maximum products computed so far.
  
- **Identifying Subproblems:** Each element of the input array is considered in turn, and the maximum product of subarrays ending at each index is computed. By breaking down the problem into smaller subproblems and solving them iteratively, we can build up the solution to the original problem.

**Input and Output:**

- The code takes input from a file, which contains the size of the array and the elements of the array.
- It outputs the maximum product of subarrays that can be obtained from the given array.

