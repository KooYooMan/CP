from typing import List

class Solution:
    def __init__(self):
        pass
    
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for row in range((n + 1) // 2):
            for col in range(n // 2):
                dx, dy = row, col
                listCell = [(dx, dy), (dy, n - 1 - dx), (n - 1 - dx, n - 1 - dy), (n - 1 - dy, dx)]
                listValue = []
                for i in range(4):
                    x, y = listCell[(i + 3) % 4]
                    listValue.append(matrix[x][y])
                for i in range(4):
                    x, y = listCell[i]
                    matrix[x][y] = listValue[i]

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
        In = [[1,2,3],[4,5,6],[7,8,9]],
        Out = [[7,4,1],[8,5,2],[9,6,3]],
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]],
        Out = [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]],
    ) 
    testing.addTestcase(test)
    
    test = dict(
        In = [[1]], 
        Out = [[1]], 
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [[1,2],[3,4]], 
        Out = [[3,1],[4,2]], 
    ) 
    testing.addTestcase(test)

    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        # Logic test starts here
        
        solution.rotate(Input)
        ans = Input

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
