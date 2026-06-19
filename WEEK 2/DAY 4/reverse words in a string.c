#include <string.h>

void reverse(char *s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);
    int start = 0;

    for (int end = 0; end <= n; end++) {
        if (end == n || s[end] == ' ') {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }

    return s;
}
