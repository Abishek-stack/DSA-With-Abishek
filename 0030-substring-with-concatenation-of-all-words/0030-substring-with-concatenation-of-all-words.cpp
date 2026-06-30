class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;

        unordered_map<string, int> required;

        // Store frequency of each word
        for (string word : words)
            required[word]++;

        // Try every possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {

            unordered_map<string, int> window;

            int left = offset;
            int count = 0;

            // Move right one whole word at a time
            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {

                string currWord = s.substr(right, wordLen);

                // Invalid word
                if (required.find(currWord) == required.end()) {

                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
                else {

                    window[currWord]++;
                    count++;

                    // Too many occurrences of current word
                    while (window[currWord] > required[currWord]) {

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found all words
                    if (count == wordCount) {

                        ans.push_back(left);

                        // Slide window forward
                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
            }
        }

        return ans;
    }
};