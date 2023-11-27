#include<stdio.h>
main()
{
	int i,j,n,p[20],t;
	printf("\nEnter no of process : ");
	scanf("%d",&n);
	printf("\nEnter the process : ");
	for(i=0;i<n;i++)
	    scanf("%d",&p[i]);
	int at[n],bt[n],tat[n],wt[n],temp[n];
	float awt=0,atat=0;
	printf("\nEnter arriaval time: ");
	for(i=0;i<n;i++)
	   scanf("%d",&at[i]);
	printf("\nEnter brust time: ");
	for(i=0;i<n;i++)
	   scanf("%d",&bt[i]);
	temp[0]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(bt[j]>bt[j+1] && at[j]>at[j+1])
			{
				
				t=bt[j];
				bt[j]=bt[j+1];
                bt[j+1]=t;
				
				t=at[j];
				at[j]=at[j+1];
                at[j+1]=t;
                
                t=p[j];
				p[j]=p[j+1];
                p[j+1]=t;         
				
			}
		}
	}
	
	
	printf("\nPRO\tBT\tAT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		wt[i]=0;
		tat[i]=0;
		temp[i+1]=temp[i]+bt[i];
		wt[i]=temp[i]-at[i];
		tat[i]=wt[i]+bt[i];
		awt+=wt[i];
		atat+=tat[i];
		printf("\np[%d]\t%d\t%d\t%d\t%d\n",p[i],bt[i],at[i],tat[i],wt[i]);
	}
	
	printf("\nGANTT\n.");
	for(i=0;i<n;i++)
	{
		printf(" %d <p[%d]> %d ",temp[i],p[i],temp[i+1]);
	}
	printf("\n\n");
	
	awt/=n;
	atat/=n;
	printf("\nAvg waiting time :%f",awt);
	printf("\nAvg TAT time :%f",atat);	
}



