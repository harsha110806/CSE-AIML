#include<stdio.h>

int main()
{
    int p[20], q[5], x[5];
    int n, m, i, j, k, l = 0;
    int fault = 0, found;
    int a, b, c, max, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter pages: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    // Initialize frames
    for(i = 0; i < m; i++)
        q[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check for hit
        for(j = 0; j < m; j++)
        {
            if(p[i] == q[j])
            {
                found = 1;
                break;
            }
        }

        // Page Fault
        if(found == 0)
        {
            fault++;

            // If frames are full ? apply LRU
            if(i >= m)
            {
                // Initialize distance array
                for(a = 0; a < m; a++)
                {
                    x[a] = 0;
            	}

                // Find how far each page was used last
                for(c = 0; c < m; c++)
                {
                    for(b = i - 1; b >= 0; b--)
                    {
                        if(q[c] != p[b])
                            x[c]++;
                        else
                            break;
                    }
                }

                // Find maximum distance ? LRU page
                max = x[0];
                pos = 0;

                for(a = 1; a < m; a++)
                {
                    if(x[a] > max)
                    {
                        max = x[a];
                        pos = a;
                    }
                }

                l = pos;   // replace this frame
            }

            // Replace page
            q[l] = p[i];
            l++;

            // Print frames
            for(k = 0; k < m; k++)
                printf("%d\t", q[k]);

            printf("\n");
        }
    }

    printf("Page Faults = %d", fault);
    return 0;
}
