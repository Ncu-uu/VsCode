#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "student_score_sys.h"


// 按学号查询学生信息
void query_by_id() {
    char id[10];
    printf("请输入要查询的学生学号：");
    gets(id);
    for (int i = 0; i < student_num; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("查询到的学生信息如下:\n");
            printf("学号\t姓名\t成绩情况\n");
            show_single_student(students[i]);
            return;
        }
    }
    printf("该学号不存在！\n");
}

// 按姓名查询学生信息
void query_by_name() {
    char name[MAX_NAME_LEN];
    printf("请输入要查询的学生姓名：");
    gets(name);
    bool ISFIRST=true,NOTEXIST=true;
    for (int i = 0; i < student_num; i++) {
        if ((strcmp(students[i].name, name) == 0) && ISFIRST) {
            printf("查询到的学生信息如下:\n");
            printf("学号\t姓名\t成绩情况\n");
            show_single_student(students[i]);
            ISFIRST=false;
            NOTEXIST=false;
        }
        else if (strcmp(students[i].name, name) == 0)
        {
            show_single_student(students[i]);
        }
        else if (NOTEXIST && i==(student_num-1))
        {
            printf("未找到具有此姓名的学生！\n");
        }
    }
}

// 按分数查询学生信息
void query_by_score() {
    int score;
    printf("请输入要查询的学生成绩：");
    scanf_s("%d", &score);
    bool ISFIRST=true,NOTEXIST=true;
    for (int i = 0; i < student_num; i++) {
        if ((students[i].score==score) && ISFIRST) {
            printf("查询到的学生信息如下:\n");
            printf("学号\t姓名\t成绩情况\n");
            show_single_student(students[i]);
            ISFIRST=false;
            NOTEXIST=false;
        }
        else if (students[i].score==score)
        {
            show_single_student(students[i]);
        }
        else if (NOTEXIST && i==(student_num-1))
        {
            printf("未找到具有此成绩的学生！\n");
        }
    }
}

// 查询学生信息
void query()
{
    printf("请选择您的查询方式：\n");
    printf("1.按学号查询\n");
    printf("2.按姓名查询\n");
    printf("3.按分数查询\n");
    printf("请输入您的选择：");
    int choice;
    scanf_s("%d", &choice);
    switch (choice)
    {
        case 1:
            getchar();
            query_by_id();
            break;
        case 2:
            getchar();
            query_by_name();
            break;
        case 3:
            query_by_score();
            break;
    }
}
