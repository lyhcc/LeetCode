//题目网址：https://leetcode.com/problems/container-with-most-water/description/
/*
题目概述
    Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
    注意：CB编译有错，VS没有
*/
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<ctype.h>
#include<sstream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int ans=0;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(ans<(j-i+1)*(min(height[i],height[j]))){
                    ans=(j-i+1)*(min(height[i],height[j]));
                }
            }
        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
