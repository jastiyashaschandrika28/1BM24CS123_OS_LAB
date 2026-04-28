#include<stdio.h>
struct process
{

    int pid,at,bt,ct,pri,tat,wt;
};
int main()
{
    int n,i,j,complete=0,time=0,min,visited[100];
    float avg_wt,avg_tat;
    struct process p[100];
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the arrival times:");
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        scanf("%d",&p[i].at);
    }
      printf("Enter the burst times:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].bt);
    }
      printf("Enter the priority times:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].pri);
        visited[i]=0;
    }
    while(complete<n)
    {
        min=-1;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=time && visited[i]==0)
            {
                if(min == -1 || p[i].pri<p[min].pri)
                    min=i;
            }
        }
        if(min == -1)
            time++;
        else{
            time+=p[min].bt;
            p[min].ct=time;
            p[min].tat=p[min].ct-p[min].at;
            p[min].wt=p[min].tat-p[min].bt;
            visited[min]=1;
            complete++;


        }
    }
    for(i=0;i<n;i++)
    {
        avg_wt +=p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_wt=avg_wt/n;
    avg_tat=avg_tat/n;
    printf("pid \t AT \t WT \t CT \t TAT,\t WT \n");
    for(i=0;i<n;i++)
    {
       printf("%d \t %d \t %d \t %d \t %d \t %d \n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }

      printf("average of tat= %f\n",avg_tat);
      printf("average waiting time %f ",avg_wt);
      return 0;


}
