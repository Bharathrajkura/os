#include <stdio.h>
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int allocated[10][10], max[10][10], need[10][10], available[10], work[10];
    int finished[10] = {0}; // Flag array to mark completed processes
    int pno, rno;          // Number of processes and resources
    int count = 0;         // Count of completed processes

    // Input: Number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the number of resources: ");
    scanf("%d", &rno);

    // Input: Total resources
    int totalResources[10];
    printf("Enter total resources for each type:\n");
    for (int i = 0; i < rno; i++) {
        scanf("%d", &totalResources[i]);
    }

    // Input: Max matrix
    printf("Enter the Maximum resource requirements for each process:\n");
    for (int i = 0; i < pno; i++) {
        printf("Process %d: ", i + 1);
        for (int j = 0; j < rno; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input: Allocated matrix
    printf("Enter the Allocated resources for each process:\n");
    for (int i = 0; i < pno; i++) {
        printf("Process %d: ", i + 1);
        for (int j = 0; j < rno; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    // Calculate available resources
    printf("Available resources:\n");
    for (int j = 0; j < rno; j++) {
        int sum = 0;
        for (int i = 0; i < pno; i++) {
            sum += allocated[i][j];
        }
        available[j] = totalResources[j] - sum;
        work[j] = available[j];
        printf("%4d", work[j]);
    }
    printf("\n");

    // Calculate the need matrix
    for (int i = 0; i < pno; i++) {
        for (int j = 0; j < rno; j++) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    printf("\nAllocated Matrix:\n");
    printMatrix(allocated, pno, rno);

    printf("\nMax Matrix:\n");
    printMatrix(max, pno, rno);

    printf("\nNeed Matrix:\n");
    printMatrix(need, pno, rno);

    // Safety algorithm
    while (count < pno) {
        int found = 0;

        for (int i = 0; i < pno; i++) {
            if (!finished[i]) { // Process not yet completed
                int canProceed = 1;
                for (int j = 0; j < rno; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = 0; // Not enough resources
                        break;
                    }
                }

                if (canProceed) {
                    // Process can be completed
                    for (int j = 0; j < rno; j++) {
                        work[j] += allocated[i][j]; // Release resources
                    }
                    finished[i] = 1; // Mark process as finished
                    count++;
                    found = 1;
                    printf("\nProcess %d has completed.", i + 1);
                    printf("\nUpdated Available Resources: ");
                    for (int j = 0; j < rno; j++) {
                        printf("%4d", work[j]);
                    }
                    printf("\n");
                }
            }
        }

        if (!found) {
            // No process can proceed
            printf("\nThe system is in an unsafe state!");
            return 0;
        }
    }

    printf("\nThe system is in a safe state!");
    return 0;
}
