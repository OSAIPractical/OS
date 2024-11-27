//fcfs without arrival time
#include<stdio.h>
#include<string.h>
#define max 30
	int main()
	{
	    int i,j,n,bt[max],wt[max],tat[max];
	    float awt=0,atat=0;
	    printf("Enter number of process");
	    scanf("%d",&n);
	    printf("Enter burst time of process");
	     for(i=0;i<n;i++)
	       scanf("%d",&bt[i]);
	     printf("process\t burst time\t  waiting time\t turn arround time\n");
	     for(i=0;i<n;i++)
	     {
	        wt[i]=0;
	        tat[i]=0;
	         for(j=0;j<i;j++)
	         { 
	           wt[i]=wt[i]+bt[i];
	         }
	        tat[i]=wt[i]+bt[i];
	        awt=awt+wt[i];
	        atat=atat+tat[i];
	        printf("%d\t%d\t\t%d\t\t%d\t\t\n",i+1,bt[i],wt[i],tat[i]);
	     }
	     awt=awt/n;
	     atat=atat/n;
	     printf("Average waiting time=%f\n",awt);
	     printf("Average turn arround time=%f\n",atat);
	}