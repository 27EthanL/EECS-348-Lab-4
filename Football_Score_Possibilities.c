#include <stdio.h>

void score_possibilities(int score){
    for (int td2 = 0; td2 * 8 <= score; td2++){
        for (int td1 = 0; td1 * 7 <= score; td1++){
            for (int td = 0; td * 6 <= score; td++){
                for (int fg = 0; fg * 3 <= score; fg++){
                    for (int s = 0; s * 2 <= score; s++){
                        int possible = (td2 * 8) + (td1 * 7) + (td * 6) + (fg * 3) + (s * 2);
                        if (possible == score){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, s);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int score;
    while (score != 2){
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score != 0 && score != 1){
            score_possibilities(score);
        }
        else{
            score = 2;
        }
    }
    return 0;
}