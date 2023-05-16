/*
* Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

  According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

  -----
  Example 1:

  Input: citations = [3,0,6,1,5]
  Output: 3

  Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
  Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

  -----
  Example 2:

  Input: citations = [1,3,1]
  Output: 1
 
  -----
  Constraints:

  n == citations.length

  1 <= n <= 5000

  0 <= citations[i] <= 1000
*/

#include <vector>
#include <algorithm>

// This approach is better for n > 1000, since it provides algorithm with O(n * log n) complexity

class Solution {
public:
    int hIndex(std::vector<int>& citations) {

        std::sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });

        int h_index = 0, pub_num = 0;

        for (int citation : citations) {

            if (citation > 0 && citation > pub_num) {
                h_index++;
                pub_num++;
            }

        }

        return h_index;
    }
};

// This solution is better specifically for the leetcode, since we are limited to n = 1000, which 
// give the possibility to make a code in a linear time O(n), instead of O(n * log n) in the approach above

/*
class Solution {
public:
    int hIndex(std::vector<int>& citations) {

        const int n = citations.size();

        std::vector<int> counts(n + 1, 0);

        // Count the number of papers for each citation count
        for (int citation : citations) {

            if (citation >= n)
                counts[n]++;
            else
                counts[citation]++;
        }

        int h_index = 0, papers = 0;

        // Traverse the counts array from right to left
        for (int i = n; i >= 0; i--) {

            papers += counts[i];  // Accumulate the number of papers

            // Check if the current h-index condition is satisfied
            if (papers >= i) {

                h_index = i;
                break;
            }
        }

        return h_index;
    }
};
*/

// Code for testing
// Should produce the result 3

/*
int main() {

    Solution test_solution;

    std::vector<int> test_citations = { 3, 0, 6, 1, 5 };

    std::cout << test_solution.hIndex(test_citations);

    return 0;
}
*/
