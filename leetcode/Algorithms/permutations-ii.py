from typing import List

class Solution:
    def __init__(self):
        pass
    
    def backtrack(self, built: List[int], candidate: List[int], result: List[List[int]]) -> None:
        if len(candidate) == 0:
            newResult = []
            for element in built:
                newResult.append(element)
            result.append(newResult)
            return
        for index, value in enumerate(candidate):
            if index > 0 and candidate[index - 1] == candidate[index]:
                continue
            built.append(value)
            candidate.pop(index)
            self.backtrack(built, candidate, result)
            built.pop()
            candidate.insert(index, value)

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        built = []
        ans = []
        self.backtrack(built, nums, ans)
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
        In = [1,1,2],
        Out = [[1,1,2], [1,2,1], [2,1,1]],
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [1,2,3],
        Out = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]],
    ) 
    testing.addTestcase(test)
    
    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        # Logic test starts here
        
        ans = solution.permuteUnique(Input)

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
