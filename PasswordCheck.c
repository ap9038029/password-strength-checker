#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pwd[100];
    int u = 0, l = 0, d = 0, s = 0, seq = 0;

    printf("Enter password: ");
    scanf("%99s", pwd);

    int len = strlen(pwd);

    for (int i = 0; i < len; i++) {
        if (isupper(pwd[i])) u = 1;
        else if (islower(pwd[i])) l = 1;
        else if (isdigit(pwd[i])) d = 1;
        else s = 1;

        if (i > 0 && pwd[i] == pwd[i-1] + 1)
            seq = 1;

        if (i > 1 && pwd[i] == pwd[i-1] &&
            pwd[i] == pwd[i-2])
            seq = 1;
    }

    if (len >= 8 && u && l && d && s && !seq)
        printf("Strong Password");
    else {
        printf("Weak Password\n");
        printf("Please change your password.");
    }

    return 0;
}