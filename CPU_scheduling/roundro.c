#include <stdio.h>

int main()
{
    int n, tq, completed = 0, completionTime = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int at[n], bt[n], rem[n], tat[n], wt[n];
    float avgtat = 0, avgwt = 0;

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i]; // Remaining time
    }

    // Round Robin Logic
    while (completed < n)
    {
        int idle = 1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= completionTime && rem[i] > 0)
            {
                idle = 0;

                if (rem[i] > tq)
                {
                    completionTime += tq;
                    rem[i] -= tq;
                }
                else
                {
                    completionTime += rem[i];
                    tat[i] = completionTime - at[i]; // Turnaround Time
                    wt[i] = tat[i] - bt[i];          // Waiting Time
                    rem[i] = 0;
                    completed++;
                }
            }
        }

        if (idle)
        {
            completionTime++; // CPU idle
        }
    }

    // Calculate averages
    for (int i = 0; i < n; i++)
    {
        avgtat += tat[i];
        avgwt += wt[i];
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgtat / n);
    printf("Average Waiting Time: %.2f\n", avgwt / n);

    return 0;
}
