**Problem Explanation:**

The problem involves finding the sum of Hamming distances between all pairs of integers in a given array. The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

**Explanation:**

The code aims to compute the total Hamming distance between all pairs of the given numbers. It adopts a bitwise approach to construct the total Hamming distance incrementally. By iterating through each bit position of the numbers, starting from the Least Significant Bit (LSB), it calculates the Hamming distance contributed by that bit. For each bit position, it counts the number of numbers with 0 and 1 as the bit value. Then, it considers pairs of numbers where one number has 0 and the other has 1 at that bit position, as these pairs contribute to the total Hamming distance. By multiplying the counts of numbers with 0 and 1 at each bit position, it calculates the total Hamming distance contributed by that bit. This process is repeated for all bit positions, effectively computing the total Hamming distance between all pairs of numbers.

**Pseudocode:**
![Logo](https://github.com/PolisettiVinayKiran/OATCP/blob/main/10.%20MinimumHamming/assets/image.png)

**Bit Manipulation Explanation:**

- **Identifying Bit Optimization:** In this problem, we are interested in finding the Hamming distance between all pairs of integers. Instead of comparing each pair of integers bit by bit, we can optimize the solution using bitwise operations.
  
- **Optimization Technique:** The solution uses bitwise manipulation to iterate through each bit position (0 to 31) and count the number of set bits and unset bits at that position across all integers in the array. By doing so, it efficiently calculates the Hamming distance between all pairs of integers without explicitly comparing each pair.
  
- **How It Works:** For each bit position, we count the number of set bits and unset bits among all integers in the array. The Hamming distance at that bit position is then calculated as the product of the counts of set and unset bits. This process is repeated for all 32 bit positions, and the total Hamming distance is accumulated.

**Input and Output:**

- The code takes input from a file, which contains integers.
- It outputs the sum of Hamming distances between all pairs of integers in the input array.

