#include <stdio.h>
#define s 50
void main()
{
    int n,p,a[s],b[s],vis[s],i,j;
    printf("Enter the no of blocks:");
    scanf("%d",&n);
    printf("Enter the no of processes:");
    scanf("%d",&p);
    printf("Enter the size of blocks:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter size of procesess:");
    for(i=0;i<p;i++)
    {
        vis[i] = 0;
        scanf("%d",&b[i]);
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]>b[i])
            {
                vis[i] = a[j];
                a[j] = 0;
                break;
            }
        }
    }
    printf("Status...\n");
    for(i=0;i<p;i++)
    {
        if(vis[j]==0)
        {
            printf("The process %d is waiting\n",b[i]);
        }
        else{
            printf("The %d process is inserted in %d block\n",b[i],vis[i]);
        }
    }
}