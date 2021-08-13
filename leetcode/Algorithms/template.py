class Solution:
    def __init__(self):
        pass
    
    def SimpleProblem(self, x: int):
        return x

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
        In = 5,
        Out = 5,
    ) 
    testing.addTestcase(test)
    
    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        ans = test["Out"] # TODO: Need to calculate the actual ans in the below code
        # Logic test starts here
        
        ans = solution.SimpleProblem(Input)

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
