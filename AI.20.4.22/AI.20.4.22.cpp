#include <stdio.h>
#include <string.h>		//字符串相关C标准库
#include <stdlib.h>		//

char zi4[100];
char shu1ru4[100];
char shu1chu1[100];



static size_t len;

/*颠倒函数规则*/
void dian1dao3() {

	for (int a = 0; a < len; a += 2) {
		shu1chu1[a] = shu1ru4[len - 2 - a];
		shu1chu1[a + 1] = shu1ru4[len - a - 1];
	}
}

/*输出运行代码到文本*/
int shu1chu1Code() {
	FILE* Code, * fpCode;
	errno_t err1, err2;
	char c;

	err1 = fopen_s(&Code, __FILE__, "r");
	err2 = fopen_s(&fpCode, "Code.txt", "w");

	do {
		c = getc(Code);
		fputc(c, fpCode);
	} while (c != EOF);

	fclose(Code);
	fclose(fpCode);
	return 0;
}

/*打开文件*/
void Openwen2jian4_zi() {
	/*定义文件指针*/
	FILE* fpzi;
	/*判断此文件流是否存在 存在返回1*/
	errno_t err;
	/*打开zi.txt文件*/
	err = fopen_s(&fpzi, "zi.txt", "a+");
	/*判断文件是否打开失败*/
	if (err != 0) {
		puts("zi.txt 文件打开失败");
		exit(1);
	}
}

/*读取zi文件数据到数组zi4*/
void du4qu3Data() {
	/*定义文件指针*/
	FILE* fp;
	/*读取缓存*/
	//char c2;
	/*挨个读取数据*/



}




int main() {
	/*打开文件*/
	//定义文件指针
	FILE* fpzi, * fpzibf;
	//判断此文件流是否存在 存在返回1
	errno_t err, err_bf;
	//打开zi.txt文件并判断是否打开失败
	err = fopen_s(&fpzi, "zi.txt", "a+");
	if (err != 0) {
		puts("zi.txt 文件打开失败");
		exit(1);
	}
	//打开zibei4fen4.txt文件并判断是否打开失败
	err_bf = fopen_s(&fpzibf, "zibei4fen4.txt", "w");
	if (err_bf != 0) {
		puts("zibei4fen4.txt 文件打开失败");
		exit(1);
	}

	/*读取zi文件数据到数组zi4*/
	//读取缓存
	char c1;
	//读取计数
	static int num = 0;
	//逐字读取数据到数组zi4
	do {
		c1 = getc(fpzi);
		zi4[num] = c1;
		num++;
	} while (c1 != EOF);


	/*交互界面*/
	//输入
	printf("你想对我说：");
	//获取屏幕输入的字符
	gets_s(shu1ru4);
	//检测字符长度
	len = strlen(shu1ru4);
	//输出
	printf("豆子说：");
	//输出豆子的话
	puts(shu1chu1);

	/*将新数据写入zi.txt*/
	//检测输入数据与已有数据的差别


	//写入新数据
	char c_new;
	static int num_new = 0;
	do {
		c_new = shu1ru4[num_new];
		c_new += 1;
		fputc(c_new, fpzi);
		num_new++;
	} while (num_new != len);







	/*关闭文件并检测是否失败*/
	int guan1bi4Tag;
	guan1bi4Tag = fclose(fpzi);
	if (guan1bi4Tag == EOF) {
		puts("zi.txt 文件关闭失败");
		exit(1);
	}

	/*输出代码*/
	shu1chu1Code();

	printf("-----End-----");
	return 0;
}



//void za2huo4Code() {
//	/*向文件写入一个字符串*/
//	int xie3ru4Tag;
//	xie3ru4Tag = fputs("我是豆子\n", fpzi);
//	/*判断文件是否写入失败*/
//	if (xie3ru4Tag == EOF) {
//		puts("zi.txt 文件写入失败");
//		exit(1);
//	}
//
//
//	/*备份：将数组zi4数据写入zibei4fen4.txt*/
//	static int num_bf = 0;
//	char c_bf;
//	do {
//		c_bf = zi4[num_bf];
//		fputc(c_bf, fpzibf);
//		num_bf++;
//	} while (num_bf != (num - 1));
//
//
//	printf("你想对我说：");
//	/*获取屏幕输入的字符*/
//	gets_s(shu1ru4);
//	/*检测字符长度*/
//	len = strlen(shu1ru4);
//	/*颠倒字符*/
//	dian1dao3();
//
//	printf("豆子说：");
//	/*输出豆子的话*/
//	puts(shu1chu1);
//
//
//
//}