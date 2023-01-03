import unittest


class Solution:
    def __init__(self):
        pass

    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return 1.0 / self.myPow(x, -n)
        if n == 0:
            return 1
        s = self.myPow(x, n // 2)
        if n % 2 == 0:
            return s * s
        else:
            return s * s * x


class Testing(unittest.TestCase):
    def test_all(self):
        tests = [
            {
                "input": {
                    "x": 2,
                    "n": 10,
                },
                "answer": 1024,
            },
            {
                "input": {
                    "x": 2.1,
                    "n": 3,
                },
                "answer": 9.261,
            },
            {
                "input": {
                    "x": 2,
                    "n": -2,
                },
                "answer": 0.25,
            },
        ]

        solution = Solution()
        for test in tests:
            inp, answer = test["input"], test["answer"]
            x, n = inp["x"], inp["n"]
            output = solution.myPow(x, n)
            self.assertEqual(output, answer, f"test fail with input {inp}")


if __name__ == "__main__":
    unittest.main()
