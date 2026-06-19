#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    char* strStack[100];
    int numStack[100];
    int top = -1;

    char* curr = (char*)malloc(100000);
    curr[0] = '\0';

    int num = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            numStack[++top] = num;

            strStack[top] = (char*)malloc(strlen(curr) + 1);
            strcpy(strStack[top], curr);

            curr[0] = '\0';
            num = 0;
        }
        else if (s[i] == ']') {
            int repeat = numStack[top];

            char* temp = (char*)malloc(100000);
            strcpy(temp, strStack[top]);

            for (int j = 0; j < repeat; j++) {
                strcat(temp, curr);
            }

            free(curr);
            free(strStack[top]);

            curr = temp;
            top--;
        }
        else {
            int len = strlen(curr);
            curr[len] = s[i];
            curr[len + 1] = '\0';
        }
    }

    return curr;
}
