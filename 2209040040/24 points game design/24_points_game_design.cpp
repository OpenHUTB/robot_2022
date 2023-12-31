#include <stdio.h>
#include <stdbool.h>

bool solve24(int cards[], int n);
bool backtrack(int nums[], int n, int target);
bool calculate(int a, int b, int result);
void printSolution(int nums[], int operators[], int n);

int main() {
    int cards[4];

    printf("请输入四张牌的数字(1-13之间，输入0表示结束)：\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &cards[i]);
        if (cards[i] == 0) {
            break;
        }
    }

    if (solve24(cards, 4)) {
        printf("成功！可以通过加减乘除计算得到24。\n");
    } else {
        printf("失败！无法通过加减乘除计算得到24。\n");
    }

    return 0;
}

bool solve24(int cards[], int n) {
    int nums[4];
    for (int i = 0; i < n; i++) {
        nums[i] = cards[i];
    }

    return backtrack(nums, n, 24);
}

bool backtrack(int nums[], int n, int target) {
    if (n == 1) {
        if (nums[0] == target) {
            printf("计算过程：\n");
            printSolution(nums, NULL, 1);
            return true;
        } else {
            return false;
        }
    }

    bool found = false;
    int temp[4];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int m = 0;


            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    temp[m++] = nums[k];
                }
            }

            int a = nums[i];
            int b = nums[j];

    
            temp[m] = a + b;
            if (backtrack(temp, n - 1, target)) {
                found = true;
                printf("+ ");
                printSolution(&a, &b, 2);
                break;
            }

     
            temp[m] = a - b;
            if (backtrack(temp, n - 1, target)) {
                found = true;
                printf("- ");
                printSolution(&a, &b, 2);
                break;
            }


            temp[m] = a * b;
            if (backtrack(temp, n - 1, target)) {
                found = true;
                printf("* ");
                printSolution(&a, &b, 2);
                break;
            }


            if (b != 0 && a % b == 0) {
                temp[m] = a / b;
                if (backtrack(temp, n - 1, target)) {
                    found = true;
                    printf("/ ");
                    printSolution(&a, &b, 2);
                    break;
                }
            }
        }

        if (found) {
            break;
        }
    }

    return found;
}

bool calculate(int a, int b, int result) {
    if (a + b == result || a - b == result || a * b == result || (b != 0 && a % b == result)) {
        return true;
    } else if (b - a == result || (a != 0 && b % a == result)) {
        return true;
    } else {
        return false;
    }
}

void printSolution(int nums[], int operators[], int n) {
    if (operators == NULL) {
        printf("%d\n", nums[0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
        if (i < n-1) {
            switch (operators[i]) {
                case '+':
                    printf("+ ");
                    break;
                case '-':
                    printf("- ");
                    break;
                case '*':
                    printf("* ");
                    break;
                case '/':
                    printf("/ ");
                    break;
            }
        }
    }

    printf("= %d\n", nums[n-1]);
}
