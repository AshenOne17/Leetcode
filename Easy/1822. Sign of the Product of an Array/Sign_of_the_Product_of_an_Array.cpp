/*
 * There is a function arraySign(x) that returns:

   1 if x is positive.
   -1 if x is negative.
   0 if x is equal to 0.
   
   You are given an integer array nums.
   Let product be the product of all values in the array nums.

   Return arraySign(product).


   Example 1:

   Input: nums = [-1,-2,-3,-4,3,2,1]

   Output: 1

   Explanation: The product of all values in the array is 144, and signFunc(144) = 1


   Example 2:

   Input: nums = [1,5,0,2,-3]

   Output: 0

   Explanation: The product of all values in the array is 0, and signFunc(0) = 0


   Example 3:

   Input: nums = [-1,1,-1,1,-1]

   Output: -1

   Explanation: The product of all values in the array is -1, and signFunc(-1) = -1

 
   Constraints:

   1 <= nums.length <= 1000
   
   -100 <= nums[i] <= 100
 */

#include <vector>

class Solution {
public:
	int arraySign(std::vector<int>& nums)
	{
		int sign = 1;

		for (const int& element : nums)
		{
			if (element > 0)
			{
				sign *= 1;
			}
			else if (element == 0)
			{
				return 0;
			}
			else if (element < 0)
			{
				sign *= -1;
			}
		}

		return sign;
	}
};

// Code for testing
// Should produce result 1

/*
int main()
{
	Solution test_solution;

	std::vector<int> test_vector = { -1,-2,-3,-4,3,2,1 };

	std::cout << test_solution.arraySign(test_vector);
}
 */
