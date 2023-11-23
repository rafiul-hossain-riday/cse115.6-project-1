#include <stdio.h>
#include <string.h>

struct course_list
{
    char course_name[10];
    int fee;
    int codes[5];
    int total_class;
};

struct course_list course_list[15] = {
    {"ARC", 20000, {101, 102, 103, 104, 105}, 35},
    {"CEE", 20000, {101, 102, 103, 104, 105}, 35},
    {"CSE", 20000, {101, 102, 103, 104, 105}, 35},
    {"EEE", 20000, {101, 102, 103, 104, 105}, 35},
    {"BIO", 20000, {101, 102, 103, 104, 105}, 35},
    {"MIC", 20000, {101, 102, 103, 104, 105}, 35},
    {"PHR", 20000, {101, 102, 103, 104, 105}, 35},
    {"BBA", 20000, {101, 102, 103, 104, 105}, 35},
    {"BAE", 20000, {101, 102, 103, 104, 105}, 35},
    {"LLB", 20000, {101, 102, 103, 104, 105}, 35},
    {"MAJ", 20000, {101, 102, 103, 104, 105}, 35},
    {"SOC", 20000, {101, 102, 103, 104, 105}, 35},
    {"CHE", 20000, {101, 102, 103, 104, 105}, 35},
    {"HIS", 20000, {101, 102, 103, 104, 105}, 35},
    {"MIS", 20000, {101, 102, 103, 104, 105}, 35},
};

/************************************************************/

struct student_course_list
{
    char course_name[5]; // CSE
    float course_code;   // 115.6
    int attendance;      // default 0;
    float cgpa;          // default 0.0;
    int paid;            // 0: false, 1: true, default 0
    int teacher_id;
    int completed;
};

struct student_data
{
    char name[30];
    int id;
    char passwd[50];
    struct student_course_list course_list[10];
};

/************************************************************/

struct teacher_course_list
{
    char course_name[5]; // CSE
    float course_code;   // 115.6
    int attendance;      // default 0;
    int course_salary;   // 50% depennds on attendance percentage
    float rating[50];
    int completed;
};

struct teacher_data
{
    char name[10];
    int id;
    char passwd[50];
    struct teacher_course_list course_list[4];
    int deleted; // 1: deleted, 0: active, default: 0
};

/************************************************************/

float average_grade(float *arr, int size)
{
    float sum = 0.0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];

    return sum / size;
}

float course_cgpa(int score)
{
    if (score >= 93)
        return 4.0;
    else if (score >= 90)
        return 3.7;
    else if (score >= 87)
        return 3.3;
    else if (score >= 83)
        return 3.0;
    else if (score >= 80)
        return 2.7;
    else if (score >= 77)
        return 2.3;
    else if (score >= 73)
        return 2.0;
    else if (score >= 70)
        return 1.7;
    else if (score >= 67)
        return 1.3;
    else if (score >= 60)
        return 1.0;
    else
        return 0.0;
}

const char *grade_str(float cgpa)
{
    if (cgpa == 4.0)
        return "A";
    else if (cgpa >= 3.7)
        return "A-";
    else if (cgpa >= 3.3)
        return "B+";
    else if (cgpa >= 3.0)
        return "B";
    else if (cgpa >= 2.7)
        return "B-";
    else if (cgpa >= 2.3)
        return "C+";
    else if (cgpa >= 2.0)
        return "C";
    else if (cgpa >= 1.7)
        return "C-";
    else if (cgpa >= 1.3)
        return "D+";
    else if (cgpa >= 1.0)
        return "D";
    else
        return "F";
}

int teacher_salary(int course_salary, int total_classes, int attended_classes)
{
    float missed_attendance_percentage = (((float)total_classes - (float)attended_classes) / total_classes) * 100.0;
    float salary_deduction_percentage = (missed_attendance_percentage / 2.0);

    float deducted_salary = course_salary * (salary_deduction_percentage / 100.0);

    return (course_salary - (int)deducted_salary);
}

/************************************************************/

int login(int user, int id, char *passwd)
{
    if (user == 1)
    {
        FILE *file = fopen("student_data.dat", "rb");
        if (file == NULL)
        {
            printf("Unable to open file.\n");
            return 0;
        }
        struct student_data currentStudent;
        // Read each struct from the file and check for a match
        while (fread(&currentStudent, sizeof(struct student_data), 1, file) == 1)
        {
            if (currentStudent.id == id)
            {
                if (strcmp(currentStudent.passwd, passwd) == 0)
                {
                    return 0; // match found
                    fclose(file);
                }
                else
                    return 1;
            }
        }
        fclose(file);
    }
    else if (user == 2)
    {
        FILE *file = fopen("teacher_data.dat", "rb");
        if (file == NULL)
        {
            printf("Unable to open file.\n");
            return 0;
        }

        struct teacher_data currentTeacher;
        // Read each struct from the file and check for a match
        while (fread(&currentTeacher, sizeof(struct teacher_data), 1, file) == 1)
        {
            if (currentTeacher.id == id)
            { // id matches
                if (currentTeacher.deleted == 0)
                {
                    if (strcmp(currentTeacher.passwd, passwd) == 0)
                    {
                        return 0; // match found
                        fclose(file);
                    }
                    else
                        return 2; // id matches but password doesn't
                }
                else
                    return 1; // deleted
            }
        }
        fclose(file);
    }
}

/************************************************************/

int delete_id(int user, int id)
{
    FILE *pr;
    FILE *pr1;

    char file_name[20];

    if (user == 1)
        strcpy(file_name, "student_data.dat");
    else if (user == 2)
        strcpy(file_name, "teacher_data.dat");
    else
        strcpy(file_name, "not_found");

    pr = fopen(file_name, "rb");
    pr1 = fopen("data_2.dat", "wb");

    if (pr == NULL || pr1 == NULL)
    {
        return 0;
    }

    struct student_data current_student;
    int deleted = 0;

    while (fread(&current_student, sizeof(struct student_data), 1, pr))
    {
        if (current_student.id == id)
            deleted = 1;
        else
            fwrite(&current_student, sizeof(struct student_data), 1, pr1);
    }

    fclose(pr);
    fclose(pr1);

    if (deleted)
    {
        remove(file_name);
        rename("data_2.dat", file_name);
    }

    return deleted;
}
