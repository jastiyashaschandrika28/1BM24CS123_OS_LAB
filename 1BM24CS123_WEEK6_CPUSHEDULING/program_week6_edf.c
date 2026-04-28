#include <stdio.h>

#define MAX 10

struct process {
    int id;
    int capacity;   // execution time
    int period;
    int deadline;

    int remaining;  // remaining execution
    int next_arrival;
    int abs_deadline;
};

// GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n, i, t;

    struct process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("Enter capacity: ");
        scanf("%d", &p[i].capacity);

        printf("Enter period: ");
        scanf("%d", &p[i].period);

        printf("Enter deadline: ");
        scanf("%d", &p[i].deadline);

        p[i].remaining = 0;
        p[i].next_arrival = 0;
        p[i].abs_deadline = 0;
    }

    // Calculate hyperperiod
    int hyper = p[0].period;
    for(i = 1; i < n; i++) {
        hyper = lcm(hyper, p[i].period);
    }

    printf("\nHyperperiod = %d\n", hyper);

    printf("\nTime\tProcess\n");

    // Time simulation
    for(t = 0; t < hyper; t++) {

        // check arrivals
        for(i = 0; i < n; i++) {
            if(t == p[i].next_arrival) {
                p[i].remaining = p[i].capacity;
                p[i].abs_deadline = t + p[i].deadline;
                p[i].next_arrival += p[i].period;
            }
        }

        // select process with earliest deadline
        int selected = -1;
        int min_deadline = 9999;

        for(i = 0; i < n; i++) {
            if(p[i].remaining > 0 && p[i].abs_deadline < min_deadline) {
                min_deadline = p[i].abs_deadline;
                selected = i;
            }
        }

        // execute or idle
        if(selected != -1) {
            printf("%d\tP%d\n", t, p[selected].id);
            p[selected].remaining--;
        } else {
            printf("%d\tIDLE\n", t);
        }
    }

    return 0;
}
