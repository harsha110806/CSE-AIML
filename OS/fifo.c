#include <stdio.h>

int main() {
    int pages[20], frames[5];
    int n, m, i, j, k;
    int fault = 0, index = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter pages: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    // Initialize frames
    for(i = 0; i < m; i++)
    {
        frames[i] = -1;
	}
    // FIFO Logic
    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already exists
        for(j = 0; j < m; j++) {
            if(pages[i] == frames[j]) {
                found = 1;
                break;
            }
        }

        // If not found ? Page Fault
        if(found == 0) {
            frames[index] = pages[i];
            index = (index + 1) % m;
            fault++;

            // Print frames
            for(k = 0; k < m; k++)
                printf("%d\t", frames[k]);
            printf("\n");
        }
    }

    printf("Total Page Faults = %d", fault);
    return 0;
}
