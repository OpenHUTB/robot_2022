
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char student_id[20];
    char name[50];
    char class_name[50];
    int math_score;
    int english_score;
    int computer_score;
    float average_score;
};

struct Student students[MAX_STUDENTS];
int num_students = 0;

void add_student() {
    struct Student new_student;

    printf("请输入学号：");
    scanf("%s", new_student.student_id);
    printf("请输入姓名：");
    scanf("%s", new_student.name);
    printf("请输入班级：");
    scanf("%s", new_student.class_name);
    printf("请输入数学成绩：");
    scanf("%d", &(new_student.math_score));
    printf("请输入英语成绩：");
    scanf("%d", &(new_student.english_score));
    printf("请输入计算机成绩：");
    scanf("%d", &(new_student.computer_score));

    new_student.average_score = (new_student.math_score + new_student.english_score + new_student.computer_score) / 3.0;

    students[num_students] = new_student;
    num_students++;
}

void search_student_by_id(char student_id[]) {
    int found = 0;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            printf("学号：%s\n", students[i].student_id);
            printf("姓名：%s\n", students[i].name);
            printf("班级：%s\n", students[i].class_name);
            printf("数学成绩：%d\n", students[i].math_score);
            printf("英语成绩：%d\n", students[i].english_score);
            printf("计算机成绩：%d\n", students[i].computer_score);
            printf("平均成绩：%.2f\n", students[i].average_score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到该学生\n");
    }
}

void search_student_by_name(char name[]) {
    int found = 0;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("学号：%s\n", students[i].student_id);
            printf("姓名：%s\n", students[i].name);
            printf("班级：%s\n", students[i].class_name);
            printf("数学成绩：%d\n", students[i].math_score);
            printf("英语成绩：%d\n", students[i].english_score);
            printf("计算机成绩：%d\n", students[i].computer_score);
            printf("平均成绩：%.2f\n", students[i].average_score);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到该学生\n");
    }
}

void sort_by_average_score() {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].average_score < students[j + 1].average_score) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sort_by_computer_score() {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].computer_score < students[j + 1].computer_score) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void delete_student(char student_id[]) {
    int found = 0;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            found = 1;
            num_students--;
            break;
        }
    }

    if (!found) {
        printf("未找到该学生\n");
    }
}

void modify_student(char student_id[]) {
    int found = 0;
    int index;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            index = i;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("请输入新的姓名：");
        scanf("%s", students[index].name);
        printf("请输入新的班级：");
        scanf("%s", students[index].class_name);
        printf("请输入新的数学成绩：");
        scanf("%d", &(students[index].math_score));
        printf("请输入新的英语成绩：");
        scanf("%d", &(students[index].english_score));
        printf("请输入新的计算机成绩：");
        scanf("%d", &(students[index].computer_score));
        students[index].average_score = (students[index].math_score + students[index].english_score + students[index].computer_score) / 3.0;
    }
    else {
        printf("未找到该学生\n");
    }
}

void analyze_class_scores() {
    int math_sum = 0;
    int english_sum = 0;
    int computer_sum = 0;
    int math_max = 0;
    int english_max = 0;
    int computer_max = 0;
    int math_min = 100;
    int english_min = 100;
    int computer_min = 100;
    int math_pass_count = 0;
    int english_pass_count = 0;
    int computer_pass_count = 0;

    for (int i = 0; i < num_students; i++) {
        math_sum += students[i].math_score;
        english_sum += students[i].english_score;
        computer_sum += students[i].computer_score;

        if (students[i].math_score > math_max) {
            math_max = students[i].math_score;
        }
        if (students[i].english_score > english_max) {
            english_max = students[i].english_score;
        }
        if (students[i].computer_score > computer_max) {
            computer_max = students[i].computer_score;
        }

        if (students[i].math_score < math_min) {
            math_min = students[i].math_score;
        }
        if (students[i].english_score < english_min) {
            english_min = students[i].english_score;
        }
        if (students[i].computer_score < computer_min) {
            computer_min = students[i].computer_score;
        }

        if (students[i].math_score >= 60) {
            math_pass_count++;
        }
        if (students[i].english_score >= 60) {
            english_pass_count++;
        }
        if (students[i].computer_score >= 60) {
            computer_pass_count++;
        }
    }

    float math_average = (float)math_sum / num_students;
    float english_average = (float)english_sum / num_students;
    float computer_average = (float)computer_sum / num_students;
    float math_pass_rate = (float)math_pass_count / num_students * 100;
    float english_pass_rate = (float)english_pass_count / num_students * 100;
    float computer_pass_rate = (float)computer_pass_count / num_students * 100;

    printf("数学平均成绩：%.2f\n", math_average);
    printf("英语平均成绩：%.2f\n", english_average);
    printf("计算机平均成绩：%.2f\n", computer_average);
    printf("数学最高分：%d\n", math_max);
    printf("英语最高分：%d\n", english_max);
    printf("计算机最高分：%d\n", computer_max);
    printf("数学最低分：%d\n", math_min);
    printf("英语最低分：%d\n", english_min);
    printf("计算机最低分：%d\n", computer_min);
    printf("数学及格率：%.2f%%\n", math_pass_rate);
    printf("英语及格率：%.2f%%\n", english_pass_rate);
    printf("计算机及格率：%.2f%%\n", computer_pass_rate);
}

void output_student_info() {
    for (int i = 0; i < num_students; i++) {
        printf("学号：%s\n", students[i].student_id);
        printf("姓名：%s\n", students[i].name);
        printf("班级：%s\n", students[i].class_name);
        printf("数学成绩：%d\n", students[i].math_score);
        printf("英语成绩：%d\n", students[i].english_score);
        printf("计算机成绩：%d\n", students[i].computer_score);
        printf("平均成绩：%.2f\n", students[i].average_score);
        printf("\n");
    }
}

int main() {
    int choice;
    char student_id[20];
    char name[50];

    while (1) {
        printf("学生信息管理系统\n");
        printf("1. 添加学生的记录\n");
        printf("2. 查询学生（按学号）\n");
        printf("3. 查询学生（按姓名）\n");
        printf("4. 对学生数据排序（按平均成绩）\n");
        printf("5. 对学生数据排序（按计算机成绩）\n");
        printf("6. 删除学生记录\n");
        printf("7. 修改学生记录\n");
        printf("8. 班级成绩分析\n");
        printf("9. 输出学生信息表\n");
        printf("0. 退出\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                printf("请输入要查询的学生学号：");
                scanf("%s", student_id);
                search_student_by_id(student_id);
                break;
            case 3:
                printf("请输入要查询的学生姓名：");
                scanf("%s", name);
                search_student_by_name(name);
                break;
            case 4:
                sort_by_average_score();
                printf("按平均成绩的降序排序完成\n");
                break;
            case 5:
                sort_by_computer_score();
                printf("按计算机成绩的降序排序完成\n");
                break;
            case 6:
                printf("请输入要删除的学生学号：");
                scanf("%s", student_id);
                delete_student(student_id);
                break;
            case 7:
                printf("请输入要修改的学生学号：");
                scanf("%s", student_id);
                modify_student(student_id);
                break;
            case 8:
                analyze_class_scores();
                break;
            case 9:
                output_student_info();
                break;
            case 0:
                printf("再见！\n");
                return 0;
            default:
                printf("无效的选项，请重新输入\n");
        }

        printf("\n");
    }
}

