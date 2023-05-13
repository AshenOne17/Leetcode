/*
* Given an array nums of size n, return the majority element.

  The majority element is the element that appears more than ?n / 2? times. 
  You may assume that the majority element always exists in the array.

  -----
  Example 1:

  Input: nums = [3,2,3]
  Output: 3

  -----
  Example 2:

  Input: nums = [2,2,1,1,1,2,2]
  Output: 2
 
  -----
  Constraints:

  n == nums.length

  1 <= n <= 5 * 104

  -109 <= nums[i] <= 109
 
  -----
  Follow-up: Could you solve the problem in linear time and in O(1) space? (Yes :D)
*/

#include <vector>
#include <iostream>

class Solution {
public:
	// Boyer-Moore Majority Voting Algorithm

	int majorityElement(std::vector<int>& nums) {

		int votes = 0, candidate = -1;

		for (int i = 0; i < nums.size(); i++) {
			if (votes == 0) {
				candidate = nums[i];
				votes = 1;
			}
			else if (nums[i] == candidate) {
				votes++;
			}
			else {
				votes--;
			}
		}

		int count = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == candidate) {
				count++;
			}
		}

		if (count > nums.size() / 2) {
			return candidate;
		}
		else {
			return -1;
		}
	}
};

// Code for testing
// Should produce result 2

//int main() {
//
//	Solution test_solution;
//
//	std::vector<int> nums = { 2,2,1,1,1,2,2 };
//
//	std::cout << test_solution.majorityElement(nums);
//
//	return 0;
//}