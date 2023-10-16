#include<stdio.h>
struct node
{
	int pno;
	int count;
};
struct node f[10];
int i,fr,j;

int page(int pno1)
{
	for(i=0;i<fr;i++)
		if(f[i].pno==pno1)
		  return i;
    return -1;		  		
}

int lru()
{
	int min=0;
	for(i=0;i<fr;i++)
	{
		if(f[i].count<f[min].count)
		{
			min=i;
		}
	}
	return min;
}

main()
{
	int len,flag=0,pno1,curr=1,p;
	int a[20],pf=0,hit=0;
	printf("\nEnter no of frame : ");
	scanf("%d",&fr);
	printf("\nEnter length of ref string : ");
	scanf("%d",&len);
	printf("\nEnter ref string : ");
	for(i=0;i<len;i++)
	   scanf("%d",&a[i]);
	for(i=0;i<fr;i++)   
	{
		f[i].pno=-1;
		f[i].count=-1;
	}
	printf("\npage\tframe\tpfault\n");
	for(p=0;p<len;p++)
	{
		pno1=a[p];
		j=page(pno1);
		flag=0;
		if(j==-1)
		{
			j=lru();
			f[j].pno=pno1;
			pf++;
			flag=1;	
		}
		f[j].count=curr;
		curr++;
		printf("\n%d\t",pno1);
		for(i=0;i<fr;i++)
		    printf(" %d ",f[i]);
		if(flag==1)    
		  printf("\t\tYES");
		else
		{
			printf("\t\tHit");
			hit++;
		  }  
	}
	printf("\nPage fault:%d",pf);
	printf("\nPage fault:%d",hit);
	
}























