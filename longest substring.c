#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int last_seen[128];

    for (int i = 0; i < 128; i++)
    {
        last_seen[i] = -1;
    }

    int max_length = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++)
    {
        unsigned char current = s[right];

        if (last_seen[current] >= left)
        {
            left = last_seen[current] + 1;
        }

        last_seen[current] = right;

        int current_length = right - left + 1;

        if (current_length > max_length)
        {
            max_length = current_length;
        }
    }

    return max_length;
}

int main()
{
    char s[] = "abcabcbb";

    int result = lengthOfLongestSubstring(s);

    printf("Input: %s\n", s);
    printf("Output: %d\n", result);

    return 0;
}