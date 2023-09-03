#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // 学生信息数组的最大长度
#define FILE_NAME "students.txt" // 学生信息文件名

// 学生信息结构体
typedef struct {
    char id[20]; // 学号
    char name[20]; // 姓名
    int age; // 年龄
    char gender[10]; // 性别
    char birth[20]; // 出生年月
    char address[100]; // 地址
    char phone[20]; // 电话
    char email[50]; // 邮箱
} Student;

// 学生信息数组和学生信息数量
Student students[MAX_SIZE];
int count = 0;

// 函数声明
void displayMenu();

void addStudent();

void viewStudents();

void searchStudent();

void deleteStudent();

void modifyStudent();

void saveToFile();

void readFromFile();

int main() {
    int choice;
    readFromFile(); // 从文件中读取学生信息

    do {
        displayMenu(); // 显示菜单
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                modifyStudent();
                break;
            case 6:
                saveToFile();
                printf("保存成功\n");
                break;
            case 7:
                printf("退出程序\n");
                break;
            default:
                printf("请输入正确的选项\n");
        }
    } while (choice != 7);

    return 0;
}

// 显示菜单
void displayMenu() {
    printf("\n学生信息管理系统\n");
    printf("-----------------\n");
    printf("1. 添加学生信息\n");
    printf("2. 浏览学生信息\n");
    printf("3. 查询学生信息\n");
    printf("4. 删除学生信息\n");
    printf("5. 修改学生信息\n");
    printf("6. 保存到文件\n");
    printf("7. 退出程序\n");
    printf("请输入选项：");
}

// 添加学生信息
void addStudent() {
    Student student;

    printf("\n请输入学生信息：\n");
    printf("学号：");
    scanf("%s", student.id);
    for (int i = 0; i < count; i++){
        if(strcmp(students[i].id, student.id) == 0){
            printf("学号已存在，请重新输入。\n");
            return;
        }
    }
    printf("姓名：");
    scanf("%s", student.name);
    printf("年龄：");
    scanf("%d", &student.age);
    printf("性别：");
    scanf("%s", student.gender);
    printf("出生年月：");
    scanf("%s", student.birth);
    printf("地址：");
    scanf("%s", student.address);
    printf("电话：");
    scanf("%s", student.phone);
    printf("E-mail：");
    scanf("%s", student.email);

    students[count++] = student;
}

// 浏览学生信息
void viewStudents() {
    printf("\n所有学生信息：\n");
    printf("%-15s%-10s%-10s%-10s%-15s%-30s%-20s%-30s\n", "学号", "姓名", "年龄", "性别", "出生年月", "地址", "电话", "E-mail");
    // 输出每个学生的信息
    for (int i = 0; i < count; i++) {
        printf("%-15s%-10s%-10d%-10s%-15s%-30s%-20s%-30s\n", students[i].id, students[i].name, students[i].age,
               students[i].gender, students[i].birth, students[i].address, students[i].phone, students[i].email);
    }
}

// 查询学生信息
void searchStudent() {
    int choice;
    char id[20];
    char name[20];
    int found = 0;

    printf("\n查询学生信息：\n");
    printf("1. 按学号查询\n");
    printf("2. 按姓名查询\n");
    printf("请选择查询方式：");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("请输入要查询的学号：");
            scanf("%s", id);
            printf("\n%-15s%-10s%-10s%-10s%-15s%-30s%-20s%-30s\n", "学号", "姓名", "年龄", "性别", "出生年月", "地址", "电话", "E-mail");
            for (int i = 0; i < count; i++) {
                if (strcmp(students[i].id, id) == 0) {
                    printf("%-15s%-10s%-10d%-10s%-15s%-30s%-20s%-30s\n", students[i].id, students[i].name,
                           students[i].age, students[i].gender, students[i].birth, students[i].address,
                           students[i].phone, students[i].email);
                    found = 1;
                    break;
                }
            }
            break;
        case 2:
            printf("请输入要查询的姓名：");
            scanf("%s", name);
            printf("\n%-15s%-10s%-10s%-10s%-15s%-30s%-20s%-30s\n", "学号", "姓名", "年龄", "性别", "出生年月", "地址", "电话", "E-mail");
            for (int i = 0; i < count; i++) {
                if (strcmp(students[i].name, name) == 0) {
                    printf("%-15s%-10s%-10d%-10s%-15s%-30s%-20s%-30s\n", students[i].id, students[i].name,
                           students[i].age, students[i].gender, students[i].birth, students[i].address,
                           students[i].phone, students[i].email);
                    found = 1;
                }
            }
            break;
        default:
            printf("请输入正确的选项\n");
    }

    if (!found) {
        printf("未找到该学生信息\n");
    }
}

// 删除学生信息
void deleteStudent() {
    char id[20];
    int found = 0;

    printf("\n请输入要删除的学生学号：");
    scanf("%s", id);

// 遍历已有的学生信息，找到要删除的学生信息
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            // 将该学生信息从数组中删除
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("删除成功\n");
            break;
        }
    }

    if (!found) {
        printf("未找到该学生信息\n");
    }
}

// 修改学生信息
void modifyStudent() {
    char id[20];
    int found = 0;

    printf("\n请输入要修改的学生学号：");
    scanf("%s", id);

// 遍历已有的学生信息，找到要修改的学生信息
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            printf("\n请输入学生信息：\n");
            printf("学号：%s（不可修改）\n", students[i].id);
            printf("姓名：");
            scanf("%s", students[i].name);
            printf("年龄：");
            scanf("%d", &students[i].age);
            printf("性别：");
            scanf("%s", students[i].gender);
            printf("出生年月：");
            scanf("%s", students[i].birth);
            printf("地址：");
            scanf("%s", students[i].address);
            printf("电话：");
            scanf("%s", students[i].phone);
            printf("E-mail：");
            scanf("%s", students[i].email);
            printf("修改成功\n");
            break;
        }
    }

    if (!found) {
        printf("未找到该学生信息\n");
    }
}

// 将学生信息保存到文件
void saveToFile() {
    FILE *fp;
    fp = fopen(FILE_NAME, "w");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%d,%s,%s,%s,%s,%s\n", students[i].id, students[i].name, students[i].age, students[i].gender,
                students[i].birth, students[i].address, students[i].phone, students[i].email);
    }

    fclose(fp);
}

// 从文件中读取学生信息
void readFromFile() {
    FILE *fp;
    char line[500];
    char *token;
    const char delim[2] = ",";
    fp = fopen(FILE_NAME, "r");

    if (fp) {
        count = 0;
        while (fgets(line, 500, fp)) {
            // 将读取到的学生信息按逗号分隔，并依次填充到学生信息结构体中
            token = strtok(line, delim);
            strcpy(students[count].id, token);
            token = strtok(NULL, delim);
            strcpy(students[count].name, token);
            token = strtok(NULL, delim);
            students[count].age = atoi(token);
            token = strtok(NULL, delim);
            strcpy(students[count].gender, token);
            token = strtok(NULL, delim);
            strcpy(students[count].birth, token);
            token = strtok(NULL, delim);
            strcpy(students[count].address, token);
            token = strtok(NULL, delim);
            strcpy(students[count].phone, token);
            token = strtok(NULL, delim);
            // 如果当前字符是换行符，则跳过这个字符
            if (token[strlen(token) - 1] == '\n') {
                token[strlen(token) - 1] = '\0';
            }
            strcpy(students[count].email, token);
            count++;
        }

        fclose(fp);
    }
}

