#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

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
