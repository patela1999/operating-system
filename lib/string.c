#include "string.h"
#include <stddef.h>

void itoa(char *buf, int num) {
    int index = 0;

    if (num == 0)
    {
        buf[index++] = '0';
        buf[index++] = '\0';
        return;
    }

    while (num != 0)
    {
        int digit = num % 10;
        buf[index++] = '0' + digit;
        num /= 10;
    }

    buf[index] = '\0';
    strrev(buf, index);
}

int strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

}

size_t strlen(const char *str) {
    size_t len = 0;
    while (*str++)
    {
        len++;
    }
    return len;
}

char *strrev(char *str, unsigned int length) {
    char *left, *right;
    left = str;
    right = str + (length - 1);
    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
    return str;
}

