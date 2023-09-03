
#include <stdio.h>
#include <string.h>

#define MAX_DEVICES 100

// 设备信息结构体
typedef struct {
    int id;
    char type[50];
    char name[50];
    double price;
    char purchaseDate[11];
    int isScrapped;
    char scrappedDate[11];
} Device;

// 全局变量
Device devices[MAX_DEVICES];
int count = 0;

// 函数声明
void displayMenu();
void addDevice();
void modifyDevice();
void classifyDevices();
void processDamagedDevices();
void searchDevice();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("请输入选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDevice();
                break;
            case 2:
                modifyDevice();
                break;
            case 3:
                classifyDevices();
                break;
            case 4:
                processDamagedDevices();
                break;
            case 5:
                searchDevice();
                break;
            case 0:
                printf("感谢使用实验设备管理系统！\n");
                return 0;
            default:
                printf("无效的选择，请重新输入。\n");
        }
    }
}

// 显示菜单
void displayMenu() {
    printf("\n************* 实验设备管理系统 *************\n");
    printf("1. 录入设备信息\n");
    printf("2. 修改设备信息\n");
    printf("3. 设备分类统计\n");
    printf("4. 设备破损耗费和遗损处理\n");
    printf("5. 查询设备\n");
    printf("0. 退出系统\n");
    printf("*******************************************\n");
}

// 录入设备信息
void addDevice() {
    if (count == MAX_DEVICES) {
        printf("设备数量已达上限，无法录入更多设备。\n");
        return;
    }

    Device device;

    printf("请输入设备编号：");
    scanf("%d", &device.id);

    printf("请输入设备种类：");
    scanf("%s", device.type);

    printf("请输入设备名称：");
    scanf("%s", device.name);

    printf("请输入设备价格：");
    scanf("%lf", &device.price);

    printf("请输入设备购入日期（YYYY-MM-DD）：");
    scanf("%s", device.purchaseDate);

    printf("是否报废（1-是，0-否）：");
    scanf("%d", &device.isScrapped);

    if (device.isScrapped == 1) {
        printf("请输入设备报废日期（YYYY-MM-DD）：");
        scanf("%s", device.scrappedDate);
    }

    devices[count++] = device;

    printf("设备录入成功。\n");
}

// 修改设备信息
void modifyDevice() {
    int id;
    int i;
    int found = 0;

    printf("请输入要修改的设备编号：");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (devices[i].id == id) {
            printf("请输入设备种类：");
            scanf("%s", devices[i].type);

            printf("请输入设备名称：");
            scanf("%s", devices[i].name);

            printf("请输入设备价格：");
            scanf("%lf", &devices[i].price);

            printf("请输入设备购入日期（YYYY-MM-DD）：");
            scanf("%s", devices[i].purchaseDate);

            printf("是否报废（1-是，0-否）：");
            scanf("%d", &devices[i].isScrapped);

            if (devices[i].isScrapped == 1) {
                printf("请输入设备报废日期（YYYY-MM-DD）：");
                scanf("%s", devices[i].scrappedDate);
            }

            found = 1;
            printf("设备信息修改成功。\n");
            break;
        }
    }

    if (!found) {
        printf("未找到设备编号为%d的设备。\n", id);
    }
}

// 设备分类统计
void classifyDevices() {
    int i;
    int computerCount = 0;
    int printerCount = 0;
    int scannerCount = 0;
    int otherCount = 0;

    for (i = 0; i < count; i++) {
        if (strcmp(devices[i].type, "微机") == 0) {
            computerCount++;
        }
        else if (strcmp(devices[i].type, "打印机") == 0) {
            printerCount++;
        }
        else if (strcmp(devices[i].type, "扫描仪") == 0) {
            scannerCount++;
        }
        else {
            otherCount++;
        }
    }

    printf("设备分类统计结果：\n");
    printf("微机：%d台\n", computerCount);
    printf("打印机：%d台\n", printerCount);
    printf("扫描仪：%d台\n", scannerCount);
    printf("其他设备：%d台\n", otherCount);
}

// 设备破损耗费和遗损处理
void processDamagedDevices() {
    int id;
    int i;
    int found = 0;

    printf("请输入要处理的设备编号：");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (devices[i].id == id) {
            if (devices[i].isScrapped == 1) {
                printf("设备已报废。\n");
            }
            else {
                devices[i].isScrapped = 1;
                printf("请输入设备报废日期（YYYY-MM-DD）：");
                scanf("%s", devices[i].scrappedDate);
                printf("设备报废处理成功。\n");
                found = 1;
            }
            break;
        }
    }

    if (!found) {
        printf("未找到设备编号为%d的设备。\n", id);
    }
}

// 查询设备
void searchDevice() {
    int id;
    int i;
    int found = 0;

    printf("请输入要查询的设备编号：");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (devices[i].id == id) {
            printf("设备编号：%d\n", devices[i].id);
            printf("设备种类：%s\n", devices[i].type);
            printf("设备名称：%s\n", devices[i].name);
            printf("设备价格：%.2lf\n", devices[i].price);
            printf("设备购入日期：%s\n", devices[i].purchaseDate);
            if (devices[i].isScrapped == 1) {
                printf("设备报废日期：%s\n", devices[i].scrappedDate);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到设备编号为%d的设备。\n", id);
    }
}
