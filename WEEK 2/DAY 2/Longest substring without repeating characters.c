int lengthOfLongestSubstring(char *s) {
    int index[128] = {0};

    int left = 0, maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char c = s[right];

        if (index[c] > left)
            left = index[c];

        int currentLength = right - left + 1;

        if (currentLength > maxLength)
            maxLength = currentLength;

        index[c] = right + 1;
    }

    return maxLength;
}
