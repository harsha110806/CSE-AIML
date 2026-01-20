#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], ct[n];
    int completed = 0, time = 0, smallest;
    int min = 9999;

    // Input arrival and burst time
    for (i = 0; i < n; i++) {
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // Remaining time initially = burst time
    }

    // SRTF logic
    while (completed != n) {
        smallest = -1;
        min = 9999;

        // Find the process with the smallest remaining time among arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < min && rt[i] > 0) {
                min = rt[i];
                smallest = i;
            }
        }

        // Execute selected process for 1 unit time
        rt[smallest]--;
        time++;

        // If process is completed
        if (rt[smallest] == 0) {
            completed++;
            ct[smallest] = time; // completion time

            tat[smallest] = ct[smallest] - at[smallest];  // TAT = CT - AT
            wt[smallest] = tat[smallest] - bt[smallest];  // WT = TAT - BT
        }
    }

    // Display results
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}

