#include <stdio.h>

int main() {

    char candidates[5][10] = {"Cad1", "Cad2", "Cad3", "Cad4", "Cad5"};
    int votes[5] = {2, 4, 7, 9, 1};

    int num_candidates = 5;

    printf("Welcome to the voting system...\n");
    printf("Choose you option: \n");

    int op;
    do {
        printf("1. Vote your fav\n2. Check Votes\n3. Check leading and exit\n>>> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Printing candidates...\n");
                for (int i = 0; i < num_candidates; ++i) {
                    printf("%d. %s\n", i+1, candidates[i]);
                }
                int cop;
                do {
                    printf("Select you vote: ");
                    scanf("%d", &cop);
                } while (cop <=1 && cop >= 5);

                votes[cop-1]++;

                break;
            case 2:
                printf("Printing candidates...\n");
                for (int i = 0; i < num_candidates; ++i) {
                    printf("%d. %s = %d\n", i+1, candidates[i], votes[i]);
                }
                break;
            default:
                printf("Invalid Code");
        }
    } while (op != 3);
    
    int max_votes_i = 0;
    for (int i = 0; i < num_candidates; ++i) {
        if (votes[i] > votes[max_votes_i]) {
            max_votes_i = i;
        }
    }

    printf("Winner\n");
    printf("%s with %d votes", candidates[max_votes_i], votes[max_votes_i]);
    

}