#include <stdio.h>

#define MAX_ITEMS 100 // maximum number of items
#define MAX_WEIGHT 1000 // maximum weight of knapsack

// function to compute the maximum value that can be obtained
int knapsack(int n, int weight[], int value[], int W) {
    int dp[n+1][W+1];
    // initialize dp table to all zeros
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }
    // compute the maximum value for each weight
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weight[i-1] > j) {
                // item cannot be included
                dp[i][j] = dp[i-1][j];
            } else {
                // choose the maximum of including and not including the item
                dp[i][j] = (value[i-1] + dp[i-1][j-weight[i-1]]) > dp[i-1][j] ? 
                            value[i-1] + dp[i-1][j-weight[i-1]] : dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n; // number of items
    int weight[MAX_ITEMS]; // weight of each item
    int value[MAX_ITEMS]; // value of each item
    int W; // weight capacity of knapsack
    // read input
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }
    printf("Enter weight capacity of knapsack: ");
    scanf("%d", &W);
    // solve the knapsack problem
    int max_value = knapsack(n, weight, value, W);
    // output the result
    printf("Maximum value that can be obtained: %d\n", max_value);
    return 0;
}
