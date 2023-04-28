/*
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  You can return the answer in any order.

  Example 1:

	Input: nums = [2,7,11,15], target = 9
	Output: [0,1]
	Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

  Example 2:

	Input: nums = [3,2,4], target = 6
	Output: [1,2]

  Example 3:

	Input: nums = [3,3], target = 6
	Output: [0,1]

  Constraints:

  2 <= nums.length <= 104
  -109 <= nums[i] <= 109
  -109 <= target <= 109

  Only one valid answer exists.

*/

#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
	std::unordered_map<int, int> key_value;
	std::unordered_map<int, int>::const_iterator get;

public:

	Solution() = default;

	std::vector<int> twoSum(std::vector<int>& nums, int target);
};

std::vector<int> Solution::twoSum(std::vector<int>& nums, const int target)
{
	for (int i = 0; i < nums.size(); i++)
	{
		int required_num = target - nums[i];

		get = key_value.find(required_num);

		if (get == key_value.end())
		{
			key_value.insert(std::make_pair(nums[i], i));
		}
		else
		{
			return{ get->second, i };
		}

	}

	return {};
}

// Code for testing
// Should produce result Solution { 0, 1 }

/*
int main ()
{
	std::vector<int> test = { 2, 7, 11, 15 };

	int target = 9;

	Solution test_solution;

	std::vector<int> test_result = test_solution.twoSum(test, target);

	if (test_result.empty())
	{
		std::cout << "Empty array. No solution found.\n";
	}
	else
	{
		std::cout << "Solution: " << "{ " << test_result[0] << ", " << test_result[1] << " }\n";
	}

	return 0;
}
*/