/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool allZero(int count[]) {
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int* findAnagrams(char* s, char* p, int* returnSize) {
    int n = strlen(s);
    int m = strlen(p);

    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = 0;

    if (m > n)
        return result;

    int count[26] = {0};

    for (int i = 0; i < m; i++) {
        count[p[i] - 'a']++;
        count[s[i] - 'a']--;
    }

    if (allZero(count))
        result[(*returnSize)++] = 0;

    for (int i = m; i < n; i++) {
        count[s[i] - 'a']--;
        count[s[i - m] - 'a']++;

        if (allZero(count))
            result[(*returnSize)++] = i - m + 1;
    }

    return result;
}
