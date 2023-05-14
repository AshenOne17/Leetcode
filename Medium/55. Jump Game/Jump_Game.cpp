/*
* You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

  Return true if you can reach the last index, or false otherwise.

  -----
  Example 1:

  Input: nums = [2,3,1,1,4]
  Output: true

  Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

  -----
  Example 2:

  Input: nums = [3,2,1,0,4]
  Output: false

  Explanation: You will always arrive at index 3 no matter what. 
  Its maximum jump length is 0, which makes it impossible to reach the last index.
 
  -----
  Constraints:

  1 <= nums.length <= 104

  0 <= nums[i] <= 105
*/

#include <vector>
#include <iostream>

/*
* The basic idea behind this code is to keep track of the farthest reachable index from the current index and update it as we iterate through the array. 
  We start from the first index and initialize the farthest reachable index as the value at that index plus the index itself (i.e., i + nums[i]).

  Then, for each subsequent index, we check if it is reachable from the previous farthest index. 
  If it is, we update the farthest reachable index to the maximum of its current value and the value at the current index plus the index itself. 
  If it's not reachable from the previous farthest index, that means there is a gap in the array that cannot be jumped over, so we return false.

  Finally, if we have iterated through the entire array without returning false, that means we can jump to the end of the array and we return true.
*/

class Solution {
public:
    bool canJump(std::vector<int>& nums) {

        int n = nums.size();

        int last_good_index = n - 1;

        for (int i = n - 2; i >= 0; i--) {

            if (i + nums[i] >= last_good_index) {
                last_good_index = i;
            }

        }

        return last_good_index == 0;
    }
};

// Code for testing
// Should produce result true

/*
int main() {

    Solution test_solution;

    std::vector<int> test_nums = { 2, 5, 0, 0 };

    std::cout << std::boolalpha << test_solution.canJump(test_nums);

    return 0;
}
*/
