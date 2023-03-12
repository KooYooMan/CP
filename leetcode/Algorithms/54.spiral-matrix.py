import unittest
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
            return []

        n = len(matrix[0])

        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        is_checked = [[False]*n for i in range(m)]
        ans = []

        x, y, direction = 0, 0, 0

        while True:
            is_checked[x][y] = True
            ans.append(matrix[x][y])

            found = False
            for i in range(4):
                new_x, new_y = x + dx[direction], y + dy[direction]
                if new_x < 0 or new_x >= m:
                    direction = (direction + 1) % 4
                    continue
                if new_y < 0 or new_y >= n:
                    direction = (direction + 1) % 4
                    continue
                if is_checked[new_x][new_y]:
                    direction = (direction + 1) % 4
                    continue
                found = True
                x, y = new_x, new_y
                break

            if not found:
                break

        return ans


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [[1, 2, 3], [4, 5, 6], [7, 8, 9]],
                "answer": [1, 2, 3, 6, 9, 8, 7, 4, 5],
            },
            {
                "input": [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]],
                "answer": [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7],
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.spiralOrder(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
