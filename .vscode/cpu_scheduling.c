// //shortest job first

// #include <stdio.h>

// struct process {
//     int burst, wait, no;
// } p[20] = {0, 0};

// int main() {
//     int n, i, j, totalwait = 0, totalturn = 0;

//     printf("\nEnter The No Of Process: ");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++) {
//         printf("Enter The Burst Time (in ms) For Process #%2d: ", i + 1);
//         scanf("%d", &p[i].burst);
//         p[i].no = i + 1;
//     }

//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n - i - 1; j++) {
//             if (p[j].burst > p[j + 1].burst) {
//                 // Swap burst times
//                 int temp_burst = p[j].burst;
//                 p[j].burst = p[j + 1].burst;
//                 p[j + 1].burst = temp_burst;

//                 // Swap process numbers
//                 int temp_no = p[j].no;
//                 p[j].no = p[j + 1].no;
//                 p[j + 1].no = temp_no;
//             }
//         }
//     }

//     printf("\nProcess \t Waiting Time \t Turnaround Time\n");
//     for (i = 0; i < n; i++) {
//         printf("Process # %-12d%-15d%-15d\n", p[i].no, p[i].wait, p[i].wait + p[i].burst);
//         p[i + 1].wait = p[i].wait + p[i].burst;
//         totalwait += p[i].wait;
//         totalturn += p[i].wait + p[i].burst;
//     }

//     printf("\nAverage\n---------\n");
//     printf("Waiting Time: %.2f ms\n", totalwait / (float)n);
//     printf("Turnaround Time: %.2f ms\n\n", totalturn / (float)n);

//     return 0;
// }

// // FIRST COME FIRST SERVED (FCFS) 
// // Program: 
// #include<stdio.h> 

// struct process 
// { 
//     int burst, wait; 
// } p[20] = {{0, 0}}; 

// int main() 
// { 
//     int n, i, totalwait = 0, totalturn = 0; 
//     printf("\nEnter The No Of Process: "); 
//     scanf("%d", &n); 
    
//     for(i = 0; i < n; i++) 
//     { 
//         printf("Enter The Burst Time (in ms) For Process #%2d: ", i+1); 
//         scanf("%d", &p[i].burst); 
//     } 
    
//     printf("\nProcess \t Waiting Time \t TurnAround Time\n"); 
//     for(i = 0; i < n; i++) 
//     { 
//         printf("Process #%-12d%-15d%-15d\n", i+1, p[i].wait, p[i].wait + p[i].burst); 
//         if (i < n - 1)
//             p[i+1].wait = p[i].wait + p[i].burst; 
//         totalwait += p[i].wait; 
//         totalturn += p[i].wait + p[i].burst; 
//     } 
    
//     printf("\nAVERAGE\n---------\n"); 
//     printf("Waiting Time: %.2f ms\n", totalwait / (float)n); 
//     printf("TurnAround Time: %.2f ms\n\n", totalturn / (float)n); 
    
//     return 0; 
// }

// // Output: 
// // Enter The No Of Process  :3 
// // Enter The Burst Time (in ms) For Process # 1 :10 
// // Enter The Burst Time (in ms) For Process # 2 :30 
// // Enter The Burst Time (in ms) For Process # 3 :20 
// // Process          
// // Process # 1           
// // Process # 2           
// // Process # 3           
// // AVERAGE --------- 
// // Waiting Time  TurnAround Time 
// // (in ms)         
// // (in ms) 
// // 0              
// // 10             
// // 40             
// // 10 
// // 40 
// // 60 
// // Waiting    Time : 16.666667 ms 
// // TurnAround Time : 36.666667 ms 

//priority scheduling


// #include <stdio.h>

// struct process{
//     int burst, wait, no, priority;
// }p[20] = {0, 0};

// int main(){
//     int n, i, j, totalWait = 0, totalTurn = 0;
//     printf("Enter the number of processes : ");
//     scanf("%d", &n);


//     for(i=0;i<n;i++){
//         printf("Enter the burst time (in ms) for process %2d : ", i+1);
//         scanf("%d", &p[i].burst);
//         printf("Enter the priority of process %2d : ", i+1);
//         scanf("%d", &p[i].priority);
//         p[i].no = i+1;
//     }

//     for(i=0;i<n;i++)
//     for(j=0;j<n-i-1;j++)
//     if(p[j].priority>p[j+1].priority){
//         p[j].priority^=p[j+1].priority^=p[j].priority^=p[j+1].priority;
//         p[j].burst^=p[j+1].burst^=p[j].burst^=p[j+1].burst;
//         p[j].no^=p[j+1].no^=p[j].no^=p[j+1].no;
//     }

//     printf("\nProcess\t\t Waiting Time (in ms) \t\t Turn Around Time (in ms)\n");
//     for(i=0;i<n;i++){
//         printf("Process # %2d %15d %25d\n", p[i].no, p[i].wait, p[i].wait + p[i].burst);
//         p[i+1].wait = p[i].wait + p[i].burst;
//         totalWait += p[i].wait;
//         totalTurn += p[i].wait + p[i].burst;
//     }

    
//     printf("\nAverage---------------\n");
//     printf("Waiting Time = %f\n", totalWait / (float)n);
//     printf("Turn Around Time = %f", totalTurn / (float)n);

//     return 0;
// }






 
// ROUND ROBIN SCHEDULING 
// Program: 
// #include<stdio.h> 
// struct process{ 
// int burst,wait,comp,f; 
// }p[20]={0,0}; 
// int main(){ 
// int 
// n,i,j,totalwait=0,totalturn=0,quantum,flag=1,
//  time=0; 
// printf("\nEnter The No Of Process         :"); 
// scanf("%d",&n); 
// printf("\nEnter The Quantum time (in ms)  :"); 
// scanf("%d",&quantum); 
// for(i=0;i<n;i++){ 
// printf("Enter The Burst Time (in ms) For Process #%2d :",i+1); 
// scanf("%d",&p[i].burst); 
// p[i].f=1; 
// } 
// printf("\nOrder Of Execution \n"); 
// printf("\nProcess      Starting     Ending     Remaining"); 
// printf("\n       Time        Time        Time"); 
// while(flag==1){ 
// flag=0; 
// for(i=0;i<n;i++){ 
// if(p[i].f==1){ 
// flag=1; 
// j=quantum; 
// if((p[i].burst-p[i].comp)>quantum){ 
// p[i].comp+=quantum; 
// } 
// else{ 
// p[i].wait=time-p[i].comp; 
// j=p[i].burst-p[i].comp; 
// p[i].comp=p[i].burst; 
// p[i].f=0; 
// } 
// printf("\nprocess # %-3d  %-10d   %-10d   %-10d",i+1,time,time+j,p[i].burst-p[i].comp); 
// time+=j; 
// }}} 
// printf("\n\n------------------"); 
// printf("\nProcess \t Waiting Time  TurnAround Time "); 
// for(i=0;i<n;i++){ 
// printf("\nProcess # %-12d%-15d%15d",i+1,p[i].wait,p[i].wait+p[i].burst); 
// totalwait=totalwait+p[i].wait; 
// totalturn=totalturn+p[i].wait+p[i].burst; 
// } 
// printf("\n\nAverage\n------------------"); 
// printf("\nWaiting    Time : %f ms",totalwait/(float)n); 
// printf("\nTurnAround Time : %f ms\n\n",totalturn/(float)n); 
// return 0; 
// } 