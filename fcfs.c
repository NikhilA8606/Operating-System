#include <stdio.h>
#include <stdlib.h>
#define s 50
void main()
{
    int n,i,bt[s],wt[s],tat[s];
    float atat,awt;
    printf("Enter the no of process:");
    scanf("%d",&n);
    printf("Enter the burst time:\n");
    for(i= 0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    atat += tat[0];
    for(i=1;i<n;i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    printf("\nprocsess\tBurst time\tWaiting time\tTurnaround time");
    for(i = 0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t",i+1,bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time:%f",awt/n);
    printf("\nAverage turnaroundtime %f",atat/n);
}