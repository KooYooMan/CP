import math
import unittest
from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        dx = [0, -1]
        dy = [-1, 0]

        for u in range(m):
            for v in range(n):
                if u == 0 and v == 0:
                    dp[u][v] = grid[u][v]
                    continue
                for direction in range(2):
                    prev_u, prev_v = u + dx[direction], v + dy[direction]
                    if prev_u < 0 or prev_v < 0:
                        continue
                    value = dp[prev_u][prev_v] + grid[u][v]
                    if dp[u][v] == 0:
                        dp[u][v] = value
                    else:
                        dp[u][v] = min(dp[u][v], value)

        return dp[m - 1][n - 1]


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [[1, 3, 1], [1, 5, 1], [4, 2, 1]],
                "answer": 7,
            },
            {
                "input": [[1, 2, 3], [4, 5, 6]],
                "answer": 12,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.minPathSum(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
