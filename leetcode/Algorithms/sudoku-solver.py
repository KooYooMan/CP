from typing import List

class Solution:
    def __init__(self):
        pass
    
    def printBoard(self, board: List[List[str]]) -> None:
        for i in range(9):
            for j in range(9):
                print(board[i][j], end=' ')
            print()
        print()
    
    def solveSudoku(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for k in ["1","2","3","4","5","6","7","8","9"]:
                        if self.isValid(board,i,j,k):
                            board[i][j] = k
                            if self.solveSudoku(board):
                                return True
                            else:
                                board[i][j] = '.'             
                    return False
        return True
    
    def isValid(self,board,x,y,c):
        a, b = (x // 3) * 3, (y // 3) * 3
        for i in range(9):
            if board[x][i] == c: return False
            if board[i][y] == c: return False
            if board[a + (i//3)][b + (i%3)] == c: return False
        return True

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
        In = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]],
        Out = [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]],
    ) 
    testing.addTestcase(test)
    
    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"]
        # Logic test starts here
        
        solution.solveSudoku(Input)
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
