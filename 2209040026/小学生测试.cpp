#include<stdio.h>
#include<stdlib.h>///����rand()
#include <time.h>///srand()


int main() {
	int left, right,mid,result=0,answer;///left�Ӽ���������� right�Ӽ����ұ����� result��ʵ��� answer�û�����Ľ��
	int temp = 1,chance=1,grade=0;///temp����ʽ��� chance�û��ش���� grade�û��ɼ�


	for (int i = 0; i < 10; i++) {

		while (1){
			srand(time(NULL));///��ȡ�����������
			left = rand() % 51;///��ȡ�����
			right = rand() % 51;
			mid = rand() % 51;///��ȡһ�������������ӷ����Ǽ���
			if (mid % 2 == 0) result = left + right;///���mid��ż����ӷ�
			if (mid % 2 != 0 && left != 0) result = left - right;
			if (result >= 0 && result <= 50) { break; }///��ʵ�������Ҫ����������
		}

			if (mid % 2 == 0) {
				printf("(%d) %d+%d=", temp, left, right);
				scanf("%d", &answer);
				if (answer == result) {
					printf("回答正确ȷ\n");
					temp++;
					grade += 10; ///��һ�λش���ȷ �ɼ���ʮ��
				}
				if (answer != result) {
					printf("回答错误，请重新输入\n");
					printf("(%d) %d+%d=", temp, left, right);
					scanf("%d", &answer);
					if (answer == result) {
						printf("回答正确\n");
						temp++;
						grade += 7; ///�ڶ��λش���ȷ �ɼ����߷�
					}
					else {
						printf("回答错误，请重新输入\n");
						printf("(%d) %d+%d=", temp, left, right);
						scanf("%d", &answer);
						if (answer == result) {
							printf("回答正确\n");
							temp++;
							grade += 5; ///�����μ����
						}
						else {
							printf("回答错误，正确答案：%d\n", result);///���λ�������  �����ȷ�� 
							temp++; 
						}
					}
				}
			}
			else {///����ͬ�ӷ�
				printf("(%d) %d-%d=", temp, left, right);
				scanf("%d", &answer);
				if (answer == result) {
					printf("回答正确\n");
					temp++;
					grade += 10; 
				}
				if (answer != result) {
					printf("回答错误，请重新输入\n");
					printf("(%d) %d-%d=", temp, left, right);
					scanf("%d", &answer);
					if (answer == result) {
						printf("回答正确\n");
						temp++;
						grade += 7; 
					}
					else {
						printf("回答错误，请重新输入\n");
						printf("(%d) %d-%d=", temp, left, right);
						scanf("%d", &answer);
						if (answer == result) {
							printf("回答正确\n");
							temp++;
							grade += 5; 
						}
						else {
							printf("回答错误，正确答案：%d\n", result); 
							temp++; 
						}
					}
				}
			}
		
	}


	if (grade >= 90) printf("SMART\n");
	else if (grade >= 80 && grade < 90) printf("GOOD\n");
	else if (grade >= 70 && grade < 80)printf("OK\n");
	else if (grade >= 60 && grade < 70)printf("PASS\n");
	else printf("TRY-AGAIN\n");
}

