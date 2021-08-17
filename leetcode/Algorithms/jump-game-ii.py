from typing import List

class Solution:
    def __init__(self):
        pass
    
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [n + 1 for i in range(n)]
        dp[0] = 0
        for index, num in enumerate(nums):
            for i in range(1, num + 1):
                if index + i >= n:
                    break
                dp[index + i] = min(dp[index + i], dp[index] + 1)
        return dp[n - 1]

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
        In = [2,3,1,1,4],
        Out = 2,
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [2,3,0,1,4], 
        Out = 2,
    ) 
    testing.addTestcase(test)
    
    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        # Logic test starts here
        
        ans = solution.jump(Input)

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
