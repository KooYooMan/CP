//
// Created by Manh Cao on 29/01/2023.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string> > lines;
        vector<string> line;
        int current = 0;
        for (string word: words) {
            if (!line.empty()) current ++;
            current += word.size();
            if (current > maxWidth) {
                lines.push_back(line);

                line.clear();
                line.push_back(word);

                current = word.size();
            } else {
                line.push_back(word);
            }
        }

        lines.push_back(line);

        vector<string> result;

        for (int index = 0, n_lines = lines.size(); index < n_lines; index ++) {
            vector<string> l = lines[index];
            string ans = l[0];

            int n_word = 0, n_word_len = 0;
            for (string word: l) {
                n_word ++;
                n_word_len += word.size();
            }

            if (index == n_lines - 1) {
                for (int i = 1; i < n_word; i ++) {
                    ans.push_back(' ');
                    ans = ans + l[i];
                }
                for (int i = 0; i < maxWidth - (n_word_len + n_word - 1); i ++) ans.push_back(' ');
                result.push_back(ans);
                continue;
            }

            if (n_word == 1) {
                for (int i = 0; i < maxWidth - n_word_len; i ++) ans.push_back(' ');
            } else {
                int num_space = (maxWidth - n_word_len) / (n_word - 1);
                int num_space_over = (maxWidth - n_word_len) % (n_word - 1);
                for (int i = 1; i < n_word; i ++) {
                    for (int j = 0; j < num_space; j ++) ans.push_back(' ');
                    if (i <= num_space_over) ans.push_back(' ');
                    ans = ans + l[i];
                }
            }

            result.push_back(ans);
        }
        return result;
    }
};

int main() {

    Solution solution = Solution();

    vector<string> words;
    words.push_back("What");
    words.push_back("must");
    words.push_back("be");
    words.push_back("acknowledgment");
    words.push_back("shall");
    words.push_back("be");

    auto ans = solution.fullJustify(words, 16);

    for (string justify: ans) cout << justify << endl;

    return 0;
}
