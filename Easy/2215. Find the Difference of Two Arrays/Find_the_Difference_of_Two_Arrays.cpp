/*
* Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

  answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
  answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

  Note that the integers in the lists may be returned in any order.

  -----
  Example 1:

  Input: nums1 = [1,2,3], nums2 = [2,4,6]

  Output: [[1,3],[4,6]]

  Explanation:

  For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. 
  Therefore, answer[0] = [1,3].

  For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. 
  Therefore, answer[1] = [4,6].
  
  -----
  Example 2:

  Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]

  Output: [[3],[]]

  Explanation:

  For nums1, nums1[2] and nums1[3] are not present in nums2. 
  Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].

  Every integer in nums2 is present in nums1. 
  Therefore, answer[1] = [].
 
  -----
  Constraints:

  1 <= nums1.length, nums2.length <= 1000

  -1000 <= nums1[i], nums2[i] <= 1000
*/

#include <vector>
#include <unordered_set>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {

		std::vector<std::vector<int>> result(2);
		std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
		std::unordered_set<int> nums2_set(nums2.begin(), nums2.end());

		// Find numbers in nums1 that are not in nums2
		for (int num : nums1_set) {
			if (nums2_set.find(num) == nums2_set.end()) {
				result[0].push_back(num);
			}
		}

		// Find numbers in nums2 that are not in nums1
		for (int num : nums2_set) {
			if (nums1_set.find(num) == nums1_set.end()) {
				result[1].push_back(num);
			}
		}

		return result;
	}
};

// Code for testing
// Should produce result { 1, 3, }; { 4, 6, } 

/*
* int main()
{
	Solution test_solution;

	std::vector<int> a = { 1, 2, 3 }, b = { 2, 4, 6 };

	const std::vector<std::vector<int>> test_result = test_solution.findDifference(a, b);

	for (const auto& i : test_result)
	{
		std::cout << "{ ";

		for (const int number : i)
		{
			std::cout << number << ", ";
		}

		std::cout << " }; ";
	}
}
*/
