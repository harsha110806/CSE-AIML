#include<stdio.h>

int main()
{
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10], finish[10];
    int safeseq[10];
    int np, nr, i, j, k = 0, count = 0;

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &np, &nr);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < np; i++)
        for(j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i = 0; i < np; i++)
        for(j = 0; j < nr; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < nr; i++)
        scanf("%d", &avail[i]);

    // Calculate Need
    for(i = 0; i < np; i++)
        for(j = 0; j < nr; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize
    for(i = 0; i < np; i++)
        finish[i] = 0;

    for(i = 0; i < nr; i++)
        work[i] = avail[i];

    // Banker's Algorithm
    while(count < np)
    {
        int found = 0;

        for(i = 0; i < np; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                // Check if need <= work
                for(j = 0; j < nr; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                // If safe to execute
                if(flag == 1)
                {
                    for(j = 0; j < nr; j++)
                        work[j] += alloc[i][j];

                    safeseq[k++] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        // If no process found ? unsafe
        if(found == 0)
        {
            printf("System is NOT in safe state\n");
            return 0;
        }
    }

    printf("Safe Sequence: ");
    for(i = 0; i < np; i++)
        printf("P%d ", safeseq[i]);

    return 0;
}
