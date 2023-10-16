#include <stdio.h>

// Function to calculate the average of sales
double calculateAverage(double sales[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sales[i];
    }
    return sum / n;
}

// Function to sort sales in descending order
void sortSales(double sales[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                double temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
            }
        }
    }
}

// Function to generate the sales report
void generateSalesReport(double sales[], char* months[], int n) {
    printf("Monthly sales report for 2022:\n");
    printf("Month      Sales\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
    printf("\nSales summary:\n");
    printf("Maximum sales: $%.2f (%s)\n", sales[n-1], months[n-1]);
    printf("Minimum sales: $%.2f (%s)\n", sales[0], months[0]);
    printf("Average sales: $%.2f\n\n", calculateAverage(sales, n));

    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < n - 5; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 5], sum / 6);
    }
    printf("\nSales Report (Highest to Lowest):\n");
    sortSales(sales, n);
    printf("Month      Sales\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

int main() {
    double sales[12] = {
        23458.01, 40112.00, 56011.85, 37820.88,
        37904.67, 60200.22, 72400.31, 56210.89,
        67230.84, 68233.12, 80950.34, 95225.22
    };

    char* months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int n = 12;
    generateSalesReport(sales, months, n);

    return 0;
}
