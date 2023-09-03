
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

    printf("������ѧ�ţ�");
    scanf("%s", new_student.student_id);
    printf("������������");
    scanf("%s", new_student.name);
    printf("������༶��");
    scanf("%s", new_student.class_name);
    printf("��������ѧ�ɼ���");
    scanf("%d", &(new_student.math_score));
    printf("������Ӣ��ɼ���");
    scanf("%d", &(new_student.english_score));
    printf("�����������ɼ���");
    scanf("%d", &(new_student.computer_score));

    new_student.average_score = (new_student.math_score + new_student.english_score + new_student.computer_score) / 3.0;

    students[num_students] = new_student;
    num_students++;
}

void search_student_by_id(char student_id[]) {
    int found = 0;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            printf("ѧ�ţ�%s\n", students[i].student_id);
            printf("������%s\n", students[i].name);
            printf("�༶��%s\n", students[i].class_name);
            printf("��ѧ�ɼ���%d\n", students[i].math_score);
            printf("Ӣ��ɼ���%d\n", students[i].english_score);
            printf("������ɼ���%d\n", students[i].computer_score);
            printf("ƽ���ɼ���%.2f\n", students[i].average_score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ���ѧ��\n");
    }
}

void search_student_by_name(char name[]) {
    int found = 0;

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("ѧ�ţ�%s\n", students[i].student_id);
            printf("������%s\n", students[i].name);
            printf("�༶��%s\n", students[i].class_name);
            printf("��ѧ�ɼ���%d\n", students[i].math_score);
            printf("Ӣ��ɼ���%d\n", students[i].english_score);
            printf("������ɼ���%d\n", students[i].computer_score);
            printf("ƽ���ɼ���%.2f\n", students[i].average_score);
            found = 1;
        }
    }

    if (!found) {
        printf("δ�ҵ���ѧ��\n");
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
        printf("δ�ҵ���ѧ��\n");
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
        printf("�������µ�������");
        scanf("%s", students[index].name);
        printf("�������µİ༶��");
        scanf("%s", students[index].class_name);
        printf("�������µ���ѧ�ɼ���");
        scanf("%d", &(students[index].math_score));
        printf("�������µ�Ӣ��ɼ���");
        scanf("%d", &(students[index].english_score));
        printf("�������µļ�����ɼ���");
        scanf("%d", &(students[index].computer_score));
        students[index].average_score = (students[index].math_score + students[index].english_score + students[index].computer_score) / 3.0;
    }
    else {
        printf("δ�ҵ���ѧ��\n");
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

    printf("��ѧƽ���ɼ���%.2f\n", math_average);
    printf("Ӣ��ƽ���ɼ���%.2f\n", english_average);
    printf("�����ƽ���ɼ���%.2f\n", computer_average);
    printf("��ѧ��߷֣�%d\n", math_max);
    printf("Ӣ����߷֣�%d\n", english_max);
    printf("�������߷֣�%d\n", computer_max);
    printf("��ѧ��ͷ֣�%d\n", math_min);
    printf("Ӣ����ͷ֣�%d\n", english_min);
    printf("�������ͷ֣�%d\n", computer_min);
    printf("��ѧ�����ʣ�%.2f%%\n", math_pass_rate);
    printf("Ӣ�Ｐ���ʣ�%.2f%%\n", english_pass_rate);
    printf("����������ʣ�%.2f%%\n", computer_pass_rate);
}

void output_student_info() {
    for (int i = 0; i < num_students; i++) {
        printf("ѧ�ţ�%s\n", students[i].student_id);
        printf("������%s\n", students[i].name);
        printf("�༶��%s\n", students[i].class_name);
        printf("��ѧ�ɼ���%d\n", students[i].math_score);
        printf("Ӣ��ɼ���%d\n", students[i].english_score);
        printf("������ɼ���%d\n", students[i].computer_score);
        printf("ƽ���ɼ���%.2f\n", students[i].average_score);
        printf("\n");
    }
}

int main() {
    int choice;
    char student_id[20];
    char name[50];

    while (1) {
        printf("ѧ����Ϣ����ϵͳ\n");
        printf("1. ���ѧ���ļ�¼\n");
        printf("2. ��ѯѧ������ѧ�ţ�\n");
        printf("3. ��ѯѧ������������\n");
        printf("4. ��ѧ���������򣨰�ƽ���ɼ���\n");
        printf("5. ��ѧ���������򣨰�������ɼ���\n");
        printf("6. ɾ��ѧ����¼\n");
        printf("7. �޸�ѧ����¼\n");
        printf("8. �༶�ɼ�����\n");
        printf("9. ���ѧ����Ϣ��\n");
        printf("0. �˳�\n");
        printf("����������ѡ��");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
                scanf("%s", student_id);
                search_student_by_id(student_id);
                break;
            case 3:
                printf("������Ҫ��ѯ��ѧ��������");
                scanf("%s", name);
                search_student_by_name(name);
                break;
            case 4:
                sort_by_average_score();
                printf("��ƽ���ɼ��Ľ����������\n");
                break;
            case 5:
                sort_by_computer_score();
                printf("��������ɼ��Ľ����������\n");
                break;
            case 6:
                printf("������Ҫɾ����ѧ��ѧ�ţ�");
                scanf("%s", student_id);
                delete_student(student_id);
                break;
            case 7:
                printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
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
                printf("�ټ���\n");
                return 0;
            default:
                printf("��Ч��ѡ�����������\n");
        }

        printf("\n");
    }
}

