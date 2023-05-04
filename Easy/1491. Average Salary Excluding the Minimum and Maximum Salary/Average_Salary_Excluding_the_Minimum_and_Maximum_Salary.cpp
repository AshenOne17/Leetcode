/*
 * You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

  Return the average salary of employees excluding the minimum and maximum salary.
  Answers within 10-5 of the actual answer will be accepted.

  Example 1:

  Input: salary = [4000,3000,1000,2000]
  
  Output: 2500.00000
  
  Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
  
  Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
  
  Example 2:

  Input: salary = [1000,2000,3000]

  Output: 2000.00000

  Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.

  Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 

  Constraints:

  3 <= salary.length <= 100
  
  1000 <= salary[i] <= 106
  
  All the integers of salary are unique.
 */

#include <vector>

class Solution {
public:
	double average(std::vector<int>& salary)
	{
		int min_salary = salary[0], max_salary = salary.back();

		for (const int element : salary)
		{
			if (min_salary > element)
			{
				min_salary = element;
			}

			if (max_salary < element)
			{
				max_salary = element;
			}
		}

		double elements_sum = 0.0;

		int number_of_salaries = 0;

		for (const int element : salary)
		{
			if (element != min_salary && element != max_salary)
			{
				elements_sum += element;
				number_of_salaries++;
			}
		}

		return elements_sum / number_of_salaries;
	}
};

// Code for testing
// Should produce result 2500

/*
int main()
{
	Solution test_solution;

	std::vector<int> salary_test = { 4000,3000,1000,2000 };

	std::cout << test_solution.average(salary_test);
}
 */