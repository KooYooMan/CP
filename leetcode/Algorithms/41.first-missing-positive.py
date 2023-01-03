import unittest
from typing import List


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [1, 2, 0],
                "answer": 3,
            },
            {
                "input": [3, 4, -1, 1],
                "answer": 2,
            },
            {
                "input": [7, 8, 9, 11, 12],
                "answer": 1,
            },
            {
                "input": [1],
                "answer": 2,
            },
            {
                "input": [1, 1],
                "answer": 2,
            },
        ]

        solution = Solution()

        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.first_missing_postitive(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


class Solution:
    def __init__(self):
        pass

    def first_missing_postitive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(0, n):
            if nums[i] == i + 1:
                continue
            if nums[i] <= 0:
                continue
            if nums[i] >= n + 1:
                nums[i] = 0
                continue
            value = nums[i]
            nums[i] = 0
            while True:
                newValue = nums[value - 1]
                nums[value - 1] = value
                if newValue == value:
                    break
                if newValue >= n + 1:
                    break
                if newValue <= 0:
                    break
                value = newValue
        for i in range(0, n):
            if nums[i] <= 0:
                return i + 1
        return n + 1


if __name__ == "__main__":
    unittest.main()
