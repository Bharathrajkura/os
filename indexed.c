#include <stdio.h>
#include <conio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int nob;            // Number of blocks
    int blocks[30];     // Block numbers
} ft[30];

void main() {
    int i, j, n;
    char s[20];

    clrscr(); // Clear screen for Turbo C

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);

        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &ft[i].nob);

        printf("Enter the blocks of the file: ");
        for (j = 0; j < ft[i].nob; j++) {
            scanf("%d", &ft[i].blocks[j]);
        }
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0) {
            break; // File found
        }
    }

    if (i == n) {
        printf("\nFile Not Found\n");
    } else {
        printf("\nFILE NAME     NO OF BLOCKS     BLOCKS OCCUPIED");
        printf("\n%s\t\t%d\t\t", ft[i].name, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++) {
            printf("%d ", ft[i].blocks[j]);
        }
        printf("\n");
    }

    getch(); // Wait for a key press before exiting
}
