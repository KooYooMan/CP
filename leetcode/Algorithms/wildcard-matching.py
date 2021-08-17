class Solution:
    def __init__(self):
        pass
    
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        ok = [[False for j in range(n + 1)] for i in range(m + 1)]
        culmulativeOr = [[False for j in range(n + 1)] for i in range(m + 1)]
        ok[0][0] = True
        for i in range(0, m + 1):
            culmulativeOr[i][0] = True

        for i in range(1, n + 1):
            if p[i - 1] == '*':
                ok[0][i] = True
                culmulativeOr[0][i] = True
            else:
                break

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                c_s, c_p = s[i - 1], p[j - 1]
                if c_p == '?':
                    if i > 0:
                        ok[i][j] = ok[i - 1][j - 1]
                elif c_p == '*':
                    ok[i][j] = culmulativeOr[i][j - 1]
                elif c_s == c_p:
                    ok[i][j] = ok[i - 1][j - 1]
                culmulativeOr[i][j] = culmulativeOr[i - 1][j] or ok[i][j]

        return ok[m][n]

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
        s = "aa",
        p = "a",
        Out = False,
    ) 
    testing.addTestcase(test)

    test = dict(
        s = "aa",
        p = "*",
        Out = True,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        s = "cb",
        p = "?a",
        Out = False,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        s = "adceb",
        p = "*a*b",
        Out = True,
    ) 
    testing.addTestcase(test)

    test = dict(
        s = "acdcb",
        p = "a*c?b",
        Out = False,
    ) 
    testing.addTestcase(test)
    # Set test check
    def testCheck(idTest, test):
        s = test["s"]
        p = test["p"]
        Out = test["Out"]
        ans = test["Out"] # TODO: Need to calculate the actual ans in the below code
        # Logic test starts here
        
        ans = solution.isMatch(s, p)

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
