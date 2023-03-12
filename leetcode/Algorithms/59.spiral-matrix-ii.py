import unittest
from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        is_checked = [[False] * n for _ in range(n)]
        ans = [[0] * n for _ in range(n)]

        x, y, direction, count = 0, 0, 0, 0

        while True:
            is_checked[x][y] = True
            count += 1
            ans[x][y] = count

            found = False
            for i in range(4):
                new_x, new_y = x + dx[direction], y + dy[direction]
                if new_x < 0 or new_x >= n:
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
                "input": 3,
                "answer": [[1, 2, 3], [8, 9, 4], [7, 6, 5]],
            },
            {
                "input": 1,
                "answer": [[1]],
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.generateMatrix(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
