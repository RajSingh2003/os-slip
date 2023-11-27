#include<stdio.h>
#include<stdlib.h>


void main()
{   
    int i,n,j;
    printf("\n Enter number of processes : ");
    scanf("%d",&n);
    int at[n],bt[n],rt[n],ct,smallest,remain=0,time,temp;
    float sum_wt=0,sum_tat=0;
    int g;


    for (i=0; i<n; i++)
    {
        printf("\n Enter arival time for process  %d:  ",i+1);
        scanf("%d",&at[i]);

    }


    for (i=0; i<n; i++)
    {
        printf("\n\n Enter burst time for processs %d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];

    }

    printf("\n pro\tat\tbt\tTat\twt\tGC");
    for (time=0; remain != n; time++)
    {
        for (i=0; i<n; i++)
        {
            if(at[i] <= time && rt[i])
                smallest=i;
        }
        rt[smallest]--;
        if(rt[smallest]==0)
        {
            remain++;
            ct=time+1;
            g=smallest +1 ;
         // printf("\ng chart \n");
           // printf("%d\t",g);
            //printf("  ");
            
            printf("\n p[%d]\t%d\t%d\t%d\t%d\tp[%d]",smallest+1,at[smallest],bt[smallest],ct-at[smallest],ct-bt[smallest]-at[smallest],g);
           // printf("\t%d\t",g);
            sum_tat=sum_tat+ ct-at[smallest];
            sum_wt=sum_wt+ct-bt[smallest]-at[smallest];

        }



    }
    //for (i=0; i<n; i++)
        // printf("\n\n%d",g);
    
    sum_wt/=n;
    sum_tat/=n;
    printf("\n Average waiting time : %f ",sum_wt);
    printf("\n Average turn around  time : %f ",sum_tat);

}
