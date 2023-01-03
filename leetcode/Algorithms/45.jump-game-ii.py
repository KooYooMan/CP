import unittest
from typing import List


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [2, 3, 1, 1, 4],
                "answer": 2,
            },
            {
                "input": [2, 3, 0, 1, 4],
                "answer": 2,
            }
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.jump(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


class Solution:
    def __init__(self):
        pass

    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [n + 1 for i in range(n)]
        dp[0] = 0
        for index, num in enumerate(nums):
            for i in range(1, num + 1):
                if index + i >= n:
                    break
                dp[index + i] = min(dp[index + i], dp[index] + 1)
        return dp[n - 1]


if __name__ == "__main__":
    unittest.main()
