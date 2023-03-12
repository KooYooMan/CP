//
// Created by Manh Cao on 24/01/2023.
//

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0, diff = (a.size() - b.size()); i < diff; i ++) {
            b.append("0");
        }

        int remember = 0;
        string ans = "";

        for (int i = 0; i < a.size(); i ++) {
            int digit_a = (a[i] == '0' ? 0 : 1);
            int digit_b = (b[i] == '0' ? 0 : 1);
            int sum = digit_a + digit_b + remember;
            remember = sum / 2;
            ans.append(to_string(sum % 2));
        }

        if (remember > 0) {
            ans.append("1");
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution solution = Solution();

    string output;

//    output = solution.addBinary("11", "1");
//    cout << output << endl << endl;
//
//    output = solution.addBinary("1010", "1011");
//    cout << output << endl << endl;

    output = solution.addBinary("1", "111");
    cout << output << endl << endl;

    return 0;
}