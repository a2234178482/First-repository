#define _CRT_SECURE_NO_WARNINGS 1
//写一个c语言程序
//
// 
// 
// int main()
//{
//	printf("hello C\n");
//	return 0;
//}

//旧时写法
//void main()
//{
//
//
//} 
 
// void main (void)
//int main()
//{
//	printf("hehe\n");
//	printf("呵呵");//双引号括起来的就是一个字符串
//	return 0;
//}
//

//%d - 整型的打印
//%c - 字符的打印
//%f = 打印小数
//%s - 打印字符串，遇到\0结束

#include <stdio.h>
//
//int main()
//{
//	printf("hello world\n");//\n是换行
//	printf("%d\n", 100);
//	printf("%c\n", 'X');//单引号引起来是字符
//	printf("%f\n", 3.14);
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	int ret = 0;
//
//	return 0;
//}


//int main()
//{
//	//'a';//97
//	//'q';
//	//'#';
//
//	printf("%c\n", 'a');
//	printf("%d\n", 'a');
//	return 0;
//}
//

//
//int main()
//{
//	printf("%c\n", 'z');
//	printf("%c\n", 122);
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 32; i <= 127; i++)
//	{
//		printf("%c ", i);
//	}
//	return 0;
//}

//%s - 打印字符串
//
//int main()
//{
//	//printf("abcdef\n");
//	//printf("%s", "abcdef");
//
//	return 0;
//}
//


//数组 - 一组数据
//
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a', 'b', 'c','\0'};
//
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//	printf("%s\n", "abc\0def");//?
//
//	return 0;
//}
//
//

//int main()
//{
//	printf("%s\n", "abc\ndef");
//
//	return 0;
//}


//    \?  这种转义字符基本用不上了
//  三字母词
// ??) -- ]
// ??( -- [
//
//
//int main()
//{
//	//printf("(are you ok\?\?)");
//	//(are you ok]
//
//	//printf("%c\n", 'a');
//	//printf("%c\n", 'x');
//	//printf("%c\n", '\'');
//
//	//printf("%s\n", "abc");
//	//printf("%s\n", "a");
//	//printf("%s\n", "\"");
//
//	//printf("c:\\test\\test.c");
//	//printf("\a");
//	//printf("abcdef\n");
//	//printf("abc\bdef\n");
//	//abdef
//
//	printf("a\tbc\tdef\tqwertyu");
//	return 0;
//}


int main()
{
	//10进制的数字：0~9数组组成的
	//8进制的数字：0~7的数组成的

	printf("%c\n", '\132');//'Z'
	printf("%c\n", '\x61');//'a'

	return 0;
}