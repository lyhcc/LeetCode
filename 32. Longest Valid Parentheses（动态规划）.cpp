/*
ÌâÄ¿ÃèÊö
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

*/
#include<vector>
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {

	        int result=0;
	        vector<int> dp(s.length(),0);
	        for(int i=1;i<s.length();i++)
	        {
	            if(s[i]==')')
	            {
	                if(s[i-1-dp[i-1]]=='(')
	                {
	                    dp[i]=dp[i-1]+2;
	                    dp[i]+=dp[i-dp[i]];
	                }
	            }
	            result=max(result,dp[i]);
	        }
	        return result;
    }

};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
