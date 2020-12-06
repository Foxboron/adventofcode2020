#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define for_each_arr(i, items) \
    for (i = 0; i < sizeof(items) / sizeof(items[0]); i++)

int main(int argc, char *argv[]){
    FILE *f;
    int i;
    char line[255];

    if (argc == 1){
        printf("No file supplied\n");
        return 1;
    }

    if (!(f = fopen(argv[1], "re"))){
        printf("Can't open file\n");
        return 1;
    }

    int answers[26];
    memset(answers, 0, sizeof(answers));
    int people = 0;
    int count = 0;
    while (fgets(line, sizeof(line), f)) {
        if (strlen(line) == 1){
            for_each_arr(i, answers){
                if(answers[i] == people){
                    count++;
                }
            }
            memset(answers, 0, sizeof(answers));
            people = 0;
            continue;
        }
        for (i = 0; i < strlen(line)-1; i++){
            answers[line[i]-97]++; 
        }
        people++;
    }
    printf("Solution: %i\n", count);
}
