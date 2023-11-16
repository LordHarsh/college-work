FCFS

#include <stdio.h>

void fcfs_scheduling(int processes[], int n, int burst_time[]) {

int 
waiting_time[n], turnaround_time[n];

// Calculate waiting time for the first process (it's 0)

waiting_time[0] = 0;

// Calculate waiting time for the rest of the processes

for (int i = 1; i < n; i++) {

waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];

}

// Calculate turnaround time for each process

for (int i = 0; i < n; i++) {

turnaround_time[i] = waiting_time[i] + burst_time[i];

}

// Calculate and display average waiting time and turnaround time

float total_waiting_time = 0, total_turnaround_time = 0;

for (int i = 0; i < n; i++) {

total_waiting_time += waiting_time[i];

total_turnaround_time += turnaround_time[i];

}

float average_waiting_time = total_waiting_time / n;

float average_turnaround_time = total_turnaround_time / n;

printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

for (int i = 0; i < n; i++) {

printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);

}

printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);

printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

}

int main() {

int n;

printf("Enter the number of processes: ");

scanf("%d", &n);

int processes[n];

int burst_time[n];

for (int i = 0; i < n; i++) {

processes[i] = i + 1;

printf("Enter burst time for process P%d: ", i + 1);

scanf("%d", &burst_time[i]);

}




fcfs_scheduling(processes, n, burst_time);

return 0;

}


SJFS

#include <stdio.h>

void sjf_scheduling(int processes[], int n, int burst_time[]) {

int waiting_time[n], turnaround_time[n];

// Sort the processes based on their burst times using a simple sorting algorithm

for (int i = 0; i < n - 1; i++) {

for (int j = 0; j < n - i - 1; j++) {

if (burst_time[j] > burst_time[j + 1]) {

// Swap burst times

int temp_burst = burst_time[j];

burst_time[j] = burst_time[j + 1];

burst_time[j + 1] = temp_burst;

// Swap processes

int temp_process = processes[j];

processes[j] = processes[j + 1];

processes[j + 1] = temp_process;

}

}

}

// Calculate waiting time and turnaround time for the processes

waiting_time[0] = 0;

turnaround_time[0] = burst_time[0];

for (int i = 1; i < n; i++) {

waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];

turnaround_time[i] = waiting_time[i] + burst_time[i];

}

// Calculate and display average waiting time and turnaround time

float total_waiting_time = 0, total_turnaround_time = 0;

for (int i = 0; i < n; i++) {

total_waiting_time += waiting_time[i];

total_turnaround_time += turnaround_time[i];

}

float average_waiting_time = total_waiting_time / n;

float average_turnaround_time = total_turnaround_time / n;

printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

for (int i = 0; i < n; i++) {

printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);

}

printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);

printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

}

int main() {

int n;

printf("Enter the number of processes: ");

scanf("%d", &n);

int processes[n];

int burst_time[n];

for (int i = 0; i < n; i++) {

processes[i] = i + 1;

printf("Enter burst time for process P%d: ", i + 1);

scanf("%d", &burst_time[i]);

}

sjf_scheduling(processes, n, burst_time);

return 0;

}

PRIORITY

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int priority;
    int burst_time;
};

int compare(const void *a, const void *b) {
    return ((struct Process *)a)->priority - ((struct Process *)b)->priority;
}

void priorityScheduling(struct Process processes[], int n) {
    qsort(processes, n, sizeof(struct Process), compare);

    int waiting_time = 0;

    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority, processes[i].burst_time, waiting_time, waiting_time + processes[i].burst_time);
        waiting_time += processes[i].burst_time;
    }
}

int main() {
    struct Process processes[] = {{1, 3, 8}, {2, 1, 6}, {3, 4, 9}, {4, 2, 4}};
    int n = sizeof(processes) / sizeof(processes[0]);
    priorityScheduling(processes, n);
    return 0;
}
