#include <stdio.h>
#include <conio.h>

void main() {
    char job[10][10];
    int time[10], avail, temp[10], tem[10];
    int safe[10];
    int ind = 0, i, j, n, t, q;

    clrscr(); // Clear the screen (Turbo C specific)

    // Input number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Input job names and times
    for (i = 0; i < n; i++) {
        printf("Enter job name and time: ");
        scanf("%s %d", job[i], &time[i]);
    }

    // Input available resources
    printf("Enter the available resources: ");
    scanf("%d", &avail);

    // Copy job times and indices for sorting
    for (i = 0; i < n; i++) {
        temp[i] = time[i];
        tem[i] = i; // Store the original indices
    }

    // Sort jobs by time in ascending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;

                t = tem[i];
                tem[i] = tem[j];
                tem[j] = t;
            }
        }
    }

    // Check for safe sequence
    for (i = 0; i < n; i++) {
        q = tem[i];
        if (time[q] <= avail) {
            safe[ind++] = q; // Add to safe sequence
            avail -= time[q]; // Reduce available resources
        }
    }

    // Output results
    if (ind == 0) {
        printf("No safe sequence.\n");
    } else {
        printf("Safe sequence is:\n");
        for (i = 0; i < ind; i++) {
            printf(" %s %d\n", job[safe[i]], time[safe[i]]);
        }
    }

    getch(); // Wait for keypress (Turbo C specific)
}

