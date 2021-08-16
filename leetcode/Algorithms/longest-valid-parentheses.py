class Solution:
    def __init__(self):
        pass
    
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        dp = [0 for i in range(n + 1)]
        ans = 0
        for i in range(1, n+1):
            if (s[i - 1] == '('):
                continue
            if (s[i - 1] == ')'):
                if i == 1:
                    continue
                if (s[i - 2] == '('):
                    dp[i] = dp[i - 2] + 2
                else:
                    if dp[i - 1] == 0:
                        continue
                    else:
                        pos = i - 2 - dp[i - 1]
                        if pos < 0:
                            continue
                        if s[pos] == '(':
                            dp[i] = dp[i - 1] + 2 + dp[pos]
                ans = max(ans, dp[i])
        return ans

class Testing:
    def __init__(self):
        self.tests = []

    def setTestCheck(self, f):
        self.testCheck = f

    def addTestcase(self, test):
        self.tests.append(test)

    def runTest(self):
        for index, test in enumerate(self.tests):
            self.testCheck(index, test)
        pass

if __name__ == "__main__":
    # inititalize testing and solution
    testing = Testing()
    solution = Solution()

    # Add test here
    test = dict(
        In = "(()",
        Out = 2,
    ) 
    testing.addTestcase(test)

    test = dict(
        In = "",
        Out = 0,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        In = ")()())",
        Out = 4,
    ) 
    testing.addTestcase(test)

    test = dict(
        In = "(()))())(",
        Out = 4,
    ) 
    testing.addTestcase(test)

    test = dict(
        In = "()(())", 
        Out = 6,
    ) 
    testing.addTestcase(test)
 
    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        # Logic test starts here
        
        ans = solution.longestValidParentheses(Input)

        # Logic test ends here
        if ans == Out:
            print(f"Test {idTest}: Correct Answer")
        else:
            print(f"Test {idTest}: Wrong Answer")
            print(f"Expected: {Out}")
            print(f"Actual: {ans}")
        print()

    testing.setTestCheck(testCheck)

    # run testing
    testing.runTest()
