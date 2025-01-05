#include <stdio.h>
#include <conio.h>

void main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];

    clrscr(); // Clear screen (Turbo C specific)

    // Input memory size and page size
    printf("\nEnter the memory size -- ");
    scanf("%d", &ms);

    printf("\nEnter the page size -- ");
    scanf("%d", &ps);

    // Calculate the number of pages available
    nop = ms / ps;
    printf("\nThe number of pages available in memory are -- %d", nop);

    // Input number of processes
    printf("\nEnter number of processes -- ");
    scanf("%d", &np);

    rempages = nop; // Remaining pages in memory

    for (i = 1; i <= np; i++) {
        // Input number of pages required for process
        printf("\nEnter number of pages required for p[%d]-- ", i);
        scanf("%d", &s[i]);

        if (s[i] > rempages) {
            printf("\nMemory is Full");
            break;
        }

        rempages -= s[i]; // Deduct pages from remaining
        printf("\nEnter page table for p[%d] --- ", i);
        for (j = 0; j < s[i]; j++) {
            scanf("%d", &fno[i][j]); // Input frame numbers
        }
    }

    // Input logical address details
    printf("\nEnter Logical Address to find Physical Address");
    printf("\nEnter process no., page number, and offset -- ");
    scanf("%d %d %d", &x, &y, &offset);

    // Validate inputs
    if (x > np || y >= s[x] || offset >= ps) {
        printf("\nInvalid Process or Page Number or Offset");
    } else {
        // Calculate physical address
        pa = fno[x][y] * ps + offset;
        printf("\nThe Physical Address is -- %d", pa);
    }

    getch(); // Wait for keypress (Turbo C specific)
}
