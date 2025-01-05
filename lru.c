#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;

    clrscr(); // Clear the screen (Turbo C specific)

    // Input length of reference string
    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    // Input reference string
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0; // Initialize the flag array
    }

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames and counters
    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1; // Set all frames to -1 (empty)
    }

    // Page replacement process
    printf("\nThe Page Replacement process is:\n");
    for (i = 0; i < n; i++) {
        // Check if the page is already in a frame
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;        // Page found in a frame
                count[j] = next;    // Update the usage time
                next++;
                break;
            }
        }

        // If the page is not in a frame (page fault)
        if (flag[i] == 0) {
            if (i < f) {
                // Directly place the page in an empty frame
                m[i] = rs[i];
                count[i] = next;
                next++;
            } else {
                // Find the least recently used page
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[min] > count[j]) {
                        min = j;
                    }
                }
                m[min] = rs[i];    // Replace the least recently used page
                count[min] = next; // Update the usage time
                next++;
            }
            pf++; // Increment the page fault counter
        }

        // Print the current frame state
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("%d\t", m[j]);
            else
                printf("-\t");
        }

        // Indicate if a page fault occurred
        if (flag[i] == 0) {
            printf("PF No. -- %d", pf);
        }
        printf("\n");
    }

    // Output the total number of page faults
    printf("\nThe number of page faults using LRU are: %d", pf);

    getch(); // Pause for key press (Turbo C specific)
}
