/*
 Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
 
 -----
 Example 1:
 
 Input: n = 3
 Output: [[1,2,3],[8,9,4],[7,6,5]]

 -----
 Example 2:

 Input: n = 1
 Output: [[1]]

 -----
 Constraints:

 1 <= n <= 20
*/

// The task is similar to problem 54. Spiral Matrix, except for inserting elements into matrix of specific size

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> spiralOrder(int n) {

		std::vector<std::vector<int>> result(n, std::vector<int>(n));

		if (n < 1) {
			return result;
		}

		int row_start = 0, row_end = n - 1;

		int col_start = 0, col_end = n - 1;

		int dir = 0; // 0 - right, 1 - down, 2 - left, 3 - up

		int current_num = 1;

		while (row_start <= row_end && col_start <= col_end) {

			if (dir == 0) {
				// Traverse first row to the right
				for (int i = col_start; i <= col_end; i++) {
					result[row_start][i] = current_num++;
				}

				// Traverse one row down on the top right
				row_start++;
			}
			else if (dir == 1) {

				for (int i = row_start; i <= row_end; i++) {
					result[i][col_end] = current_num++;
				}

				// Traverse from the bottom right element to the bottom left
				col_end--;
			}
			else if (dir == 2) {

				if (row_start <= row_end) {
					for (int i = col_end; i >= col_start; i--) {
						result[row_end][i] = current_num++;
					}

					row_end--;
				}
			}
			else if (dir == 3) {
				// Traverse from the bottom left to the upper element
				if (col_start <= col_end) {
					for (int i = row_end; i >= row_start; i--) {
						result[i][col_start] = current_num++;
					}

					col_start++;
				}
			}

			dir = (dir + 1) % 4;
		}

		return result;
	}
};

// Code for testing
// Should produce result [ 1 2 3 ][ 8 9 4 ][ 7 6 5 ]

/*
int main() {

	Solution test_solution;

	std::vector<std::vector<int>> test_vector = test_solution.spiralOrder(3);

	for (auto vector : test_vector) {
		std::cout << "[ ";
		for (int num : vector) {
			std::cout << num << ' ';
		}
		std::cout << ']';
	}

	return 0;
}
*/
