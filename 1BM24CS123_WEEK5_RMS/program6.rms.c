#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int capacity;
    int period;
    int remaining;
    int next_arrival;
} Process;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
int find_hyperperiod(Process p[], int n) {
    int result = p[0].period;
    for (int i = 1; i < n; i++) {
        result = lcm(result, p[i].period);
    }
    return result;
}

int main() {
    Process p[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcess %d\n", i + 1);
        printf("Enter capacity: ");
        scanf("%d", &p[i].capacity);

        printf("Enter period: ");
        scanf("%d", &p[i].period);

        p[i].remaining = 0;
        p[i].next_arrival = 0;
    }


    int hyperperiod = find_hyperperiod(p, n);

    printf("\nHyperperiod (LCM) = %d\n", hyperperiod);

    printf("\nTime\tRunning Process\n");


    for (int t = 0; t < hyperperiod; t++) {


        for (int i = 0; i < n; i++) {
            if (t == p[i].next_arrival) {
                p[i].remaining = p[i].capacity;
                p[i].next_arrival += p[i].period;
            }
        }


        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                if (selected == -1 || p[i].period < p[selected].period) {
                    selected = i;
                }
            }
        }


        if (selected != -1) {
            printf("%d\tP%d\n", t, p[selected].id);
            p[selected].remaining--;
        } else {
            printf("%d\tIdle\n", t);
        }
    }

    return 0;
}
