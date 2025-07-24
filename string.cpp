//Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int left = 0, right = 0, maxLength = 0;

        while (right < s.length()) {
            if (ch.find(s[right]) == ch.end()) {
                ch.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                ch.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    int result = sol.lengthOfLongestSubstring(str);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}

