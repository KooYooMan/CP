import unittest
from typing import List


class Solution:
    def __init__(self):
        pass

    def backtrack(self, built: List[int], candidate: List[int], result: List[List[int]]) -> None:
        if len(candidate) == 0:
            newResult = []
            for element in built:
                newResult.append(element)
            result.append(newResult)
            return
        for index, value in enumerate(candidate):
            if index > 0 and candidate[index - 1] == candidate[index]:
                continue
            built.append(value)
            candidate.pop(index)
            self.backtrack(built, candidate, result)
            built.pop()
            candidate.insert(index, value)

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        built = []
        ans = []
        self.backtrack(built, nums, ans)
        return ans


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [1, 1, 2],
                "answer": [[1, 1, 2], [1, 2, 1], [2, 1, 1]],
            },
            {
                "input": [1, 2, 3],
                "answer": [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]],
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.permuteUnique(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
