#include<stdio.h>
int main(){
    int bt[20],wt[20],tat[20],n;
    float awt,atat=0;
    printf("Enter The Total Number Of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Burst Tine for Process %d : ",i);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(int i=0;i<n;i++){
        if(i>0){
            wt[i]=wt[i-1]+bt[i-1];
        }
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];
    }
     printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);

    return 0;
}