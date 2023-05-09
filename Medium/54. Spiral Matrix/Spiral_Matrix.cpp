/*
* Given an m x n matrix, return all elements of the matrix in spiral order.

  -----
  Example 1:

  Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
  Output: [1,2,3,6,9,8,7,4,5]

  -----
  Example 2:
  Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
  Output: [1,2,3,4,8,12,11,10,9,5,6,7]

  -----
  Constraints:

  m == matrix.length

  n == matrix[i].length

  1 <= m, n <= 10

  -100 <= matrix[i][j] <= 100
*/

#include <vector>

class Solution {
public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {

		std::vector<int> result;

		if (matrix.empty()) {
			return result;
		}

		int row_start = 0, row_end = matrix.size() - 1;

		int col_start = 0, col_end = matrix[0].size() - 1;

		int dir = 0; // 0 - right, 1 - down, 2 - left, 3 - up

		while (row_start <= row_end && col_start <= col_end) {

			if (dir == 0) {
				// Traverse first row to the right
				for (int i = col_start; i <= col_end; i++) {
					result.push_back(matrix[row_start][i]);
				}

				// Traverse one row down on the top right
				row_start++;
			}
			else if (dir == 1) {

				for (int i = row_start; i <= row_end; i++) {
					result.push_back(matrix[i][col_end]);
				}

				// Traverse from the bottom right element to the bottom left
				col_end--;
			}
			else if (dir == 2) {

				if (row_start <= row_end) {
					for (int i = col_end; i >= col_start; i--) {
						result.push_back(matrix[row_end][i]);
					}

					row_end--;
				}
			}
			else if (dir == 3) {
				// Traverse from the bottom left to the upper element
				if (col_start <= col_end) {
					for (int i = row_end; i >= row_start; i--) {
						result.push_back(matrix[i][col_start]);
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
// Should produce result 1,2,3,6,9,8,7,4,5

/*
int main() {

	Solution test_solution;

	std::vector<std::vector<int>> test_array = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};

	std::vector<int> result_array = test_solution.spiralOrder(test_array);

	for (int i : result_array) {
		std::cout << i << ' ';
	}

	return 0;
}
*/