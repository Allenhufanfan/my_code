/*
字符串翻转
输入: hello xiao mi
结果：mi xiao hello
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    string words;
    while (getline(cin, words)) {
        reverse(words.begin(), words.end());
        unsigned i = 0, j = i;
        while (i < words.size()) {
            while (i < words.size() && words[i] != ' ')
                i++;
            reverse(words.begin() + j, words.begin() + i);
            j = ++i;
        }
        cout << words << endl;
    }
    return 0;
}