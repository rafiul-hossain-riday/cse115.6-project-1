#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global-data.h"

#define MAX_NAME_LENGTH 15
#define MAX_STUDENTS 30

char name[MAX_STUDENTS][MAX_NAME_LENGTH] = {
    "Noahm", "Oliverm", "Leom", "Freddiem", "Arthurm", "Archiem", "Alfiem", "Charliem", "Oscarm", "Henrym",
    "Harrym", "Jackm", "Teddym", "Finleym", "Arlom", "Lucam", "Jacobm", "Tommym", "Lucasm", "Theodorem",
    "Maxm", "Isaacm", "Albiem", "Jamesm", "Masonm", "Rorym", "Thomasm", "Ruebenm", "Romanm", "Loganm"};

char course_names[10][4] = {
    "CSE",
    "EEE",
    "HIS",
    "MIC",
    "PHR",
    "PHY",
    "BIO",
    "ENG",
    "ECO",
    "MAT",
};

int main(void)
{
    struct student_data data[MAX_STUDENTS];
    int i, j;

    for (i = 0; i < MAX_STUDENTS; ++i)
    {
        strcpy(data[i].name, name[i]);
        data[i].id = 232001 + i;
        sprintf(data[i].passwd, "%d", 232001 + i);

        for (j = 0; j < 10; ++j)
        {
            data[i].course_list[j].cgpa = 0;
            data[i].course_list[j].attendance = 0;
            data[i].course_list[j].completed = 0;
            data[i].course_list[j].course_code = 100.1 + i;
            strcpy(data[i].course_list[j].course_name, course_names[j]);
            data[i].course_list[j].paid = 0;
            data[i].course_list[j].teacher_id = 232100 + i;
        }
    }

    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        printf("ID: %s\n", data[i].course_list[4].course_name);
    }

    // FILE *fp = fopen("student_data.dat", "ab");

    // fclose(fp);

    return 0;
}
