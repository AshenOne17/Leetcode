/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  An input string is valid if:

  - Open brackets must be closed by the same type of brackets.
  - Open brackets must be closed in the correct order.
  - Every close bracket has a corresponding open bracket of the same type.
 

  Example 1:

  Input: s = "()"
  Output: true
  
  Example 2:

  Input: s = "()[]{}"
  Output: true
  
  Example 3:

  Input: s = "(]"
  Output: false
 
  Constraints:

  1 <= s.length <= 104
  
  s consists of parentheses only '()[]{}'.
 */

#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
	bool isValid(std::string s)
	{
		std::stack<char> parenthsChecker;

		for (char c : s)
		{
			if (c == '(' || c == '{' || c == '[')
			{
				parenthsChecker.push(c);
			}
			else if (parenthsChecker.empty() ||
				(c == ')' && parenthsChecker.top() != '(') ||
				(c == '}' && parenthsChecker.top() != '{') ||
				(c == ']' && parenthsChecker.top() != '['))
			{
				return false;
			}
			else
			{
				parenthsChecker.pop();
			}
		}

		return parenthsChecker.empty();
	}
};

// Code for testing
// Should produce result true

/*
int main()
{
	std::string test_parent = "()[]{}";

	Solution test_solution;

	std::cout << std::boolalpha << test_solution.isValid(test_parent);

	return 0;
}
 */