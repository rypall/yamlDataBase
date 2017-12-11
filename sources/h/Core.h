//
// Created by Qut on 12/11/2017.
//

#ifndef YAMLDATABASE_CORE_H
#define YAMLDATABASE_CORE_H

void query_use(char *);

void query_create_database(char *);

void query_drop_database(char *);

void query_drop_table(char *);

void query_create_table(char *);

void splitCreateQuery(char *, const char *);

void goSplitCreateQuery(char *, const char *);

char *strtok1(char *, const char *);

#endif //YAMLDATABASE_CORE_H