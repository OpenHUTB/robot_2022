#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));
    int score = 0;
    
    
	for (int i = 0; i < 10; i++) {
	int num1,num2,result, answer, attempt = 0;
	
	char operator1;
		do{
			num1 = generateRandomNumber(0, 50);
			num2 = generateRandomNumber(0, 50);
        
			int operation = generateRandomNumber(1, 2);
			if (operation == 1) {
				operator1 = '+';
				result = num1 + num2;
			} else {
				operator1 = '-';
				if(num1>num2)
					result = num1 - num2;
				else{
					int temp=num1;
					num1=num2;
					num2=temp;
					result = num1 - num2;
				}
			}
			if(result >= 0 && result <= 50)
				break;
        }while(true);

        printf("问题 %d:\n", i+1);
        printf("%d %c %d = ?\n", num1, operator1, num2);
        
        do {
            printf("请输入你的答案: ");
            if (scanf("%d", &answer) != 1) {
                printf("输入无效，请输入一个有效的整数。\n");
                while (getchar() != '\n');
                continue;
            }
            
            attempt++;
            
            if (answer == result) {
                if (attempt == 1) {
                    score += 10;
                } else if (attempt == 2) {
                    score += 7;
                } else if (attempt == 3) {
                    score += 5;
                }
                
                break;
            } else {
                printf("答案错误，请重试。\n");
            }
        } while (attempt < 3);
        
        if (attempt >= 3) {
            printf("错误！正确答案是 %d\n", result);
        }
        
        printf("\n");
    }
    
    printf("你的最终得分是: %d\n", score);
    
    return 0;
}