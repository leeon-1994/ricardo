#include <stdio.h>
#include <stdlib.h>
#if 0 
int main01(int argc, char *argv[])
{
	/* 数组: 把若干相同数据类型变量存放在一块连续的内存中
		1. 符号与[]结合代表这个是数组
		2. 数组中的元素个数由[]里面的数值决定
		3. 每个元素的数据类型由数组名前面的类型决定
		4. 定义数组时,[]里面的值不能是变量
		5. 使用时,[]里面的值可以是变量也可以是常量
	*/
	int num[10];

	/*
		数组初始化
	*/
	int s[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n[10] = {0};
//	int r[10] = {[5]=5};

	printf("%d\n", sizeof(num));  // 数组大小
	// 数组元素个数
	int ret = sizeof(num) / sizeof(num[0]);
	for (int i=0; i < sizeof(s)/sizeof(s[0]); i++)
	{
		printf("%d\n", s[i]);
	}
	// 数组内存中地址
	printf("%u\n", &num[0]);
	printf("%u\n", num);
	printf("%u\n", &num);
	printf("--------\n");
	printf("%u\n", &num[0]+1);
	printf("%u\n", num+1);
	printf("%u\n", &num+1);

	// 数组交换
/*	int j = sizeof(s)/sizeof(s[0]) - 1;
	for (int i=0; i<sizeof(s)/sizeof(s[0]); i++)
	{
		if (i < j)
		{
			int temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			j--;
		}
		printf("%d\n", s[i]);
	}*/
	int i = 0;
	int temp;
	int j = sizeof(s)/sizeof(s[0]) - 1;
	while ( i < j )
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	for (int i=0; i<sizeof(s)/sizeof(s[0]); i++)
	{
		printf("%d\t", s[i]);
	}
	return 0;
}
int main02()
{
	// 冒泡排序
	int arr[] = { 3, 10, 33, 27, 99, 101 };
	for (int i=0; i < sizeof(arr)/sizeof(arr[0])-1; i++)  //比较的轮数
	{
		for (int j=0; j < sizeof(arr)/sizeof(arr[0])-1-i; j++)  // 没比较一轮，比较次数都需要减一，比较的次数等于n-1-i
		{
			// 比较相邻元素大小
			if ( arr[j] > arr[j+1] )
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (int i=0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}
int main03()
{
	// 二维数组
	int arr[2][4] = {
		{1,2,3,4},
		{5,6,7,8}
	};
	// 定义时不能省略列的下标
	int arr1[][3] = { 1, 2, 3 };
	// 元素个数
	int n = sizeof(arr) / sizeof(arr[0][0]);
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);

	int a[2][3];
	/*
		&a[0][0] + 1  元素地址加一，跨过一个元素
		a[0] + 1 元素地址加一，跨过一个元素
		&a[0] + 1 行地址加一，跨过一行
		a + 1  行地址加一，跨过一行
		&a + 1 二维数组地址加一，跨过整个数组
	*/
	return 0;
}
#endif 
int main()
{
	// 求各科平均分和不及格人数
	float score[][3] = {
		{ 77, 82.5, 93 },
		{ 88, 95, 100 },
		{ 100, 60, 33.3 },
		{ 27, 48, 56.5 },
		{ 77, 46.4, 68 }
	};
	float sum = 0.0;
	int man[3] = { 0 };
	float avg[3] = { 0 };
	printf("%d\n", sizeof(score[0])/sizeof(score[0][0]));
	printf("%d\n", sizeof(score)/sizeof(score[0]));
	for (int i=0; i < sizeof(score[0])/sizeof(score[0][0]); i++)
	{
		sum = 0.0;
		for (int j=0; j < sizeof(score)/sizeof(score[0]); j++)
		{
			sum = sum + score[j][i];
			if ( score[j][i] < 60)
			{
				man[i]++;
			}
		}
		avg[i] = sum / 5;
	}
	for (int i=0; i < sizeof(man)/sizeof(man[0]); i++)
	{
		printf("%d\n", man[i]);
	}
	for (int i=0; i < sizeof(avg)/sizeof(avg[0]); i++)
	{
		printf("%f\n", avg[i]);
	}
	return 0;
}
