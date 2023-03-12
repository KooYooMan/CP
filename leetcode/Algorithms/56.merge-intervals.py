import unittest
from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        sorted_intervals = sorted(intervals)
        ans = []
        cur_min, cur_max = sorted_intervals[0][0], sorted_intervals[0][1]
        for interval in sorted_intervals:
            left, right = interval[0], interval[1]
            if left > cur_max:
                ans.append([cur_min, cur_max])
                cur_min, cur_max = left, right
            else:
                cur_max = max(right, cur_max)
        ans.append([cur_min, cur_max])
        return ans


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [[1, 3], [2, 6], [8, 10], [15, 18]],
                "answer": [[1, 6], [8, 10], [15, 18]],
            },
            {
                "input": [[1, 4], [4, 5]],
                "answer": [[1, 5]],
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.merge(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
