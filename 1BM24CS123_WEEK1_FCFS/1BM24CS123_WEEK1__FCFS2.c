#include<stdio.h>
int main()
{
    int n,i;
    printf("enter the no.of process:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],et[n],tat[n],wt[n];
    for(i=0;i<n;i++)
    {
         printf("\nenter the Process %d details:",i+1);
        printf("\nenter arrival time and burst time:");
        scanf("%d %d",&at[i],&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            ct[i]=at[i]+bt[i];
        }
        else{
            if(ct[i-1]<at[i])
                ct[i]=at[i]+bt[i];
            else
                ct[i]=ct[i-1]+bt[i];
        }
        et[i]=bt[i];
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tET\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],et[i],tat[i],wt[i]);
    }
}
