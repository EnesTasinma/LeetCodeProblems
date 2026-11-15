#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnArr;
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (um.find(need) != um.end()) {
                returnArr.push_back(um.at(need));
                returnArr.push_back(i);
                break;
            } else {
                um.emplace(nums[i], i);
            }
        }
        return returnArr;
    }
};

int main() {
    Solution a;
    vector<int> test = {2, 7, 11, 15};
    vector<int> tes2 = a.twoSum(test, 9);
    cout << tes2[0] << "    " << tes2[1] << endl;
}