#include <stdbool.h>
#include <string.h>

bool allZero(int count[]) {
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }
    return true;
}

bool checkInclusion(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    if (n > m)
        return false;

    int count[26] = {0};

    for (int i = 0; i < n; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }

    if (allZero(count))
        return true;

    for (int i = n; i < m; i++) {
        count[s2[i] - 'a']--;
        count[s2[i - n] - 'a']++;

        if (allZero(count))
            return true;
    }

    return false;
}
