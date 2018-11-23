/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
#include<string>
#include<assert.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>next;
    void getNext(string needle){
        int n=needle.length();
        next.clear();
        next.resize(n+1);
        next[0]=-1;
        int i=0,j=-1;
        while(i<n-1){
            if(j<0||needle[i]==needle[j]){
                i++;j++;
                if(needle[i]!=needle[j]){
                    next[i]=j;
                }
                else{
                    next[i]=next[j];
                }
            }else{
                j=next[j];
            }
        }

    }
    int strStr(string haystack, string needle) {
        getNext(needle);

        int needleLen=needle.length();
        int haystackLen=haystack.length();

        int i=0,j=0;
        while(j<needleLen&&i<haystackLen){
            if(j<0||haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j=next[j];
            }
        }

        if(j>=needleLen)return i-needleLen;
        return -1;
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
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
