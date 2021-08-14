class Solution:
    def __init__(self):
        pass
    
    def fastCheckMatch(self, s: str, p: str) -> bool:
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
        ans = [[False for j in range(n+1)] for i in range(m+1)]
        ans[0][0] = True
        for i in range(0, m + 1):
            c_s = s[i-1]
            for j in range(1, n + 1):
                c_p = p[j-1]
                if c_p != '*':
                    if c_p == '.' or c_s == c_p:
                        ans[i][j] = ans[i-1][j-1]
                    else:
                        ans[i][j] = False
                    continue
                # TODO: Processing if c_p == '*'
                if j == 1:
                    print("Error character * doesn't have any previous character matched with it")
                    return False
                elif p[j-2] == '*':
                    print("Error: Why 2 character * in a row")
                else:
                    previous = p[j-2]
                    form = ""
                    for k in range(i+1):
                        target = s[i-k: i]
                        if not self.fastCheckMatch(target, form):
                            break
                        ans[i][j] = ans[i-k][j-2] or ans[i][j]
                        form += previous
        return ans[m][n]

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
        p = "a*",
        Out = True,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        s = "ab",
        p = ".*",
        Out = True,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        s = "aab",
        p = "c*a*b",
        Out = True,
    ) 
    testing.addTestcase(test)

    test = dict(
        s = "mississippi",
        p = "mis*is*p*.",
        Out = False,
    ) 
    testing.addTestcase(test)
    
    # Set test check
    def testCheck(idTest, test):
        s = test["s"]
        p = test["p"]
        Out = test["Out"]
        # Logic test starts here
        
        ans = solution.isMatch(s, p)

        # Logic test ends here
        if ans == Out:
            print(f"Test {idTest}: Correct Answer")
        else:
            print(f"Test {idTest}: Wrong Answer")
            print(f"Expected: {Out}")
            print(f"Actual: {ans}")

    testing.setTestCheck(testCheck)

    # run testing
    testing.runTest()
