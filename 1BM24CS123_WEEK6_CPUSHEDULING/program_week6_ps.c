#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int tickets;
    int remaining_time;
} Process;

int main() {
    int n, i, total_tickets = 0;
    Process p[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter tickets for process %d: ", p[i].id);
        scanf("%d", &p[i].tickets);

        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].remaining_time);

        total_tickets += p[i].tickets;
    }

    srand(time(NULL));

    printf("\nExecution Order:\n");

    // Continue until all processes finish
    while (1) {
        int all_done = 1;

        for (i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                all_done = 0;
                break;
            }
        }

        if (all_done)
            break;

        // Pick a random ticket
        int winning_ticket = rand() % total_tickets;
        int ticket_sum = 0;

        for (i = 0; i < n; i++) {
            ticket_sum += p[i].tickets;

            if (ticket_sum > winning_ticket) {
                if (p[i].remaining_time > 0) {
                    printf("Process %d is running\n", p[i].id);
                    p[i].remaining_time--;

                    // If process finishes, remove its tickets
                    if (p[i].remaining_time == 0) {
                        total_tickets -= p[i].tickets;
                        p[i].tickets = 0;
                        printf("Process %d completed\n", p[i].id);
                    }
                }
                break;
            }
        }
    }

    printf("\nAll processes completed.\n");
    return 0;
}
