#include <string.h>
#include <stdlib.h>

int expand(char* s, int left, int right) {
    while (left >= 0 &&
           right < strlen(s) &&
           s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);

    if (n < 2)
        return s;

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {

        int len1 = expand(s, i, i);       // odd length
        int len2 = expand(s, i, i + 1);   // even length

        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    char* result = (char*)malloc(maxLen + 1);

    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}
