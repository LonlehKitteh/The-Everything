# Problem: 264. Ugly Number II

An **ugly number** is a positive integer whose prime factors are limited to **2, 3, and 5**.

Given an integer `n`, return the **nth ugly number**.

## Example 1

**Input**: n = 10  
**Output**: 12  
**Explanation**: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

## Example 2

**Input**: n = 1  
**Output**: 1  
**Explanation**: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

## Constraints

- 1 <= n <= 1690

## Solution Explanation

To solve this problem, we use a **dynamic programming** approach with three pointers to keep track of the multiples of 2, 3, and 5.

### Key Concepts

1. **Three Pointers**:

   - `i2`, `i3`, `i5`: These pointers track the positions in the sequence of ugly numbers that are currently being multiplied by 2, 3, and 5, respectively.

2. **Dynamic Programming Array (`arr`)**:

   - This array stores the first `n` ugly numbers. The first ugly number is always 1.

3. **Main Logic**:
   - For each iteration, we calculate the next ugly number by taking the minimum of `arr[i2] * 2`, `arr[i3] * 3`, and `arr[i5] * 5`.
   - After determining the next ugly number, we increment the corresponding pointer(s) to move forward in the sequence.

### Code

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        // Array to store the first 'n' ugly numbers
        std::vector<int> arr(n + 1);
        arr[1] = 1;  // The first ugly number is always 1

        // Pointers for multiples of 2, 3, and 5
        int i2 = 1, i3 = 1, i5 = 1;

        // Generate ugly numbers from 2 to n
        for (int i = 2; i <= n; ++i) {
            // Calculate the next potential ugly numbers
            int nextUgly2 = arr[i2] * 2;
            int nextUgly3 = arr[i3] * 3;
            int nextUgly5 = arr[i5] * 5;

            // Find the smallest ugly number among them
            int nextUgly = std::min(nextUgly2, std::min(nextUgly3, nextUgly5));

            // Store the smallest ugly number
            arr[i] = nextUgly;

            // Move the corresponding pointer(s)
            if (nextUgly == nextUgly2) i2++;
            if (nextUgly == nextUgly3) i3++;
            if (nextUgly == nextUgly5) i5++;
        }

        // Return the nth ugly number
        return arr[n];
    }
};
```

## Time complexity: `O(n logn)`

- The operations on the priority queue (`push` and `pop`) take logarithmic time, and there are `n` such operations.

## Space Complexity: `O(m)`

- The space is used by the heap and the set, which store up to `m` elements as it depends on the number of unique ugly numbers stored in the set.
