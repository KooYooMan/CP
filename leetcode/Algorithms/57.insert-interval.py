import unittest
from typing import List


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        new_str = s.split(" ")
        for str in reversed(new_str):
            if len(str) != 0:
                return len(str)


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": "Hello World",
                "answer": 5,
            },
            {
                "input": "   fly me   to   the moon  ",
                "answer": 4,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.lengthOfLastWord(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
