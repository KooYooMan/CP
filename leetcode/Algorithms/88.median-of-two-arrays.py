import unittest
from typing import List


class Solution:
    def __init__(self):
        pass

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        a, b = (m + n + 1) // 2, (m + n + 2) // 2
        cur, sum = 0, 0

        while len(nums1) > 0 or len(nums2) > 0:
            value = 0

            if len(nums1) == 0:
                value = nums2[0]
                nums2.pop(0)
            elif len(nums2) == 0:
                value = nums1[0]
                nums1.pop(0)
            else:
                foo, bar = nums1[0], nums2[0]
                value = min(foo, bar)
                if foo < bar:
                    nums1.pop(0)
                else:
                    nums2.pop(0)

            cur += 1
            if cur == a:
                sum += value
            if cur == b:
                sum += value
        return sum / 2


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": {
                    "nums1": [1, 3],
                    "nums2": [2],
                },
                "answer": 2,
            },
            {
                "input": {
                    "nums1": [1, 2],
                    "nums2": [3, 4],
                },
                "answer": 2.5,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            nums1, nums2 = inp["nums1"], inp["nums2"]
            output = solution.findMedianSortedArrays(nums1, nums2)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
