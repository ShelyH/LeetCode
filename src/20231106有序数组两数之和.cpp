#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum==target){
                res.push_back(left);
                res.push_back(right);
                return res;
            }
            else if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> vec = {1, 2, 4, 6, 10};
    return 0;
}
