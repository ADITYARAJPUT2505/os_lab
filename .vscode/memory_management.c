// Program: First Fit Memory Allocation

#include <stdio.h>

struct process {
    int size;
    char name[20];
    int id;
} p[20] = {0, 0};

struct block {
    int size;
    int id;
} b[20] = {0, 0};

int main() {
    int nb, np, i, j, totalwait = 0, totalturn = 0, quantum = 4, flag = 1, time = 0;

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    for (i = 0; i < nb; i++) {
        printf("Enter the size of Block #%d: ", i + 1);
        scanf("%d", &b[i].size);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++) {
        printf("Enter the name of process #%d: ", i + 1);
        scanf("%s", p[i].name);
        printf("Enter the size of process #%d: ", i + 1);
        scanf("%d", &p[i].size);
    }

    for (i = 0; i < np; i++) {
        for (j = 0; j < nb; j++) {
            if (b[j].id == 0 && p[i].size <= b[j].size) {
                b[j].id = i + 1;
                p[i].id = j + 1;
                flag = 1;
                break;
            }
        }
    }

    printf("\nBlock\n-----------\n");
    printf("Block ID   Block Size   Process Name   Process Size\n");

    for (i = 0; i < nb; i++) {
        if (b[i].id)
            printf("%-10d%-13d%-15d%-13d\n", b[i].id, b[i].size, p[b[i].id - 1].id, p[b[i].id - 1].size);
        else
            printf("%-10s%-13d%-15s%-13s\n", "Empty", b[i].size, "Empty", "Empty");
    }

    printf("\nProcess\n-----------\n");
    printf("Process ID   Process Size   Block ID   Block Size\n");

    for (i = 0; i < np; i++) {
        if (p[i].id)
            printf("%-12d%-15d%-11d%-11d\n", i + 1, p[i].size, b[p[i].id - 1].id, b[p[i].id - 1].size);
        else
            printf("%-12d%-15d%-11s%-11s\n", i + 1, p[i].size, "Waiting", "Waiting");
    }

    return 0;
}
