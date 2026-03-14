#include <iostream>
#include <algorithm> // Required for max()

using namespace std;

class Solution {
public:
    // Changed int[] to int* and added n as a parameter
    int longestOnes(int* nums, int n, int k) {
        int omax = -1;
        int i = 0;
        int j = 0;
        // int n = nums.size(); // C-style arrays don't have .size()
        int count = 0;

        while(j < n && i < n){
            if(nums[j] == 0 && count <= k){
                omax = max(omax, (j-i));
                j++;
                count++;
            }else if(nums[j] == 1 && count <= k){
                omax = max(omax, (j-i));
                j++;
            }else{
                while(count > k){
                    if(nums[i] == 0) count--;
                    i++;
                }
            }
        }
        return omax;
    }
};

int main() {
    int myArr[] = {0,0,0,1};
    int n = sizeof(myArr) / sizeof(myArr[0]); // Calculate size manually
    int k = 4;

    Solution sol;
    int result = sol.longestOnes(myArr, n, k);
    
    cout << "Longest Ones: " << result << endl;

    return 0;
}