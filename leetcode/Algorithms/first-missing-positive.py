from typing import List

class Solution:
    def __init__(self):
        pass

    def firstMissingPositive(self, nums: List[int]) -> int: 
        n = len(nums)
        for i in range(0, n):
            if nums[i] == i + 1:
                continue
            if nums[i] <= 0:
                continue
            if nums[i] >= n + 1:
                nums[i] = 0
                continue
            value = nums[i]
            nums[i] = 0
            while True:
                newValue = nums[value - 1]
                nums[value - 1] = value 
                if newValue == value:
                    break
                if newValue >= n + 1:
                    break
                if newValue <= 0:
                    break
                value = newValue 
        for i in range(0, n):
            if nums[i] <= 0:
                return i + 1
        return n + 1 

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
        In = [1, 2, 0],
        Out = 3,
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [3, 4, -1, 1],
        Out = 2,
    ) 
    testing.addTestcase(test)
    

    test = dict(
        In = [7, 8, 9, 11, 12],
        Out = 1,
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [1],
        Out = 2,
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [1, 1],
        Out = 2,
    ) 
    testing.addTestcase(test)

    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        ans = test["Out"] # TODO: Need to calculate the actual ans in the below code
        # Logic test starts here
        
        ans = solution.firstMissingPositive(Input)

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
