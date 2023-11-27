#include<stdio.h>
#include<stdlib.h>

struct fnode
{

    int pno;

};

struct fnode frames[10];
int fr;
int pagefound (int pno1)
{

    for (int i=0; i<fr; i++)
        if(frames[i].pno==pno1)
            return 1;
    return 0;
}

void main()
{
    int ref_str[30];
    int pfct=0,i,pno1, p, flag=0;
    int len,cnt=0;
    printf("\n Enter no. of frames: ");
    scanf("%d", &fr);
    printf("\n Enter length of referencestring: ");
    scanf("%d",&len);
    printf("\n Enter  referencestring: ");
    for (i=0; i<len; i++)
        scanf("%d",&ref_str[i]);

    for (i=0; i<fr; i++)
        frames[i].pno=-1;

    printf("\nPageNo\t  pageframes\t\tpagefault");

    for (p=0; p<len; p++)
    {
        pno1=ref_str[p];
        flag=0;

        if (pagefound (pno1)==0)
        {
            frames[pfct%fr].pno=pno1;

            pfct++;

            flag=1;

        }

        printf("\n %d\t",pno1);
        for (i=0; i<fr; i++)
            printf("  %d ", frames[i]);


        if(flag==1)
            printf("\t\t PF");

        else
        {
            printf("\t\t HIT");
            cnt++;
        }
        //  printf("\t%d",pfct);

    }
    printf("\n Total No. of page fault : %d", pfct);
    printf("\n Total No. of page Hits : %d", cnt);

}
