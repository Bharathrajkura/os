#include <stdio.h>
#include <conio.h>

void main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0; 
    int i, p = 0; // p tracks number of allocated processes

    clrscr(); // Clear screen (Turbo C specific)

    // Input total memory and block size
    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);
    printf("Enter the block size (in Bytes): ");
    scanf("%d", &bs);

    // Calculate number of blocks and external fragmentation
    nob = ms / bs;
    ef = ms - nob * bs;

    // Input number of processes and their memory requirements
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
    }

    // Output number of blocks
    printf("\nNo. of Blocks available in memory: %d", nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    // Allocate memory to processes
    for (i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i + 1, mp[i]);

        if (mp[i] > bs) {
            printf("\t\tNO\t\t---");
        } else {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif += bs - mp[i]; // Calculate total internal fragmentation
            p++;               // Increment allocated process count
        }
    }

    // If memory is full and some processes can't be accommodated
    if (i < n) {
        printf("\nMemory is Full, Remaining Processes cannot be accommodated");
    }

    // Output total fragmentation details
    printf("\n\nTotal Internal Fragmentation is %d", tif);
    printf("\nTotal External Fragmentation is %d", ef);

    getch(); // Pause for key press
}
