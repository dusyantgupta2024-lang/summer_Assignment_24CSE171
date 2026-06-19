#include <stdio.h>

int compress(char* chars, int charsSize) {
    int write = 0;
    int read = 0;

    while (read < charsSize) {
        char current = chars[read];
        int count = 0;

        while (read < charsSize && chars[read] == current) {
            read++;
            count++;
        }

        chars[write++] = current;

        if (count > 1) {
            char buffer[12];
            sprintf(buffer, "%d", count);

            for (int i = 0; buffer[i] != '\0'; i++) {
                chars[write++] = buffer[i];
            }
        }
    }

    return write;
}
