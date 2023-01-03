import unittest


class Solution:
    def __init__(self):
        pass

    def fast_check_match(self, s: str, p: str) -> bool:
        if len(s) != len(p):
            print(f"FastCheckMatch Error: two strings {s} {p} didn't have equal length")
            return False
        for i in range(len(s)):
            if p[i] == '.' or s[i] == p[i]:
                continue
            return False
        return True

    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        ans = [[False for _ in range(n + 1)] for _ in range(m + 1)]
        ans[0][0] = True
        for i in range(0, m + 1):
            c_s = s[i - 1]
            for j in range(1, n + 1):
                c_p = p[j - 1]
                if c_p != '*':
                    if c_p == '.' or c_s == c_p:
                        ans[i][j] = ans[i - 1][j - 1]
                    else:
                        ans[i][j] = False
                    continue
                # TODO: Processing if c_p == '*'
                if j == 1:
                    print("Error character * doesn't have any previous character matched with it")
                    return False
                elif p[j - 2] == '*':
                    print("Error: Why 2 character * in a row")
                else:
                    previous = p[j - 2]
                    form = ""
                    for k in range(i + 1):
                        target = s[i - k: i]
                        if not self.fast_check_match(target, form):
                            break
                        ans[i][j] = ans[i - k][j - 2] or ans[i][j]
                        form += previous
        return ans[m][n]


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
                    "p": "a*",
                },
                "answer": True,
            },
            {
                "input": {
                    "s": "ab",
                    "p": ".*"
                },
                "answer": True,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            s, p = inp["s"], inp["p"]
            output = solution.isMatch(s, p)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
