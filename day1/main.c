#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Taken from cdown
#define for_each_arr(i, items) \
    for (i = 0; i < sizeof(items) / sizeof(items[0]); i++)

int main(int argc, char *argv[]){
    clock_t begin = clock();
    FILE *f;
    int i, ii, iii;
    int numbers[199];
    char line[256];

    if (argc == 1){
        printf("No file supplied\n");
        return 1;
    }

    f = fopen(argv[1], "re");
    if (!f){
        printf("Can't open file\n");
        return 1;
    }

    int n = 0;
    while (fgets(line, sizeof(line), f)) {
        numbers[n++] = atoi(line);
    }

/* Part 1 */
    for_each_arr(i, numbers){
        for_each_arr(ii, numbers){
            if (numbers[i]+numbers[ii] == 2020) {
                goto found;
            }
        }
    }

found :
    printf("%d + %d == 2020\n", numbers[i], numbers[ii]);
    printf("Answer: %d\n", numbers[i]*numbers[ii]);

/* Part 2 */
    for_each_arr(i, numbers){
        for_each_arr(ii, numbers){
            for_each_arr(iii, numbers){
                if (numbers[i]+numbers[ii]+numbers[iii]== 2020) {
                    goto found2;
                }
            }
        }
    }

found2 :
    printf("%d + %d + %d == 2020\n", numbers[i], numbers[ii], numbers[iii]);
    printf("Answer: %d\n", numbers[i]*numbers[ii]*numbers[iii]);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    return 0;
}
