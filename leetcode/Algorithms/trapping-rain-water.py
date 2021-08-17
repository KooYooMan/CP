from typing import List

class Solution:
    def __init__(self):
        pass
    
    def trap(self, height: List[int]) -> int:
        stack = []
        ans = 0
        for index, curHeight in enumerate(height):
            if len(stack) == 0:
                stack.append((curHeight, index))
                continue
            myIndex = index
            while len(stack) != 0:
                lastHeight, lastIndex = stack[len(stack) - 1]
                if lastHeight <= curHeight:
                    stack.pop()
                    if len(stack) > 0:
                        previousHeight, previousIndex = stack[len(stack) - 1] 
                        ans += (myIndex - lastIndex) * (min(previousHeight, curHeight) - lastHeight)
                        if previousHeight > curHeight:
                            myIndex = lastIndex
                    else:
                        stack.append((curHeight, 0))
                        break
                else:
                    stack.append((curHeight, myIndex))
                    break
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
        In = [0,1,0,2,1,0,1,3,2,1,2,1],
        Out = 6,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        In = [4,2,0,3,2,5],
        Out = 9,
    ) 
    testing.addTestcase(test)

    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        # Logic test starts here
        
        ans = solution.trap(Input)

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
