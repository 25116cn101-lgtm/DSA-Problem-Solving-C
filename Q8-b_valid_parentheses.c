#include <string.h>

int isValid(char* s) {
    char stack[10000];
    int top = -1, i;

    for (i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1)
                return 0;

            if ((c == ')' && stack[top] != '(') ||
                (c == ']' && stack[top] != '[') ||
                (c == '}' && stack[top] != '{'))
                return 0;

            top--;
        }
    }

    return top == -1;
}
