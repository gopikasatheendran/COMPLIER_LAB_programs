#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char ch, c, a[10][10], f[10];
int i = 0, j = 0, k, z, n, m = 0;

void first(char c);
void follow(char c);
int addToSet(char c);

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (e.g., S=AB):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    do {
        m = 0;
        printf("Enter the character: ");
        scanf(" %c", &c); // " %c" ensures leading whitespace is ignored

        first(c);
        printf("First(%c): {", c);
        for (i = 0; i < m; i++) {
            if (f[i] != '\0') {
                printf("%c", f[i]);
                if (i < m - 1) printf(", ");
            }
        }
        printf("}\n");

        strcpy(f, " ");
        m = 0;
        follow(c);
        printf("Follow(%c): {", c);
        for (i = 0; i < m; i++) {
            if (f[i] != '\0') {
                printf("%c", f[i]);
                if (i < m - 1) printf(", ");
            }
        }
        printf("}\n");

        printf("Continue? 0/1: ");
        scanf("%d", &z);
    } while (z == 1);

    return 0;
}

void first(char c) {
    int k;
    if (!isupper(c)) { // if c is a terminal
        addToSet(c);
        return;
    }

    for (k = 0; k < n; k++) {
        if (a[k][0] == c) { // production for non-terminal c
            if (islower(a[k][2])) { // terminal directly follows non-terminal
                addToSet(a[k][2]);
            } else if (a[k][2] == '$') { // epsilon production
                addToSet('$');
            } else { // recursive call for non-terminal
                first(a[k][2]);
            }
        }
    }
}

void follow(char c) {
    if (a[0][0] == c) // start symbol
        addToSet('$');

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0') { // next symbol exists
                    first(a[i][j + 1]);
                }
                if (a[i][j + 1] == '\0' && c != a[i][0]) { // at end of production
                    follow(a[i][0]);
                }
            }
        }
    }
}

int addToSet(char c) {
    for (int i = 0; i < m; i++) {
        if (f[i] == c) // check for duplicate
            return 0;
    }
    f[m++] = c; // add to set
    return 1;
}
