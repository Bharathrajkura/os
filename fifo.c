#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

    clrscr(); // Clear screen (Turbo C specific)

    // Input length of reference string
    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    // Input reference string
    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    // Input number of frames
    printf("\nEnter the number of frames: ");
    scanf("%d", &f);

    // Initialize all frames to -1 (empty)
    for (i = 0; i < f; i++) {
        m[i] = -1;
    }

    // Process the reference string
    printf("\nThe Page Replacement Process is:\n");
    for (i = 0; i < n; i++) {
        // Check if the page is already in one of the frames
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                break;
            }
        }

        // If the page is not in a frame, it's a page fault
        if (k == f) {
            m[count] = rs[i]; // Replace the frame at position `count`
            count = (count + 1) % f; // Move to the next frame (FIFO)
            pf++; // Increment page fault count
        }

        // Print the current state of the frames
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("\t%d", m[j]);
            else
                printf("\t-");
        }

        // Indicate if a page fault occurred
        if (k == f) {
            printf("\tPF No. %d", pf);
        }

        printf("\n");
    }

    // Output the total number of page faults
    printf("\nThe number of Page Faults using FIFO are: %d", pf);

    getch(); // Pause for key press
}
