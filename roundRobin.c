#include<stdio.h>
int main(){
    int n,bt[20],wt[20],tat[20],remaining_bt[20],t;
    float atat=0,awt=0;
    int ellapsed_time=0;
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Burst Time for Process %d : ",i);
        scanf("%d",&bt[i]);
        remaining_bt[i]=bt[i];
    }
    printf("Enter the size of time sliced : ");
    scanf("%d",&t);
    int processes_left=n;
    while(processes_left!=0){
        for(int i=0;i<n;i++){
            if(remaining_bt[i]>0){
                if(remaining_bt[i]<=t){
                    ellapsed_time+=remaining_bt[i];
                    tat[i]=ellapsed_time;
                    remaining_bt[i]=0;
                    processes_left--;
                }else{
                    ellapsed_time+=t;
                    remaining_bt[i]-=t;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("\nThe Average Turnaround Time is: %.2f", atat / n);
    printf("\nThe Average Waiting Time is: %.2f", awt / n);

    printf("\n\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    return 0;

}