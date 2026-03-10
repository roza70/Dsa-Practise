#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";  // Handle empty string
        
        int start = 0, end = 0;    // Track longest palindrome boundaries
        
        // Try every index as potential center
        for (int i = 0; i < s.length(); i++) {
            // Check ODD length palindromes centered at i
            int len1 = expandAroundCenter(s, i, i);
            
            // Check EVEN length palindromes centered between i and i+1
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get max length from both odd/even
            int len = max(len1, len2);
            
            // Update start/end if this is longest so far
            if (len > end - start) {
                start = i - (len - 1) / 2;      // Left boundary
                end = i + len / 2;              // Right boundary
            }
        }
        
        return s.substr(start, end - start + 1);  // Extract substring
    }
    
private:
    // Expand from left,right while chars match, return length of palindrome
    int expandAroundCenter(string& s, int left, int right) {
        // Expand while valid bounds and chars match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;    // Move left pointer outward
            right++;   // Move right pointer outward
        }
        
        // Return length of palindrome found (before last invalid expansion)
        return right - left - 1;
    }
};
