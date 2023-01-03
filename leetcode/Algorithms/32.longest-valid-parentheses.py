import unittest


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": "(()",
                "answer": 2,
            },
            {
                "input": ")()())",
                "answer": 4,
            },
            {
                "input": "",
                "answer": 0,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            output = solution.longestValidParentheses(inp)
            self.assertEqual(output, answer, f"test fail with input {inp}")


class Solution:
    def __init__(self):
        pass
    
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        dp = [0 for i in range(n+1)]
        ans = 0
        for i in range(1, n+1):
            if s[i-1] == '(':
                continue
            if s[i-1] == ')':
                if i == 1:
                    continue
                if s[i-2] == '(':
                    dp[i] = dp[i-2] + 2
                else:
                    if dp[i-1] == 0:
                        continue
                    else:
                        pos = i - 2 - dp[i-1]
                        if pos < 0:
                            continue
                        if s[pos] == '(':
                            dp[i] = dp[i-1] + 2 + dp[pos]
                ans = max(ans, dp[i])
        return ans


if __name__ == "__main__":
    unittest.main()
