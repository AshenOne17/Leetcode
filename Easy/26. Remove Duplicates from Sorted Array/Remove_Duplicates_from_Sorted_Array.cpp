/*
* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
  The relative order of the elements should be kept the same. 
  Then return the number of unique elements in nums.

  Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

  1) Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
  The remaining elements of nums are not important as well as the size of nums.

  2) Return k.

  -----
  Custom Judge:

  The judge will test your solution with the following code:

  int[] nums = [...]; // Input array
  int[] expectedNums = [...]; // The expected answer with correct length

  int k = removeDuplicates(nums); // Calls your implementation

  assert k == expectedNums.length;
  for (int i = 0; i < k; i++) {
      assert nums[i] == expectedNums[i];
  }

  If all assertions pass, then your solution will be accepted.
  -----
 
  -----
  Example 1:

  Input: nums = [1,1,2]
  Output: 2, nums = [1,2,_]

  Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
  It does not matter what you leave beyond the returned k (hence they are underscores).

  -----
  Example 2:

  Input: nums = [0,0,1,1,1,2,2,3,3,4]
  Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

  Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
  It does not matter what you leave beyond the returned k (hence they are underscores).
 
  -----
  Constraints:

  1 <= nums.length <= 3 * 104

  -100 <= nums[i] <= 100

  nums is sorted in non-decreasing order.
*/

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

// This solution is more time efficient in case we have an efficient hash function
// For ints this solution is better (The standard library provides a default hash which is simply the identity function).

class Solution {
public:
    int removeElement(std::vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        std::unordered_set<int> nums_set;

        for (int i : nums) {
            nums_set.insert(i);
        }

        nums.assign(nums_set.begin(), nums_set.end());

        std::sort(nums.begin(), nums.end());

        return nums.size();
    }
};

// Otherwise, this solution with simple vector sort and unique is more efficient (in terms of time complexity)

/*
class Solution {
public:

    int removeDuplicates(std::vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        return nums.size();
    }
};
*/

// Alternative easy solution with two-pointers approach

/*
class Solution {
public:

    int removeDuplicates(std::vector<int>& nums) {
        
        if (nums.empty()) {
            return 0;
        }

        int slow = 0;

        for (int fast = 1; fast < nums.size(); fast++){
            if (nums[slow] != nums[fast]){
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};
*/

// Code for testing
// Should produce result 5 

//int main() {
//
//    Solution test_solution;
//
//    std::vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
//
//    std::cout << test_solution.removeElement(nums);
//
//    return 0;
//}
