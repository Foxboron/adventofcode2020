#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WIDTH   31
#define HEIGHT  323

#define for_each_arr(i, items) \
    for (i = 0; i < sizeof(items) / sizeof(items[0]); i++)

// Grabs newline
typedef char Map[HEIGHT][WIDTH+2];

typedef struct Option {
    int right;
    int down;
} Option;

const Option options[] = {
    {1, 1},
    {3, 1},
    {5, 1},
    {7, 1},
    {1, 2},
};


int check_slope(Map map, Option opt){
    int i;
    int position = 0;
    int trees = 0;
    for (i = 0; i < HEIGHT; i += opt.down) {
        if (map[i][position % WIDTH] == '#'){
            /* map[i][position % WIDTH] = 'X'; */
            trees++;
        }else{
            /* map[i][position % WIDTH] = 'O'; */
        }
        /* printf("%s", map[i]); */
        position+=opt.right;
    }
    return trees;
}

int main(int argc, char *argv[]){
    FILE *f;
    char line[WIDTH+2];
    int n = 0;
    int i = 0;
    long answer = 1;
    Map map = {};

    if (argc == 1){
        printf("No file supplied\n");
        return 1;
    }

    if (!(f = fopen(argv[1], "re"))){
        printf("Can't open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), f)) {
        strcpy(map[n++], line);
    }

    for_each_arr(i, options){
        answer *= check_slope(map, options[i]);
        if (i == 1){
            // Yolo.
            printf("Solution 1: %i\n", check_slope(map, options[i]));
        }
    }

    printf("Solution 2: %li\n", answer);
    return 0;
}
