#include <stdio.h>
#include <stdlib.h>
int mutex=1,full,size=10,x=0,n;
    void producer()
    {
        --mutex;
        ++full;
        --size;
        x++;
        printf("Producer produced item%d",x);
        ++mutex;
    }
    void consumer()
    {
        --mutex;
        --full;
        ++size;
        printf("Consumer consumed item%d",x);
        x--;
        ++mutex;
    }
    void main()
{
    
    do{
        printf("\nChoose your choice:\n");
        printf("1.Produce\n2.Consumer\n3.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                if((mutex == 1) && (size!=0))
                {
                    producer();
                }
                else
                {
                    printf("Buffer is full");
                }
                break;
            case 2:
                if((mutex == 1) && (full != 0))
                {
                    consumer();
                }
                else{
                    printf("Buffer is empty");
                }
                break;
            case 3:break;

        }   

    }while(n!=0);
}