#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> LPS(string n) {
        vector<int> lps(n.size(), 0);
        int m = n.size();
        int i = 0;
        int len = 0;
        while(i < m){
            if(n[i] == n[len]){
                len++;
                lps[i] =  len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int strStr(string h, string n) {
        if (n.empty()) return 0;
        
        vector<int> lps = LPS(n);
        int i = 0; // index for haystack
        int j = 0; // index for needle

        while (i < h.size()) {
           if(h[i] == n[j]){
                i++;
                j++;
           }
           if(j == n.size()) return i - j;
           else if(i < h.size() && h[i] != n[j]){
            if(j != 0){
                j = lps[j - 1];
            }else{
                i++;
            }
           }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard Match
    string h1 = "sadbutsad", n1 = "sad";
    cout << "Test 1 (sadbutsad, sad): " << sol.strStr(h1, n1) << " (Expected: 0)" << endl;

    // Test Case 2: No Match
    string h2 = "leetcode", n2 = "leeto";
    cout << "Test 2 (leetcode, leeto): " << sol.strStr(h2, n2) << " (Expected: -1)" << endl;

    // Test Case 3: The "KMP Jump" - mismatch after partial match
    string h3 = "ababcabcabababd", n3 = "abababd";
    cout << "Test 3 (KMP Jump Case): " << sol.strStr(h3, n3) << " (Expected: 8)" << endl;

    return 0;
}