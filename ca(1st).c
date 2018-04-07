#include<stdio.h>
#define N 10
typedef struct
{
      int process_id, arrival_time, burst_time, priority;
      int q, ready;
}s;
typedef struct
{
      int p_id,ra_t,rb_t,rp;
}r;
typedef struct
{
      int fp_id,fa_t,fb_t,fp;
}f;
typedef struct
{
      int pp_id,pa_t,pb_t,pp;
}p;
int Queue(int q) {
      if(q == 0 || q == 1 || q == 2 || q == 3)
      {
            return 1;
      }
      else
      {
            return 2;
      }
}
int main()
{
      int n,m, i, temp_process, time, j, y;
      s temp;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &n);
      s process[n];
      for(i = 0; i < n; i++)
      {
            printf("\nProcess ID:\t");
            scanf("%d", &process[i].process_id);
            printf("Arrival Time:\t");
            scanf("%d", &process[i].arrival_time);
            printf("Burst Time:\t");
            scanf("%d", &process[i].burst_time);
            printf("Process Priority:\t");
            scanf("%d", &process[i].priority);
            //temp_process = process[i].priority;
            //process[i].q = Queue(temp_process);
            //process[i].ready = 0;
      } r proces[n];f pro[n];p pr[n];
      for(i=0;i<n;i++)
      {
            if(process[i].priority>0 && process[i].priority<10)
            {
                
                  round_robin();
            }
            else if(process[i].priority>10 && process[i].priority<20)
            {    
                  fcfs();
            }
            else
            {
            
                  prior();
            }
      }
      return 0;
 }
round_robin()
 {
      int temp1;
      printf("round_robin :\t");
      printf("quantum time of 4 seconds:\t");
      int static quantum=4;
      return 0;
 }
fcfs()
{
      printf("first come first serve :\t");
      printf("quantum time of 10 seconds:\t");
      
}
prior()
{
      printf("priority scheduling :\t");
      printf("quantum time of 10 seconds:\t");
      int static quant=10;
      return 0;
}}





