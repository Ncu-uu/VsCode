#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

//显示单个学生的信息
void show_single_student(Student student) {
    printf("%s\t%s\t\t程序设计 %d\n", student.id, student.name, student.score);
}

// 展示所有学生信息
void show_all_students(){
    printf("序号\t学号\t\t姓名\t\t成绩情况\n");
    for (int i = 0; i < student_num; i++) {
        printf("%d\t", i + 1);
        show_single_student(students[i]);
    }
}

// 将学生信息数组按学号顺序输出,但不改变学生数组内顺序
void show_by_id(){
    Student temp[MAX_STUDENT_NUM];
    for (int i = 0; i < student_num; i++) {
        temp[i] = students[i];
    }
    for (int i = 0; i < student_num - 1; i++) {
        for (int j = 0; j < student_num - i - 1; j++) {
            if (strcmp(temp[j].id, temp[j + 1].id) > 0) {
                Student temp_student = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = temp_student;
            }
        }
    }
    printf("学号\t\t姓名\t\t成绩情况\n");
    for (int i = 0; i < student_num; i++) {
        show_single_student(temp[i]);
    }
} 

// 将学生信息数组按成绩顺序输出,但不改变学生数组内顺序
void show_by_score() {
    Student temp[MAX_STUDENT_NUM];
    for (int i = 0; i < student_num; i++) {
        temp[i] = students[i];
    }
    for (int i = 0; i < student_num - 1; i++) {
        for (int j = 0; j < student_num - i - 1; j++) {
            if (temp[j].score < temp[j + 1].score) {
                Student temp_student = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = temp_student;
            }
        }
    }
    printf("学号\t\t姓名\t\t成绩情况\n");
    for (int i = 0; i < student_num; i++) {
        show_single_student(temp[i]);
    }
}

// 统计出课程最高、最低和平均成绩,及格人数和不及格人数以及及格率，及格线为60分
void show_statistics() {
    int max_score = students[0].score;
    int min_score = students[0].score;
    int sum_score = 0;
    int pass_num = 0;
    int fail_num = 0;
    for (int i = 0; i < student_num; i++) {
        if (students[i].score > max_score) {
            max_score = students[i].score;
        }
        if (students[i].score < min_score) {
            min_score = students[i].score;
        }
        sum_score += students[i].score;
        if (students[i].score >= 60) {
            pass_num++;
        }
        else {
            fail_num++;
        }
    }
    printf("课程最高分：%d\n", max_score);
    printf("课程最低分：%d\n", min_score);
    printf("课程平均分：%.2f\n", sum_score * 1.0 / student_num);
    printf("及格人数：%d\n", pass_num);
    printf("不及格人数：%d\n", fail_num);
    printf("及格率：%.2f%%\n", (float)pass_num / student_num * 100);
}

//显示全部学生的信息
void show() 
{
    printf("           主菜单>>4.学生信息展示>>\n");
    printf("              ________________________________________________ \n");
    printf("             |                                                |\n");
    printf("             |                  学生信息展示                  |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       1.按照学号顺序       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       2.按照成绩顺序       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       3.成绩统计信息       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       0.返回上级菜单       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |________________________________________________|\n");
    printf("             请输入您的需求：");

    int choice;
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\n\n");
        getchar();
        show_by_id();
        break;
    case 2:
        printf("\n\n");
        getchar();
        show_by_score();
        
        break;
    case 3:
        printf("\n\n");
        printf("所有学生的成绩统计信息如下:\n");
        show_statistics();
        break;
    }
}

//判断学号是否已存在
bool is_id_exist(char id[]) {
    for (int i = 0; i < student_num; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return true;
        }
    }
    return false;
}

// 学生信息以及课程信息的录入
void add_student()
{
    if (student_num >= MAX_STUDENT_NUM)
    {
        printf("学生数已达到上限，无法添加新学生！\n");
        return;
    }

    int num;
    printf("请输入要录入的学生数：");
    scanf_s("%d", &num);
    getchar();

    for (int i = 0; i < num; i++)
    {

        printf("请输入学生学号:");
        char id[MAX_ID_LEN];
        gets(id);
        if (is_id_exist(id))
        {
            printf_s("该学号已存在！\n");
            i--;
            continue;
        }
        strcpy_s(students[student_num].id, MAX_ID_LEN, id);

        printf("请输入学生姓名：");
        gets(students[student_num].name);

        printf("请输入程序设计课程成绩：");
        scanf_s("%d", &students[student_num].score);
        getchar();

        student_num++;
        printf("添加成功！\n");
    }
    printf("\n录入完毕,本次共录入%d名学生信息\n\n", num);
}


// 按学号查询学生信息
void query_by_id() {
    char id[10];
    printf("请输入要查询的学生学号：");
    gets(id);
    for (int i = 0; i < student_num; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("查询到的学生信息如下:\n");
            printf("学号\t\t姓名\t\t成绩情况\n");
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
    bool ISFIRST = true, NOTEXIST = true;
    for (int i = 0; i < student_num; i++) {
        if ((strcmp(students[i].name, name) == 0) && ISFIRST) {
            printf("查询到的学生信息如下:\n");
            printf("学号\t\t姓名\t\t成绩情况\n");
            show_single_student(students[i]);
            ISFIRST = false;
            NOTEXIST = false;
        }
        else if (strcmp(students[i].name, name) == 0)
        {
            show_single_student(students[i]);
        }
        else if (NOTEXIST && i == (student_num - 1))
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
    bool ISFIRST = true, NOTEXIST = true;
    for (int i = 0; i < student_num; i++) {
        if ((students[i].score == score) && ISFIRST) {
            printf("查询到的学生信息如下:\n");
            printf("学号\t\t姓名\t\t成绩情况\n");
            show_single_student(students[i]);
            ISFIRST = false;
            NOTEXIST = false;
        }
        else if (students[i].score == score)
        {
            show_single_student(students[i]);
        }
        else if (NOTEXIST && i == (student_num - 1))
        {
            printf("未找到具有此成绩的学生！\n");
        }
    }
}


// 查询学生信息
void query()
{
    printf("           主菜单>>2.学生信息查询>>\n");
    printf("              ________________________________________________ \n");
    printf("             |                                                |\n");
    printf("             |                  学生信息查询                  |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       1.通过学号查询       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       2.通过姓名查询       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       3.通过成绩查询       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       0.返回上级菜单       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |________________________________________________|\n");
    printf("             请输入您的需求：");
    int choice;
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\n\n");
        getchar();
        query_by_id();
        break;
    case 2:
        printf("\n\n");
        getchar();
        query_by_name();
        break;
    case 3:
        printf("\n\n");
        query_by_score();
        break;
    }
}

// 在学生信息数组末尾添加一条记录
void add_at_end() {
    if (student_num >= MAX_STUDENT_NUM) {
        printf("学生数已达到上限，无法添加新学生！\n");
        return;
    }
    printf("请输入学生学号:");
    char id[MAX_ID_LEN];
    gets(id);
    if (is_id_exist(id)) {
        printf_s("该学号已存在！\n");
        return;
    }
    strcpy_s(students[student_num].id, MAX_ID_LEN, id);

    printf("请输入学生姓名：");
    gets(students[student_num].name);

    printf("请输入程序设计课程成绩：");
    scanf_s("%d", &students[student_num].score);
    getchar();

    student_num++;
    printf("添加成功！\n");
}

// 在学生信息数组指定位置添加一条记录
void add_at_index() {
    if (student_num >= MAX_STUDENT_NUM) {
        printf("学生数已达到上限，无法添加新学生！\n");
        return;
    }
    int index;
    printf("请输入要插入的位置：");
    scanf_s("%d", &index);
    getchar();
    if (index < 0 || index > (student_num+1)) {
        printf("输入的位置有误！\n");
        return;
    }

    student_num++;

    for (int i = student_num; i >= index; i--) {
        students[i] = students[i - 1];
    }


    printf("请输入学生学号:");
    char id[MAX_ID_LEN];
    gets(id);
    if (is_id_exist(id)) {
        printf_s("该学号已存在！\n");
        return;
    }
    strcpy_s(students[index-1].id, MAX_ID_LEN, id);

    printf("请输入学生姓名：");
    gets(students[index-1].name);

    printf("请输入程序设计课程成绩：");
    scanf_s("%d", &students[index-1].score);
    getchar();

    
    printf("添加成功！\n");


}

// 指定学号删除记录
void delete_by_id() {
    char id[10];
    printf("请输入要删除的学生学号：");
    gets(id);
    for (int i = 0; i < student_num; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = i; j < student_num - 1; j++) {
                students[j] = students[j + 1];
            }
            student_num--;
            printf("删除成功！\n");
            return;
        }
    }
    printf("该学号不存在！\n");
} 

// 指定姓名删除记录
void delete_by_name() {
    char name[MAX_NAME_LEN];
    printf("请输入要删除的学生姓名：");
    gets(name);
    bool ISFIRST = true, NOTEXIST = true;
    for (int i = 0; i < student_num; i++) {
        if ((strcmp(students[i].name, name) == 0) && ISFIRST) {
            for (int j = i; j < student_num - 1; j++) {
                students[j] = students[j + 1];
            }
            student_num--;
            printf("删除成功！\n");
            ISFIRST = false;
            NOTEXIST = false;
        }
        else if (strcmp(students[i].name, name) == 0)
        {
            for (int j = i; j < student_num - 1; j++) {
                students[j] = students[j + 1];
            }
            student_num--;
        }
        else if (NOTEXIST && i == (student_num - 1))
        {
            printf("未找到具有此姓名的学生！\n");
        }
    }
}

// 指定学号修改记录
void modify_by_id() {
    char id[10];
    printf("请输入要修改的学生学号：");
    gets(id);
    for (int i = 0; i < student_num; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("请输入学生学号：");
            char id[MAX_ID_LEN];
            gets(id);
            if (is_id_exist(id)&&strcmp(students[i].id,id)!=0)
            {
                printf_s("该学号已存在！\n");
                return;
            }
            strcpy_s(students[i].id, MAX_ID_LEN, id);
            printf("请输入学生姓名：");
            gets(students[i].name);
            printf("请输入程序设计课程成绩：");
            scanf_s("%d", &students[i].score);
            getchar();
            printf("修改成功！\n");
            return;
        }
    }
    printf("该学号不存在！\n");
}
   

// 指定姓名修改记录
void modify_by_name() {
    char name[MAX_NAME_LEN];
    printf("请输入要修改的学生姓名：");
    gets(name);
    bool ISFIRST = true, NOTEXIST = true;
    for (int i = 0; i < student_num; i++) {
        if ((strcmp(students[i].name, name) == 0) && ISFIRST) {
            printf("请输入学生学号：");
            char id[MAX_ID_LEN];
            gets(id);
            if (is_id_exist(id)&&strcmp(students[i].id,id)!=0)
            {
                printf_s("该学号已存在！\n");
                return;
            }
            strcpy_s(students[i].id, MAX_ID_LEN, id);
            printf("请输入学生姓名：");
            gets(students[i].name);
            printf("请输入程序设计课程成绩：");
            scanf_s("%d", &students[i].score);
            getchar();
            printf("修改成功！\n");
            ISFIRST = false;
            NOTEXIST = false;
        }
        else if (strcmp(students[i].name, name) == 0)
        {
            printf("请输入学生学号：");
            gets(students[i].id);
            if (is_id_exist(students[i].id))
            {
                printf_s("该学号已存在！\n");
                return;
            }
            printf("请输入学生姓名：");
            gets(students[i].name);
            printf("请输入程序设计课程成绩：");
            scanf_s("%d", &students[i].score);
            getchar();
            printf("修改成功！\n");
        }
        else if (NOTEXIST && i == (student_num - 1))
        {
            printf("未找到具有此姓名的学生！\n");
        }
    }
}   

//编辑功能，如在末尾或指定位置(可选)添加记录，按指定学号或姓名（可选）删除记录，按指定学号或姓名（可选）修改记录
void modify() {
    printf("           主菜单>>3.学生信息编辑>>\n");
    printf("              ________________________________________________ \n");
    printf("             |                                                |\n");
    printf("             |                  学生信息编辑                  |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       1.在末尾添加记录     **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       2.在指定位置添加记录 **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       3.按学号删除记录     **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       4.按姓名删除记录     **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       5.按学号修改记录     **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       6.按姓名修改记录     **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |        **       0.返回上级菜单       **        |\n");
    printf("             |        ********************************        |\n");
    printf("             |________________________________________________|\n");
    printf("             请输入您的需求：");
    int choice;
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\n\n");
        getchar();
        add_at_end();
        break;
    case 2:
        printf("\n\n");
        getchar();
        add_at_index();
        break;
    case 3:
        printf("\n\n");
        getchar();
        delete_by_id();
        break;
    case 4:
        printf("\n\n");
        getchar();
        delete_by_name();
        break;
    case 5:
        printf("\n\n");
        getchar();
        modify_by_id();
        break;
    case 6:
        printf("\n\n");
        getchar();
        modify_by_name();
        break;
    }
}


void Run() {
    bool Is_Running = true;
    while (Is_Running)
    {
        printf("\n");
        printf("            主菜单>>\n");
        printf("              ________________________________________________ \n");
        printf("             |                                                |\n");
        printf("             |            欢迎进入学生信息管理系统            |\n");
        printf("             |        ********************************        |\n");
        printf("             |        **       1.学生信息录入       **        |\n");
        printf("             |        ********************************        |\n");
        printf("             |        **       2.学生信息查询       **        |\n");
        printf("             |        ********************************        |\n");
        printf("             |        **       3.学生信息编辑       **        |\n");
        printf("             |        ********************************        |\n");
        printf("             |        **       4.学生信息展示       **        |\n");
        printf("             |        ********************************        |\n");
        printf("             |        **       0.退出系统           **        |\n");
        printf("             |        ********************************        |\n");
        printf("             |________________________________________________|\n");
        printf("             请输入您的需求：");

        int choice;
        scanf_s("%d", &choice);
        switch (choice)
        {
            case 0: Is_Running = false;
                    printf("\n感谢您的本次使用，再见！\n\n");
                    break;
            case 1:
                    getchar();
                    printf("\n\n");
                    add_student();
                    break;
            case 2:
                    printf("\n\n");
                    query();
                    break;
            case 3:
                    printf("\n\n");
                    modify();
                    break;
            case 4:
                    printf("\n\n");
                    show_all_students();
                    printf("\n若需进一步展示学生信息:\n\n");
                    show();
                    break;
        }
    }
}

int main() {
    Run();
    return 0;
}
