#include <stdio.h>
    int mutex=1,rc=0,r=0,w=0;
    void reader()
    {
        mutex --;
        rc ++;
        r = 1;
        printf("Reading (%d) reading ...",rc);
        mutex ++;
    }
    void write()
    {
        mutex --;
        w = 1;
        printf("Writing (%d) writing ...",w);
        mutex ++;
    }
    void main()
    {
        int n;
     do{
        printf("Enter the choice:");
        printf("1.READ\n2.WRITE\n3.Delete read \n4.Delete write\n5.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            if(mutex==1 && w==0)
            {
                reader();
            }
            else
            {
                printf("Cannot read, Already process is writing");
            }
            break;
            case 2:
            if(mutex == 1 && r==0 && w==0)
            {
                write();
            }
            else
            {
                printf("Cannot write,
                Already process is reading");
            }
            break;
            case 3:
            if(rc>1)
            {
                rc--;
                printf("Readers(%d)",rc);
            }
            else{
                r = 0;
                rc = 0;
                printf("Reader removed");
            }
            break;
            case 4:
            if(w=1)
            {
                w=0;
                printf("Writed removed");
            }
            break;
            case 5:break;


        }
    }while(n!=0);
}