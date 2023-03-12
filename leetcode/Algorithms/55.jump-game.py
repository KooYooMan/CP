import unittest
from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxmimum_reachable_index = 0
        n = len(nums)
        for i in range(n):
            if i > maxmimum_reachable_index:
                break
            maxmimum_reachable_index = max(maxmimum_reachable_index, i + nums[i])

        return maxmimum_reachable_index >= n - 1

class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [2,3,1,1,4],
                "answer": True,
            },
            {
                "input": [3,2,1,0,4],
                "answer": False,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.canJump(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
