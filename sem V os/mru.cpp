//#1 MRU
#include <stdio.h>
int MRU(int time[],int f) 
{
    int max=time[0],pos=0;
    for (int i=1;i<f;i++)
    {
        if (max<time[i]) 
        {
            max=time[i];
            pos=i;
        }
    }
    return pos;
}
int main() 
{
    int n,f,rs[100],time[20],frame[20],flag1,flag2,fault=0,hit=0;

    printf("Enter Size of Reference String: ");
    scanf("%d", &n);

    printf("Enter Reference String:");
    for (int i = 0; i < n; i++) 
    {
      scanf("%d", &rs[i]);
    }

    printf("Enter Frame Size: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++)
    {
      frame[i] = -1;
      time[i] = -1;
    }

    for (int i=0;i<n;i++) 
    {
        flag1=flag2=0;

        for (int j=0;j<f;j++) 
        {
            if (frame[j] == rs[i])
            {
                hit++;
                flag1=flag2=1;
                time[j]=i+1;
                break;
            }
        }
   if(flag1==0)
   {
      for(int j=0; j<f; j++)
      {
         if(frame[j]==-1)
         {
          flag2=1;
          frame[j]=rs[i];
          fault++;
          time[j]=i+1;
          break;
         }
      }
   }
    if (flag2 == 0)
    {
      int pos = MRU(time, f);
      frame[pos] = rs[i];
      time[pos] = i+1;
      fault++;
    }
    printf("\n");
    for (int j=0;j<f;j++)
    {
      if(frame[j]!=-1)
      {
        printf("%d\t", frame[j]);
      }
      else
      {
        printf("-\t");
      }
    }
    }
    printf("\nNo of Page Faults: %d\nNo of Page Hits: %d", fault, hit);
    return 0;
}
