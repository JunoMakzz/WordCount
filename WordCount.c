#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int OperatorJudge(char para[3])//判断使用字符计数或者单词计数函数
{
	if (para[0] == '-' && para[1] == 'c')
		return 1;
	else if (para[0] == '-' && para[1] == 'w')
		return 2;
	else
		return 0;
}

void CountChar(char filetext[100])//字符计数函数
{
	int count = 0;
	FILE* fp = fopen(filetext, "r");//打开txt文件
	if (fp == NULL)
	{
		printf("文件打开失败或者文件不存在!\n");
		exit(0);
	}
	while (fgetc(fp) != EOF)
	{
		count++;
	}
	printf("字符数: %d", count);
	printf("\n");
	fclose(fp);//关闭txt文本文件
}

void CountWord(char filetext[100])
{
	int count = 0;
	char c;
	int flag = 0;
	FILE* fp = fopen(filetext, "r");
	if (fp == NULL)
	{
		printf("文件打开失败或者文件不存在!\n");
		exit(0);
	}
	while ((c = fgetc(fp))!= EOF)
	{
		if (flag == 0 && c != ' ' && c != ',')
		{
			flag = 1;
			count++;
		}
		if (flag == 1 && (c == ' ' || c == ',' || c == '\t' || c == '\n'))
			flag = 0;

	}
	printf("单词数: %d", count);
	printf("\n");
	fclose(fp);
}

int main()
{
	char para[3], filetext[100];
	int result = 0;
	printf("请输入控制参数('-c'或'-w')和文本文件名，中间用空格隔开\n");
	scanf("%s", para);
	scanf("%s", filetext);
	result = OperatorJudge(para);
	if (result == 0)
		printf("控制参数输入错误!");
	else if (result == 1)
		CountChar(filetext);
	else if (result == 2)
		CountWord(filetext);
}