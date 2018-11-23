/*��Ŀ��Դ��https://leetcode.com/problems/3sum/description/

��Ŀ������

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >ans;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len;i++){
            //������������ģ���iԪ��Ϊ��������Ԫ��ҲΪ��
            if(nums[i]>0)break;
            //ȥ��
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=len-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    vector<int>t;
                    t.push_back(nums[i]);
                    t.push_back(nums[l]);
                    t.push_back(nums[r]);
                    ans.push_back(t);
                    l++;
                    r--;
                    //ȥ���ظ�
                    while(l<r&&nums[l]==nums[l-1])l++;
                    while(l<r&&nums[r]==nums[r+1])r++;
                }else if(sum<0){
                    //̫С������������ƶ�һ��Ԫ��
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};
int main(){
    int n;

    cin>>n;
    vector<int>num;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        num.push_back(x);
    }
    Solution s;
    vector<vector<int> >ans=s.threeSum(num);
     cout<<"[";
    for(int i=0;i<ans.size();i++){
            cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            printf("%d%c",ans[i][j],j==ans[i].size()-1?']':',');
        }
    }
    cout<<"]";
    return 0;
}
