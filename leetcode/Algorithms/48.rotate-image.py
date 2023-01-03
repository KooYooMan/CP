import unittest
from typing import List


class Solution:
    def __init__(self):
        pass

    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for row in range((n + 1) // 2):
            for col in range(n // 2):
                dx, dy = row, col
                list_cell = [(dx, dy), (dy, n - 1 - dx), (n - 1 - dx, n - 1 - dy), (n - 1 - dy, dx)]
                list_value = []
                for i in range(4):
                    x, y = list_cell[(i + 3) % 4]
                    list_value.append(matrix[x][y])
                for i in range(4):
                    x, y = list_cell[i]
                    matrix[x][y] = list_value[i]


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [[1, 2, 3], [4, 5, 6], [7, 8, 9]],
                "answer": [[7, 4, 1], [8, 5, 2], [9, 6, 3]],
            },
            {
                "input": [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]],
                "answer": [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]],
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = inp
            solution.rotate(output)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
