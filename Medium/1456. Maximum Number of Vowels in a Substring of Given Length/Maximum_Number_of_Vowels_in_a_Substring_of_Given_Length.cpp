/*
* Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

  Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

  -----
  Example 1:

  Input: s = "abciiidef", k = 3
  Output: 3

  Explanation: The substring "iii" contains 3 vowel letters.

  -----
  Example 2:

  Input: s = "aeiou", k = 2
  Output: 2

  Explanation: Any substring of length 2 contains 2 vowels.

  -----
  Example 3:

  Input: s = "leetcode", k = 3
  Output: 2

  Explanation: "lee", "eet" and "ode" contain 2 vowels.
 
  -----
  Constraints:

  1 <= s.length <= 105

  s consists of lowercase English letters.

  1 <= k <= s.length
*/

#include <string>

class Solution {
public:
	int maxVowels(std::string s, int k) {
		int len = s.length();
		if (len < k) {
			return -1;
		}

		int current_len = 0, maximum_len = 0;

		for (int i = 0; i < k; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				current_len++;
			}
		}
		maximum_len = current_len;

		for (int i = k; i < len; i++) {
			if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
				current_len--;
			}
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				current_len++;
			}
			maximum_len = std::max(maximum_len, current_len);
		}

		return maximum_len;
	}
};

// Code for testing
// Should produce result 4

/*
int main() {

	Solution test_solution;

	std::string test_string = "weallloveyou";

	int test_k = 7;

	std::cout << test_solution.maxVowels(test_string, test_k);

	return 0;
}
*/