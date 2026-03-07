#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // ENCODE: Convert vector<string> → single string
    string encode(vector<string>& strs) {
        string result = "";  // Final encoded string
        
        for (string s : strs) {
            // Format: length + "#" + actual_string
            result += to_string(s.length()) + "#" + s;
        }
        return result;
    }
    
    // DECODE: Convert single string → vector<string>
    vector<string> decode(string s) {
        vector<string> result;  // Final decoded strings
        int i = 0;              // Current position in encoded string
        
        while (i < s.length()) {
            // Step 1: Read length until "#" found
            int length = 0;
            while (s[i] != '#') {
                length = length * 10 + (s[i] - '0');  // Build number
                i++;
            }
            i++;  // Skip the "#"
            
            // Step 2: Extract exactly 'length' characters
            string word = s.substr(i, length);
            result.push_back(word);
            i += length;  // Move to next string
        }
        return result;
    }
};
