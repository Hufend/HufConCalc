#include <stdio.h>
#include <stdlib.h>
#include "../../Library/basic.h"
FILE* file;
double power(double,int);
double calculation();
double power(double value1,int value2){
	if(value2 == 0) return 1;
	for(int record = 0;record < value2;record++) value1 *= value1;
	return value1;
}
double calculation(){
	// 申请内存

	char text[10];
	char* report = malloc(1);
	char length;
	char mode[3] = {0/*运算模式*/,0/*是否经过加减运算*/,0/*加减运算区分*/};
	double result;
	double number;
	double buffer1;

	// 运算

	// 加
	void addition(){
		mode[1] = 1;
		mode[2] = 1;
		result += number;
		buffer1 = number;
	}
	// 减
	void subtraction(){
		mode[1] = 1;
		mode[2] = 0;
		result -= number;
		buffer1 = number;
	}
	// 乘
	void multiplication(){
		if(mode[1]){
			if(mode[2]) result -= buffer1;
			else result += buffer1;
			buffer1 *= number;
			if(mode[2]) result += buffer1;
			else result -= buffer1;
		}else result *= number;
	}
	// 除
	void division(){
		if(number){
			if(mode[1]){
				if(mode[2]) result -= buffer1;
				else result += buffer1;
				buffer1 /= number;
				if(mode[2]) result += buffer1;
				else result -= buffer1;
			}else result *= number;
		}else printf("数学错误:除数不能为0\a\n");
	}

	// 交互处理
	start:
		if(!scanf("%lf",&result)) goto exception;
		fprintf(file,"%f",result);
	loop:
		scanf("%s",text);
		length = toCharacterLength(text);
		if(length == 1){
			if(compare(text,"+",1)){
				fprintf(file,"+");
				mode[0] = 1;
				if(!scanf("%lf",&number)) goto exception;
				fprintf(file,"%f",number);
				addition();
			}else if(compare(text,"-",1)){
				fprintf(file,"-");
				mode[0] = 2;
				if(!scanf("%lf",&number)) goto exception;
				fprintf(file,"%f",number);
				subtraction();
			}else if(compare(text,"*",1)){
				fprintf(file,"*");
				mode[0] = 3;
				if(!scanf("%lf",&number)) goto exception;
				fprintf(file,"%f",number);
				multiplication();
			}else if(compare(text,"/",1)){
				fprintf(file,"/");
				mode[0] = 4;
				if(!scanf("%lf",&number)) goto exception;
				fprintf(file,"%f",number);
				division();
			}else if(compare(text,"=",1) || compare(text,")",1) || compare(text,"]",1) || compare(text,"}",1)) return result;
		}else if(length == 4 && compare(text,"退出",4)){
			goto ProgramExit;
		}else goto UnknownText;
		goto loop;
	exception:
		scanf("%s",text);
		length = toCharacterLength(text);
		if(length == 4){
			if(compare(text,"退出",4)){
				goto ProgramExit;
			}else if(compare(text,"帮助",4)){
				printf("按照平常写算式就行了\n注意运算符后面一定要加空格或回车\n");
			}else printf("错误的数字\a\n");
		}else if(length == 1 && (compare(text,"(",1) || compare(text,"[",1) || compare(text,"{",1))){
			fprintf(file,"(");
			number = calculation();
			fprintf(file,")");
			if(mode[0] == 1){
				addition();
			}else if(mode[0] == 2){
				subtraction();
			}else if(mode[0] == 3){
				multiplication();
			}else if(mode[0] == 4){
				division();
			}else{
				report = realloc(report,86);
				copy(report,"异常类型:内存异常\n异常变量:mode\n位置:栈\n类型:char\n下标:0\n异常原因:变量的值在预期之外\n",85);
				goto MemoryException;
			}
			goto loop;
		}else printf("错误的数字\a\n");
		goto start;

	// 信息处理
	MemoryException:
		printf("内存异常\n请报告给开发人员\n%s",report);
		return 0;
	UnknownText:
		printf("未知运算符号\a\n");
		goto loop;
	ProgramExit:
		printf("已退出程序\n");
		free(report);
		exit(0);
}
int main(){
	system("title Calculator运算");
	printf("欢迎使用Calculator运算\n");
	fopen_s(&file,"./calculate.log","a");
	double result;
	calculate:
		result = calculation();
		printf("%f\n\n",result);
		fprintf(file,"=%f\n\n",result);
		goto calculate;
}