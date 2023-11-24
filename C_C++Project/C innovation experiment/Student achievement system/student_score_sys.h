#ifndef STUDENT_SCORE_SYS_H
#define STUDENT_SCORE_SYS_H

#define MAX_ID_LEN 10           // 最大学号长度
#define MAX_STUDENT_NUM 100     // 最大学生数
#define MAX_NAME_LEN 20         // 最大姓名长度


// 学生信息结构体
typedef struct {
    char id[MAX_ID_LEN];        // 学号
    char name[MAX_NAME_LEN];    // 姓名
    int score;                  // 课程分数
} Student;

// 学生信息数组
Student students[MAX_STUDENT_NUM];
int student_num = 0;            // 学生数


void query();                   // 查询学生信息
void show_single_student(Student student);    // 显示单个学生信息
void show_all_students();       // 显示全部学生信息


#endif /*STUDENT_SCORE_SYS_H*/
