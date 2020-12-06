#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>


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
    if (strlen(pass.byr) == 0){
        return false;
    }else{
        int byr = 0;
        byr = atoi(pass.byr);
        if ((byr < 1920) || (byr > 2002)){
            return false;
        }
    }
    if (strlen(pass.iyr) == 0){
        return false;
    }else{
        int iyr = 0;
        iyr = atoi(pass.iyr);
        if ((iyr < 2010) || (iyr > 2020)){
            return false;
        }
    }
    if (strlen(pass.eyr) == 0){
        return false;
    }else{
        int eyr = 0;
        eyr = atoi(pass.eyr);
        if ((eyr < 2020) || (eyr > 2030)){
            return false;
        }
    }
    if (strlen(pass.hgt) == 0){
        return false;
    }else{
        size_t size = strlen(pass.hgt);
        char t[3];
        int val=0;
        sprintf(t, "%c%c", pass.hgt[size-2], pass.hgt[size-1]);
        if (!strcmp(t, "cm")){
            val = atoi(pass.hgt);
            if ((val < 150) || (val > 193)){
                return false;
            }
        }else if (!strcmp(t, "in")){
            val = atoi(pass.hgt);
            if ((val < 59) || (val > 76)){
                return false;
            }
        }else{
            return false;
        }
    }
    if (strlen(pass.hcl) == 0){
        return false;
    }else{
        regex_t regex;
        int reti=0;
        reti = regcomp(&regex, "#[0-9a-f]", 0);
        reti = regexec(&regex, pass.hcl, 0, NULL, 0);
        if (reti) {
            return false;
        }
    }
    if (strlen(pass.ecl) == 0){
        return false;
    }else{
        if (!strcmp(pass.ecl, "amb")){
        }else if (!strcmp(pass.ecl, "blu")){
        }else if (!strcmp(pass.ecl, "brn")){
        }else if (!strcmp(pass.ecl, "gry")){
        }else if (!strcmp(pass.ecl, "grn")){
        }else if (!strcmp(pass.ecl, "hzl")){
        }else if (!strcmp(pass.ecl, "oth")){
        }else{
            return false;
        }
    }
    if (strlen(pass.pid) != 9){
        return false;
    }
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
