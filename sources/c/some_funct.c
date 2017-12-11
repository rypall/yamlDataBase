//
// Created by Qut on 29/10/2017.
//
#include <stdio.h>
#include "../h/some_funct.h"
#include "../h/parser_SQL.h"
#include <string.h>
#include <stdlib.h>


void menu() {
    //  verifFirstInit();
    //  showInfo();
    printf("WELCOME\ntype exit or blanck query for exit");

    while (1) {
        char requestsql[1024] = "";
        char word[255] = "";
        int counter;
        counter = 1;
        printf("\n%d>", counter);
        //si ; en fin
        while (scanf("%[^\n]%*c", word) == 1) {
            if (!strcmp(&word[strlen(word) - 1], ";")) {
                strcat(requestsql, word);
                parserSQL(requestsql);
                break;
            } else if (strcmp(&word[strlen(word) - 1], " ")) {
                strcat(word, " ");
            }
            strcat(requestsql, word);
            printf("%d>", ++counter);
        }
        if (strlen(word) == 0) {
            query_exit("");
            break;
        }
        if (!strcmp(upWord(word), "EXIT;")) {
            break;
        }

    }
}

/**
 * Desc: up the string
 *
 * Param: Char * word : String to up
 *
 * Return: (char *) upper string
 */
char *upWord(char *word) {
    size_t len;
    int boucle;
    len = strlen(word);
    char *upword = malloc(sizeof(char) * (len + 1));
    for (boucle = 0; boucle < len; boucle++) {
        upword[boucle] = (char) ((word[boucle] >= 'a' && word[boucle] <= 'z') ? word[boucle] - 32 : word[boucle]);
    }
    upword[len] = '\0';
    return upword;
}


/**
 * Desc: delete multiple space
 *
 * Param: Char * word : String to clean of multiple space
 *
 * Return: (char *) clean string without multiple space
 */
char *cleanQuery(char *word) {
    size_t len;
    int boucle;
    int showchar;
    showchar = 1;
    size_t cleanspace;
    len = strlen(word);
    cleanspace = len;
    if (!strncmp(&word[0], " ", 1)) {
        cleanspace = len - 1;
        showchar = 0;
    }
    for (boucle = 0; boucle < len - 1; boucle++) {
        if (!strncmp(&word[boucle], " ", 1) && !strncmp(&word[boucle + 1], " ", 1)) {
            cleanspace--;
        }
    }
    char *cleanquery = malloc(sizeof(char) * (cleanspace + 1));
    cleanquery[cleanspace - 1] = ';';
    cleanquery[cleanspace] = '\0';
    cleanspace = 0;
    for (boucle = 0; boucle < len - 1; boucle++) {
        if (!strncmp(&word[boucle], " ", 1) && !strncmp(&word[boucle + 1], " ", 1)) {
            continue;
        } else {
            if (!showchar) {
                showchar = 1;
            } else {
                cleanquery[cleanspace] = word[boucle];
                cleanspace++;
            }
        }
    }
    return cleanquery;
}

/**
 * Desc: check if the string is alphanumeric
 *
 * Param: Char * word : String to check
 *
 * Return: 1 -> Alphanum ; 0 if not
 */
int isAlphaNum(char *word) {
    size_t len;
    int isOk;
    isOk = 1;
    len = strlen(word);
    for (int boucle = 0; boucle < len; boucle++) {

        if (!((word[boucle] >= 'a' && word[boucle] <= 'z') || (word[boucle] >= 'A' && word[boucle] <= 'Z') ||
              (word[boucle] >= '0' && word[boucle] <= '9'))) {
            isOk = 0;
            break;
        }
    }
    return isOk;
}

/**
 * Desc: return number of terms split with the delim
 *
 * Param:
 *      Char * countChar : String to split and count
 *      char delim : Char delim
 *
 * Return: number of term (int)
 */
int countArgs(char *countChar, const char *delim) {
    char *countrequest;
    countrequest = malloc(sizeof(char) * (strlen(countChar) + 1));
    strcpy(countrequest, countChar);
    int count;
    count = 0;
    char *token = strtok(countrequest, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }
    free(countrequest);
    return count;
}


/**
 * Desc: return the first word of a string
 *
 * Param: Char * word : String to csplit
 *
 * Return: first word
 */
char *splitWord(char *word, char *delim) {
    int len;
    int count;
    char *firstWord;
    len = strlen(word);
    for (count = 0; count < len; count++) {
        if (word[count] == delim[0]) {
            firstWord = malloc(sizeof(char) * (count + 1));
            strncpy(firstWord, word, count);
            firstWord[count] = '\0';
            break;
        }
    }
    return firstWord;
}

/**
 * Desc: check if the word is ban
 *
 * Param: Char * word : String to check
 *
 * Return: 1 -> not ban ; 0 -> ban
 */
int correctWord(char *word) {
    return 1;
}
