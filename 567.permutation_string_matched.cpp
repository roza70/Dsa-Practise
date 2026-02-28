class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Map(26, 0);
        vector<int> s2Map(26, 0);

        // Initialize frequency maps for s1 and first window of s2
        for (int i = 0; i < s1.length(); i++) {
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }

        // Slide the window through s2
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (matches(s1Map, s2Map)) {
                return true;
            }
            s2Map[s2[i + s1.length()] - 'a']++; // Add new character
            s2Map[s2[i] - 'a']--;               // Remove old character
        }

        // Check the last window
        return matches(s1Map, s2Map);
    }

private:
    bool matches(vector<int>& s1Map, vector<int>& s2Map) {
        for (int i = 0; i < 26; i++) {
            if (s1Map[i] != s2Map[i]) {
                return false;
            }
        }
        return true;
    }
};