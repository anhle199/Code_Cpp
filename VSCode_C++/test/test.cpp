#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// bool equalKey(string cal)
// {
//     int start = 0, end, num = 0;

//     end = cal.find('+', start);
//     if (end != string::npos) {
//         do {
//             num += stoi(cal.substr(start, end - start));
//             start = end + 1;
//             end = cal.find('+', start);
//         } while (end != string::npos);

//         string str = cal.substr(start);
        
//         for (int i = 1; i < str.length(); i++)
//             if (num + stoi(str.substr(0, i)) == stoi(str.substr(i)))
//                 return true;   

//     } else {
//         for (int i = 1; i < cal.length(); i++)
//             if (stoi(cal.substr(0, i)) == stoi(cal.substr(i)))
//                 return true;
//     }

//     return false;
// }

bool isDuplicate(const vector<vector<int>> &arr2D, const vector<int> &val) {
        if (arr2D.empty())
            return false;
        
        return (find(arr2D.begin(), arr2D.end(), val) != arr2D.end());
    }
    
    vector<int> createTriplet(const int &val1, const int &val2, const int &val3) {
        int minVal = min(val1, min(val2, val3));
        int maxVal = max(val1, max(val2, val3));
        
        
        return {minVal, val1 + val2 + val3 - minVal - maxVal, maxVal};
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        if (nums.size() > 2) {
            vector<int> triplet;
            vector<int>::iterator it;
            
            for (int i = 0; i < nums.size() - 2; i++) {
                for (int j = i + 1; j < nums.size() - 1; j++) {
                    it = find(nums.begin() + j + 1, nums.end(), -(nums[i] + nums[j]));

                    if (it != nums.end()) {
                        triplet = createTriplet(nums[i], nums[j], *it);

                        if (!isDuplicate(res, triplet))
                            res.push_back(triplet);
                    }
                }
            }   
        }
        
        return res;
    }

int main() {
    vector<int> a = {3,0,-2,-1,1,2};
    vector<vector<int>> b = threeSum(a);

	return 0;
}