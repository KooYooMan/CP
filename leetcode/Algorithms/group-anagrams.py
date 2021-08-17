from typing import List

class Solution:
    def __init__(self):
        pass
    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        candidate = []
        for s in strs:
            s_sorted = ''.join(sorted(s))
            candidate.append((s, s_sorted))

        def getKey(x):
            return x[1]

        candidate.sort(key=getKey)
        ans = []
        curGroup = []
        for index, c in enumerate(candidate):
            if index == 0 or (len(curGroup) == 0):
                curGroup.append(c[0])
                continue
            if c[1] == candidate[index - 1][1]:
                curGroup.append(c[0])
            else:
                ans.append(curGroup[:])
                curGroup = []
                curGroup.append(c[0])
        if (len(curGroup) > 0):
            ans.append(curGroup[:])
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
        In = ["eat","tea","tan","ate","nat","bat"],
        Out = [["bat"],["nat","tan"],["ate","eat","tea"]],
    ) 
    testing.addTestcase(test)

    test = dict(
        In = [""], 
        Out = [[""]],
    ) 
    testing.addTestcase(test)
    
    test = dict(
        In = ["a"],
        Out = [["a"]], 
    ) 
    testing.addTestcase(test)
    # Set test check
    def testCheck(idTest, test):
        Input = test["In"]
        Out = test["Out"].sort()
        # Logic test starts here
        
        ans = solution.groupAnagrams(Input).sort()

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
