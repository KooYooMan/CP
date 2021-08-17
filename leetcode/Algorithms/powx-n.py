from typing import List

class Solution:
    def __init__(self):
        pass
    
    def myPow(self, x: float, n: int) -> float:
        if (n < 0):
            return 1.0 / self.myPow(x, -n)
        if n == 0:
            return 1
        s = self.myPow(x, n // 2)
        if n % 2 == 0:
            return s * s
        else:
            return s * s * x
        
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
        x = 2.00000,
        n = 10,
        Out = 1024.00000,
    ) 
    testing.addTestcase(test)

    test = dict(
        x = 2.10000,
        n = 3,
        Out = 9.26100,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        x = 2.00000,
        n = -2,
        Out = 0.25000,
    ) 
    testing.addTestcase(test)

    # Set test check
    def testCheck(idTest, test):
        x, n = test["x"], test["n"]
        Out = test["Out"]
        # Logic test starts here
        
        ans = round(solution.myPow(x, n), 10)

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
