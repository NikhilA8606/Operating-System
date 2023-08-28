#include <stdio.h>
#include <stdlib.h>
#define s 50
void main()
{
    int n,i,j,m,alloc[s][s],max[s][s],avail[s],need[s][s],finish[s],k,flag,safe[s],ind=0,x;
    printf("Enter the no of process:");
    scanf("%d",&n);
    printf("Enter the no of resourcses:");
    scanf("%d",&m);
    printf("Enter the Allocation matrix:\n");
    for(i = 0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the Max matrix:\n");
    for(i = 0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available matrix:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    printf("The need matrix is :\n");
    for(i = 0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t",need[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        finish[i] = 0;
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag = 1;
                        break;
                    }  
                }
                if(flag == 0)
                {
                    safe[ind++] = i;
                    for(x=0;x<m;x++)
                    {
                        avail[x] += alloc[i][x];
                    }
                    finish[i] = 1;
                }
                
            }
        }
    }
    printf("\nThe safe sequence is:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t",safe[i]);
    }
}