#include <stdio.h>

void calculateCombinations(int score, int touchdowns, int fieldGoals, int safeties, char* combination) {
    if (score == 0) {
        printf("%s\n", combination);
        return;
    }

    // Try adding a touchdown
    if (score >= 6) {
        char temp[100];
        sprintf(temp, "%s1 TD, ", combination);
        calculateCombinations(score - 6, touchdowns + 1, fieldGoals, safeties, temp);
    }

    // Try adding a touchdown with a 2-point conversion
    if (score >= 8) {
        char temp[100];
        sprintf(temp, "%s1 TD + 2pt, ", combination);
        calculateCombinations(score - 8, touchdowns + 1, fieldGoals, safeties, temp);
    }

    // Try adding a field goal
    if (score >= 3) {
        char temp[100];
        sprintf(temp, "%s1 3pt FG, ", combination);
        calculateCombinations(score - 3, touchdowns, fieldGoals + 1, safeties, temp);
    }

    // Try adding a safety
    if (score >= 2) {
        char temp[100];
        sprintf(temp, "%s1 Safety, ", combination);
        calculateCombinations(score - 2, touchdowns, fieldGoals, safeties + 1, temp);
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        char initialCombination[] = "";
        calculateCombinations(score, 0, 0, 0, initialCombination);
    }

    return 0;
}
