#include <stdio.h>
#include <stdlib.h>
#define s 50
void main()
{
    int n,tq,bt[s],at[s],i,tt=0,rt[s],flag =0,remain;
    float awt=0,atat=0;
    printf("Enter the no of procesess:");
    scanf("%d",&n);
    printf("Enter the time quantum:");
    scanf("%d",&tq);
    remain = n;
     printf("Enter the arrival time & burst time: \n");
    for(i= 0;i<n;i++)
    {
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }
    for(i=0;remain!=0;)
    {
        if((rt[i]>0) && (rt[i]<=tq))
        {
            tt += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i]>0)
        {
            tt += tq;
            rt[i] -= tq;
        }
        if (flag == 1 && rt[i] == 0)
        {
            remain--;
            awt += tt - at[i] - bt[i];
            atat += tt - at[i];
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= tt)
            i++;
        else
            i=0;

    }
     printf("\nAvg Waiting time : %f", awt / n);
    printf("\nAvg TurnAround time : %f", atat / n);


}