from typing import List

class Solution:
    def __init__(self):
        pass
    
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        a, b = (m + n + 1) // 2, (m + n + 2) // 2
        cur, sum = 0, 0

        while len(nums1) > 0 or len(nums2) > 0:
            value = 0

            if len(nums1) == 0:
                value = nums2[0]
                nums2.pop(0)
            elif len(nums2) == 0:
                value = nums1[0]
                nums1.pop(0)
            else:
                foo, bar = nums1[0], nums2[0]
                value = min(foo, bar)
                if foo < bar:
                    nums1.pop(0)
                else:
                    nums2.pop(0)

            cur += 1
            if cur == a:
                sum += value
            if cur == b:
                sum += value
        return sum / 2

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
        Nums1 = [1, 3],
        Nums2 = [2],
        Out = 2.0,
    ) 
    testing.addTestcase(test)
    
    test = dict(
        Nums1 = [1, 2],
        Nums2 = [3, 4],
        Out = 2.5,
    ) 
    testing.addTestcase(test)

    test = dict(
        Nums1 = [0, 0],
        Nums2 = [0, 0],
        Out = 0.0,
    ) 
    testing.addTestcase(test)

    test = dict(
        Nums1 = [],
        Nums2 = [1],
        Out = 1.0,
    ) 
    testing.addTestcase(test)

    test = dict(
        Nums1 = [2],
        Nums2 = [],
        Out = 2.0,
    ) 
    testing.addTestcase(test)

    # Set test check
    def testCheck(idTest, test):
        nums1 = test["Nums1"]
        nums2 = test["Nums2"]
        Out = test["Out"]
        # Logic test starts here

        ans = solution.findMedianSortedArrays(nums1, nums2)

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
