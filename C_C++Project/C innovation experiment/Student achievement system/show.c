#include<stdio.h>
#include "student_score_sys.h"


//显示单个学生的信息
void show_single_student(Student student) {
    printf("%s\t%s\t程序设计 %d\n", student.id, student.name, student.score);
}

//显示全部学生的信息
void show_all_students() {
    printf("所有学生信息如下:\n");
    printf("学号\t姓名\t成绩情况\n");
    for (int i = 0; i < student_num; i++) {
        show_single_student(students[i]);
    }
}

// 按学号排序
void sort_by_id() {
    for (int i = 0; i < student_num - 1; i++) {
        for (int j = 0; j < student_num - i - 1; j++) {
            if (strcmp(students[j].id, students[j + 1].id) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("按学号排序成功！\n");
}
