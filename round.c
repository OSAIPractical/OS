//Implementation of round robin without arrival time
#include<stdio.h>
#include<conio.h>
#define max 30
	int main()
	{
	    int i,n,qt,count=0,temp,a=0,bt[max],wt[max],tat[max],rem_bt[max];
	    float awt=0,atat=0;
	    printf("Enter number of process");
	    scanf("%d",&n);
	    printf("Enter burst time of process");
	     for(i=0;i<n;i++)
	     {
	          scanf("%d",&bt[i]);
	          rem_bt[i]=bt[i];
	     }
	     printf("Enter quantum time");
	     scanf("%d",&qt);
	     while(1)
	     {
	         for(i=0,count=0;i<n;i++)
	         {
	             temp=qt;
	             if(rem_bt[i]==0)
	             {
	                 count++;
	                 continue;
	             }
	             if(rem_bt[i]>qt)
	                 rem_bt[i]=rem_bt[i]-qt;
	             else 
	              if(rem_bt[i]>=0)
	                 {
	                     temp=rem_bt[i];
	                     rem_bt[i]=0;
	                 }
	                 a=a+temp;
	                 tat[i]=a;
	             }
	             if(n==count)
	                 break;
	         }
	          printf("process\t burst time\t  waiting time\t turn arround time\n");
	     for(i=0;i<n;i++)
	     {
	         wt[i]=tat[i]-bt[i];
	         awt=awt+wt[i];
	         atat=atat+tat[i];
	           printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	     }
	     awt=awt/n;
	     atat=atat/n;
	     printf("Average waiting time=%f\n",awt);
	     printf("Average turn arround time=%f\n",atat);
	}