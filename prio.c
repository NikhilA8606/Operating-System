#include <stdio.h>
#include <stdlib.h>
#define s 50
void main()
{
    int n,i,bt[s],wt[s],tat[s],temp,j,p[s],tempb;
    float atat=0,awt=0;
    printf("Enter the no of process:");
    scanf("%d",&n);
    
    for(i= 0;i<n;i++)
    {
        printf("Enter the burst time:\n");
        scanf("%d",&bt[i]);
        printf("Enter the priority:\n");
        scanf("%d",&p[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                tempb = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = tempb;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
   
            }

        }
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
    printf("\nprocsess\tBurst time\tPriority\tWaiting time\tTurnaround time");
    for(i = 0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t",i+1,bt[i],p[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time:%f",awt/n);
    printf("\nAverage turnaroundtime %f",atat/n);
}