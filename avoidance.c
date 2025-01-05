#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    int alloc[10][10], max[10][10], avail[10], work[10], total[10];
    int need[10][10];
    int n, m, i, j, k, count = 0, c = 0;
    char finish[10];

    clrscr(); // Clear screen (Turbo C specific)

    // Input number of processes and resources
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &n, &m);

    // Initialize finish array
    for (i = 0; i < n; i++)
        finish[i] = 'n';

    // Input claim matrix
    printf("Enter the claim matrix (Max matrix):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input total resources
    printf("Enter the total resources (Resource vector): ");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculate available resources
    for (i = 0; i < m; i++) {
        avail[i] = 0;
        for (j = 0; j < n; j++) {
            avail[i] += alloc[j][i];
        }
        work[i] = total[i] - avail[i]; // Initialize work vector
    }

    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    printf("\nThe process execution sequence is as follows:\n");

    while (count < n) {
        int allocated = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 'n') {
                c = 0;

                for (j = 0; j < m; j++) {
                    if (need[i][j] <= work[j])
                        c++;
                }

                if (c == m) { // All resources can be allocated
                    printf("\nAll resources allocated to Process %d", i + 1);

                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k]; // Update available resources

                    finish[i] = 'y'; // Mark process as finished
                    allocated = 1;
                    count++;

                    printf("\nAvailable resources after Process %d execution:", i + 1);
                    for (k = 0; k < m; k++)
                        printf(" %d", work[k]);

                    break;
                }
            }
        }

        if (!allocated) { // If no allocation could be done
            printf("\nSystem is not in a safe state!");
            getch();
            return;
        }
    }

    printf("\n\nSystem is in a safe mode");
    printf("\nThe given state is a safe state");
    getch(); // Wait for keypress (Turbo C specific)
}
