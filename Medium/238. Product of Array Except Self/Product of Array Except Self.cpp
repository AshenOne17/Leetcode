/*
* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

  You must write an algorithm that runs in O(n) time and without using the division operation.

  -----
  Example 1:

  Input: nums = [1,2,3,4]
  Output: [24,12,8,6]

  -----
  Example 2:

  Input: nums = [-1,1,0,-3,3]
  Output: [0,0,9,0,0]
 
  -----
  Constraints:

  2 <= nums.length <= 105

  -30 <= nums[i] <= 30

  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {

        int n = nums.size();

        std::vector<int> prefixProduct(n, 1);
        std::vector<int> suffixProduct(n, 1);
        std::vector<int> result(n, 1);

        // Calculate prefix product
        for (int i = 1; i < n; ++i) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }

        // Calculate suffix product
        for (int i = n - 2; i >= 0; --i) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }

        // Calculate result by multiplying prefix and suffix products
        for (int i = 0; i < n; ++i) {
            result[i] = prefixProduct[i] * suffixProduct[i];
        }

        return result;
    }
};

// Code for testing
// Should produce result 24 12 8 6

/*
int main() {

    Solution test_solution;

    std::vector<int> test_nums = { 1, 2, 3, 4 };

    std::vector<int> test_result = test_solution.productExceptSelf(test_nums);

    for (int num : test_result) {
        std::cout << num << ' ';
    }

    return 0;
}
*/
