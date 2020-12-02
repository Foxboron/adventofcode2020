#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define for_each_arr(i, items) \
    for (i = 0; i < sizeof(items) / sizeof(items[0]); i++)

int main(int argc, char *argv[]){
    FILE *f;
    char line[256];

    if (argc == 1){
        printf("No file supplied\n");
        return 1;
    }

    if (!(f = fopen(argv[1], "re"))){
        printf("Can't open file\n");
        return 1;
    }
    int valid1 = 0;
    while (fgets(line, sizeof(line), f)) {
        int lower, upper;
        char letter;
        char password[255];
        // 3-4 f: sgbmjfftf
        sscanf(line, "%d-%d %c: %s", &lower, &upper, &letter, password);
        /* printf("lower: %d upper: %d letter: %c password: %s\n", lower, upper, letter, password); */
        int i;
        int count = 0;
        for (i = 0; i < strlen(password); i++){
            if (letter == password[i]){
                count++;
            }
        }
        if ((count >= lower) && (count <= upper)){
            valid1++;
        }
    }
    printf("Solution 1: %d\n", valid1);

    if (!(f = fopen(argv[1], "re"))){
        printf("Can't open file\n");
        return 1;
    }

    int valid2 = 0;
    while (fgets(line, sizeof(line), f)) {
        int lower, upper;
        char letter;
        char password[255];
        sscanf(line, "%d-%d %c: %s", &lower, &upper, &letter, password);
        /* printf("lower: %d upper: %d letter: %c password: %s\n", lower, upper, letter, password); */
        if ((password[lower-1] == letter) && (password[upper-1] == letter)){
            continue;
        }
        if ((password[lower-1] == letter) || (password[upper-1] == letter)){
            valid2++;
        }
    }
    printf("Solution 2:%d\n", valid2);
    return 0;
}
