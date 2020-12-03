#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *f;
    char line[256];
    int lower, upper;
    char letter;
    char password[255];

    if (argc == 1){
        printf("No file supplied\n");
        return 1;
    }

    if (!(f = fopen(argv[1], "re"))){
        printf("Can't open file\n");
        return 1;
    }

    int valid1 = 0;
    int valid2 = 0;
    while (fgets(line, sizeof(line), f)) {
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
        if ((password[lower-1] == letter) ^ (password[upper-1] == letter)){
            continue;
        }
        valid2++;
    }
    printf("Solution 1: %d\n", valid1);
    printf("Solution 2:%d\n", valid2);
    return 0;
}
