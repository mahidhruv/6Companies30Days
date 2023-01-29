class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        for (auto x : mp) {
            string str = x.first;
            int n = str.size();
            int i = 0, j = 0;
            while (i < n && j < s.size()) {
                if (str[i] == s[j]) {
                    i++;
                }
                j++;
            }
            if (i == n) {
                count += x.second;
            }
        }

        return count++;
    }
};