#include<stdio.h>
//请简述大端字节序和小端字节序的概念，设计一个小程序来判断当前机器的字节序
int check_sys() {
	int i = 1;
	return *((char*)&i);

}
int main() {
	if (check_sys()) {
		printf("小端\n");
	}
	else {
		printf("大端\n");
	}
	return 0;
}