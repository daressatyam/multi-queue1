#include<stdio.h>//header file  
#include<conio.h>//

int roundrobin(int a, int b);
int fcfs(int a, int b);
int priority(int a , int b);
int waiting_time[20];
int q1,q2,q3;
int main()
{ printf("\n\t\t\t\t:-----------------------MULTI QUEUE SCHEDULING-------------------------------:\t\t");
	//int q1,q2,q3;
	printf("\n\t\tEnter number of processes in queue 1\t\t::\t\t");
	scanf("%d",&q1);
	printf("\n\t\tEnter number of processes in queue 2\t\t::\t\t");
	scanf("%d",&q2);
	printf("\n\t\tEnter number of processes in queue 3\t\t::\t\t");
	scanf("%d",&q3);
	int p1,p2,p3;
	
	char name[3];
	printf("\n\t\tEnter priority of queue 1\t\t::\t\t");
	scanf("%d",&p1);
	while(1)
	{
	printf("\n\t\tEnter priority of queue 2\t\t::\t\t");
	scanf("%d",&p2);
	if(p1!=p2)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	while(1)
	{
	printf("\n\t\tEnter priority of queue 3\t\t::\t\t");
	scanf("%d",&p3);
	if(p1!=p3&&p2!=p3)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	if (p1<p2&&p1<p3)
	{
		roundrobin(q1,1);
		if(p2<p3)
		{
			priority(q2,2);
			fcfs(q3,3);
		}
		else
		{
			priority(q3,3);
			fcfs(q2,2);
		}
	}
	else if(p2<p1&&p2<p3)
	{
		roundrobin(q2,2);
		if(p1<p3)
		{
			priority(q1,1);
			fcfs(q3,3);
		}
		else
		{
			priority(q3,3);
			fcfs(q1,1);
		}
	}
	else
	{
		roundrobin(q3,3);
		if(p1<p2)
		{
			priority(q1,1);
			fcfs(q2,2);
		}
		else
		{
			priority(q2,2);
			fcfs(q1,1);
		}
	}
}


int priority(int a,int b)
{

}


int fcfs(int c, int d)
{
}

int roundrobin(int e, int f)
{
     
}
