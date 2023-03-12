import math
import unittest
from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0] * n for _ in range(m)]
        dx = [0, -1]
        dy = [-1, 0]

        for u in range(m):
            for v in range(n):
                if obstacleGrid[u][v] == 1:
                    continue
                if u == 0 and v == 0:
                    dp[u][v] = 1
                    continue
                for direction in range(2):
                    prev_u, prev_v = u + dx[direction], v + dy[direction]
                    if prev_u < 0 or prev_v < 0:
                        continue
                    dp[u][v] += dp[prev_u][prev_v]

        return dp[m - 1][n - 1]


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [[0, 0, 0], [0, 1, 0], [0, 0, 0]],
                "answer": 2,
            },
            {
                "input": [[0, 1], [0, 0]],
                "answer": 1,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.uniquePathsWithObstacles(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
