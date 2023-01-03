import unittest
from typing import List


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": ["eat", "tea", "tan", "ate", "nat", "bat"],
                "answer": [['bat'], ['eat', 'tea', 'ate'], ['tan', 'nat']],
            },
            {
                "input": [""],
                "answer": [[""]],
            },
            {
                "input": ["a"],
                "answer": [["a"]],
            },
        ]

        solution = Solution()

        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.group_anagrams(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


class Solution:
    def __init__(self):
        pass

    def group_anagrams(self, strs: List[str]) -> List[List[str]]:
        candidate = []
        for s in strs:
            s_sorted = ''.join(sorted(s))
            candidate.append((s, s_sorted))

        def get_keys(x):
            return x[1]

        candidate.sort(key=get_keys)
        ans = []
        cur_group = []
        for index, c in enumerate(candidate):
            if index == 0 or (len(cur_group) == 0):
                cur_group.append(c[0])
                continue
            if c[1] == candidate[index - 1][1]:
                cur_group.append(c[0])
            else:
                ans.append(cur_group[:])
                cur_group = [c[0]]
        if len(cur_group) > 0:
            ans.append(cur_group[:])
        return ans


if __name__ == "__main__":
    unittest.main()
