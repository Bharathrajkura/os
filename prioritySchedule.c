#include<stdio.h>
int main(){
    int bt[10],wt[10],tat[10],priority[10],process[10],n;
    printf("Enter the Number Of Processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        process[i]=i;
        printf("Enter the process Burst Time and Priority: %d : ",i);
        scanf("%d %d",&bt[i],&priority[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(priority[i]>priority[j]){
                int temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;
                 temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }
    float awt=0,att=0;
    wt[0]=0;
    tat[0]=bt[0];
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+tat[i-1];
        tat[i]=wt[i]+bt[i];
        att+=tat[i];
        awt+=wt[i];
    }
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", att / n);

    return 0;
}