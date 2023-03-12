import math
import unittest
from typing import List


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        ans = 1
        for i in range(m - 1):
            ans *= (m + n - 2 - i)
            ans /= (i + 1)
        return math.floor(ans + 0.5)


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": {
                    "m": 3,
                    "n": 7,
                },
                "answer": 28,
            },
            {
                "input": {
                    "m": 3,
                    "n": 2,
                },
                "answer": 3,
            },
            {
                "input": {
                    "m": 56,
                    "n": 5,
                },
                "answer": 455126,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            m, n = inp["m"], inp["n"]
            output = solution.uniquePaths(m, n)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
