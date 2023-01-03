import unittest


class Solution:
    def __init__(self):
        pass

    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        ok = [[False for j in range(n + 1)] for i in range(m + 1)]
        culmulative_or = [[False for j in range(n + 1)] for i in range(m + 1)]
        ok[0][0] = True
        for i in range(0, m + 1):
            culmulative_or[i][0] = True

        for i in range(1, n + 1):
            if p[i - 1] == '*':
                ok[0][i] = True
                culmulative_or[0][i] = True
            else:
                break

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                c_s, c_p = s[i - 1], p[j - 1]
                if c_p == '?':
                    if i > 0:
                        ok[i][j] = ok[i - 1][j - 1]
                elif c_p == '*':
                    ok[i][j] = culmulative_or[i][j - 1]
                elif c_s == c_p:
                    ok[i][j] = ok[i - 1][j - 1]
                culmulative_or[i][j] = culmulative_or[i - 1][j] or ok[i][j]

        return ok[m][n]


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": {
                    "s": "aa",
                    "p": "a",
                },
                "answer": False,
            },
            {
                "input": {
                    "s": "aa",
                    "p": "*",
                },
                "answer": True,
            },
            {
                "input": {
                    "s": "cb",
                    "p": "?a",
                },
                "answer": False,
            }
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            s, p = inp["s"], inp["p"]
            output = solution.isMatch(s, p)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
