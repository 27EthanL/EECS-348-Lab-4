// The essential include
#include <stdio.h>

// The score possibilities function
void score_possibilities(int score){
    // Checks if a TD + 2 is possible for the score
    for (int td2 = 0; td2 * 8 <= score; td2++){
        // Checks if a TD + safety is possible for the score
        for (int td1 = 0; td1 * 7 <= score; td1++){
            // Checks if a TD is possible for the score
            for (int td = 0; td * 6 <= score; td++){
                // Checks if a FG is possible for the score
                for (int fg = 0; fg * 3 <= score; fg++){
                    // Checks if a Satefy is possible for the score
                    for (int s = 0; s * 2 <= score; s++){
                        // Sums up the products of all the current points
                        int possible = (td2 * 8) + (td1 * 7) + (td * 6) + (fg * 3) + (s * 2);
                        // Checks if the possible points is similar to the score
                        if (possible == score){
                            // If true, prints the points
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, s);
                        }
                    }
                }
            }
        }
    }
}

// The main function of the c-program (required)
int main(){
    int score;
    // A simple file loop that stops the repeat if the user puts in 0 or 1
    while (score != 0 || score != 1){
        printf("Enter 0 or 1 to STOP\n");
        // Gets the NFL score from the user
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        // Checks if possible
        if (score != 0 && score != 1){
            score_possibilities(score);
        }
    }
    return 0;
}