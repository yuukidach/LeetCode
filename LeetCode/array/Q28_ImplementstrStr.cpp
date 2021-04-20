class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        if (len2 == 0) return 0;
        for (int i = 0; i <= len1 - len2; ++i) {
            int j;
            for (j = 0; j < len2; ++j) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == len2) return i;
        }

        return -1;
    }
};