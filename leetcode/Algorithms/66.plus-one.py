import math
import unittest
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        reversed_digits = digits[::-1]
        ans = []
        added = True
        for digit in reversed_digits:
            if digit == 9 and added:
                ans.append(0)
                added = True
            elif added:
                ans.append(digit + 1)
                added = False
            else:
                ans.append(digit)

        if added:
            ans.append(1)

        return ans[::-1]


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [1, 2, 3],
                "answer": [1, 2, 4],
            },
            {
                "input": [4, 3, 2, 1],
                "answer": [4, 3, 2, 2],
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.plusOne(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
