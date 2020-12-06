#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct Passport {
    char byr[255];
    char iyr[255];
    char eyr[255];
    char hgt[255];
    char hcl[255];
    char ecl[255];
    char pid[255];
    char cid[255];
} Passport;

static const struct Passport EmptyStruct;

bool check_policy(Passport pass){
    /* printf("check_policy: %s\n", pass.byr); */
    /* printf("check_policy strlen: %i\n", strlen(pass.byr)); */
    if (strlen(pass.byr) == 0)
        return false;
    if (strlen(pass.iyr) == 0)
        return false;
    if (strlen(pass.eyr) == 0)
        return false;
    if (strlen(pass.hgt) == 0)
        return false;
    if (strlen(pass.hcl) == 0)
        return false;
    if (strlen(pass.ecl) == 0)
        return false;
    if (strlen(pass.pid) == 0)
        return false;
    return true;
}

int main(int argc, char *argv[]){
    FILE *f;
    char line[255];
    char *rest = NULL;
    char *token;
    char key[3];
    char field[255];
    int valid = 0;
    int passports = 0;

    if (argc == 1){
        printf("No file supplied\n");
        return 1;
    }

    if (!(f = fopen(argv[1], "re"))){
        printf("Can't open file\n");
        return 1;
    }

    Passport pass = {0};
    while (fgets(line, sizeof(line), f)) {
        if (strlen(line) == 1){
            passports++;
            if (check_policy(pass)){
                valid++;
            }
            pass = EmptyStruct;
            continue;
        }

        token = strtok_r (line, " ", &rest);
        while (token != NULL){
            sscanf(token, "%3s:%255s", key, field);
            token = strtok_r(NULL, " ", &rest);
            if (strcmp(key, "byr") == 0){
                strcpy(pass.byr, field);
            }
            if (strcmp(key, "iyr") == 0){
                strcpy(pass.iyr, field);
            }
            if (strcmp(key, "eyr") == 0){
                strcpy(pass.eyr, field);
            }
            if (strcmp(key, "hgt") == 0){
                strcpy(pass.hgt, field);
            }
            if (strcmp(key, "hcl") == 0){
                strcpy(pass.hcl, field);
            }
            if (strcmp(key, "ecl") == 0){
                strcpy(pass.ecl, field);
            }
            if (strcmp(key, "pid") == 0){
                strcpy(pass.pid, field);
            }
            if (strcmp(key, "cid") == 0){
                strcpy(pass.cid, field);
            }
        }
    }
    printf("Solution 1: %i", valid);
    printf("Passports: %i", passports);
    return 0;
}
