#include<stdio.h>

struct Job {
    int d;
    int p;// Profit-to-weight ratio
};

// Function to perform Bubble Sort on items array based on profit-to-weight ratio


float jobSequencing(struct Job jobs[], int n) {
    int profit=0,count=0,dmax=0,i,slot[n],r;
    for(i=1;i<=n;i++)
    {
        if(jobs[i].d>dmax)
        {
            dmax=jobs[i].d;
        }
    }
    for(i=1;i<=dmax;i++)
    {

        slot[i]=-1;
    }
    for(i=1;i<=n;i++)
    {
        r=jobs[i].d;
        for(r=jobs[i].d;r>=1;r--)
        {
            if(slot[r]==-1)
            {
                slot[r]=i;
                profit+=jobs[i].p;
                count++;
                break;
            }
        }
        if(count==dmax)
        {
            break;
        }
    }
    return profit;
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter the deadline and profit of each item:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &jobs[i].d, &jobs[i].p);
    }

    float maxProfit = jobSequencing(jobs, n);
    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}
