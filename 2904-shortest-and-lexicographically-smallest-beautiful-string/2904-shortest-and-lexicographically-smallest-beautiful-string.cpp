class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1')
                ones++;

            while (ones == k) {

                while (left < right && s[left] == '0')
                    left++;

                int len = right - left + 1;

                if (ans.empty() ||
                    len < ans.size() ||
                    (len == ans.size() &&
                     s.substr(left, len) < ans)) {
                    ans = s.substr(left, len);
                }

                if (s[left] == '1') {
                    ones--;
                    left++;
                }
            }
        }

        return ans;
    }
};