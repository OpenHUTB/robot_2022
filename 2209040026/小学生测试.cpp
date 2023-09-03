#include<stdio.h>
#include<stdlib.h>///包含rand()
#include <time.h>///srand()


int main() {
	int left, right,mid,result=0,answer;///left加减法左边数字 right加减法右边数字 result真实结果 answer用户输入的结果
	int temp = 1,chance=1,grade=0;///temp算术式编号 chance用户回答次数 grade用户成绩


	for (int i = 0; i < 10; i++) {

		while (1){
			srand(time(NULL));///获取随机数的种子
			left = rand() % 51;///获取随机数
			right = rand() % 51;
			mid = rand() % 51;///获取一个数用来决定加法还是减法
			if (mid % 2 == 0) result = left + right;///如果mid是偶数则加法
			if (mid % 2 != 0 && left != 0) result = left - right;
			if (result >= 0 && result <= 50) { break; }///真实结果符合要求则进行输出
		}

			if (mid % 2 == 0) {
				printf("(%d) %d+%d=", temp, left, right);
				scanf("%d", &answer);
				if (answer == result) {
					printf("鍥炵瓟姝ｇ‘确\n");
					temp++;
					grade += 10; ///第一次回答正确 成绩加十分
				}
				if (answer != result) {
					printf("鍥炵瓟閿欒锛岃閲嶆柊杈撳叆\n");
					printf("(%d) %d+%d=", temp, left, right);
					scanf("%d", &answer);
					if (answer == result) {
						printf("鍥炵瓟姝ｇ‘\n");
						temp++;
						grade += 7; ///第二次回答正确 成绩加七分
					}
					else {
						printf("鍥炵瓟閿欒锛岃閲嶆柊杈撳叆\n");
						printf("(%d) %d+%d=", temp, left, right);
						scanf("%d", &answer);
						if (answer == result) {
							printf("鍥炵瓟姝ｇ‘\n");
							temp++;
							grade += 5; ///第三次加五分
						}
						else {
							printf("鍥炵瓟閿欒锛屾纭瓟妗堬細%d\n", result);///三次机会用完  输出正确答案 
							temp++; 
						}
					}
				}
			}
			else {///减法同加法
				printf("(%d) %d-%d=", temp, left, right);
				scanf("%d", &answer);
				if (answer == result) {
					printf("鍥炵瓟姝ｇ‘\n");
					temp++;
					grade += 10; 
				}
				if (answer != result) {
					printf("鍥炵瓟閿欒锛岃閲嶆柊杈撳叆\n");
					printf("(%d) %d-%d=", temp, left, right);
					scanf("%d", &answer);
					if (answer == result) {
						printf("鍥炵瓟姝ｇ‘\n");
						temp++;
						grade += 7; 
					}
					else {
						printf("鍥炵瓟閿欒锛岃閲嶆柊杈撳叆\n");
						printf("(%d) %d-%d=", temp, left, right);
						scanf("%d", &answer);
						if (answer == result) {
							printf("鍥炵瓟姝ｇ‘\n");
							temp++;
							grade += 5; 
						}
						else {
							printf("鍥炵瓟閿欒锛屾纭瓟妗堬細%d\n", result); 
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

