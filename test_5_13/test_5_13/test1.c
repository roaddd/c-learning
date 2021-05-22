#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//利用函数指针数组实现简易计算器
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int div(int a, int b) {
	return a / b;
}
int main1() {
	int x, y;
	int input=1;
	int ret=0;
	int (*p[5])(int, int) = { 0,add,sub,mul,div };
	while (input) {
		printf("*************************\n");
		printf(" 1:add           2:sub \n");
		printf(" 3:mul           4:div \n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1)) {
			printf("输入操作数：");
			scanf("%d,%d", &x, &y);
			ret = p[input](x, y);
		}
		else
			printf("输入有误\n");
		printf("ret=%d\n", ret);
	}
	return 0;

}