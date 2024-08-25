#include<stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio; // Profit-to-weight ratio
};

// Function to perform Bubble Sort on items array based on profit-to-weight ratio
void Sort(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, int capacity) {
    int i;
    Sort(items, n);

    int remainingCapacity = capacity;
    float totalProfit = 0.0;

    for (i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity && remainingCapacity > 0) {
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            break;
        }
    }

    if (remainingCapacity > 0 && i < n) {
        totalProfit += items[i].profit * ((float)remainingCapacity / items[i].weight);
    }

    return totalProfit;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];

    printf("Enter the weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    float maxProfit = fractionalKnapsack(items, n, capacity);
    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}
