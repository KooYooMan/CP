import unittest
from typing import List


class Solution:
    def __init__(self):
        pass

    def trap(self, height: List[int]) -> int:
        stack = []
        ans = 0
        for index, curHeight in enumerate(height):
            if len(stack) == 0:
                stack.append((curHeight, index))
                continue
            myIndex = index
            while len(stack) != 0:
                lastHeight, lastIndex = stack[len(stack) - 1]
                if lastHeight <= curHeight:
                    stack.pop()
                    if len(stack) > 0:
                        previousHeight, previousIndex = stack[len(stack) - 1]
                        ans += (myIndex - lastIndex) * (min(previousHeight, curHeight) - lastHeight)
                        if previousHeight > curHeight:
                            myIndex = lastIndex
                    else:
                        stack.append((curHeight, 0))
                        break
                else:
                    stack.append((curHeight, myIndex))
                    break
        return ans


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1],
                "answer": 6,
            },
            {
                "input": [4, 2, 0, 3, 2, 5],
                "answer": 9,
            }
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.trap(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
