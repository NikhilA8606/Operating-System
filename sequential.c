#include <stdio.h>
#define  s 50
void main()
{
    int n,i,bt[s],sb[s],xj,c[s][s],x,tmp[s],j;
    printf("Enter the no of files:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the block size:");
        scanf("%d",&bt[i]);
        printf("Enter the starting block:");
        scanf("%d",&sb[i]);
        tmp[i] = sb[i];
        
        for(j=0;j<bt[i];j++)
        {
            c[i][j] = sb[i]++;
        }
    }
    printf("\nFile no\tStarting block\t Block size");
    for(i=0;i<n;i++)
    {
        printf("\n");
        printf("%d\t%d\t%d",i,tmp[i],bt[i]);
        
    }

    printf("\nWhich file?");
    scanf("%d",&x);
    printf("The block size is %d\n",bt[x]);
    printf("Elements are:");
    for(i=0;i<bt[x];i++)
    {
        printf("%d\t",c[x][i]);
    }
    
  
}