#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

//addition
void addition();
BOOL give_one_addition(int range);
void mistake_input_add(int a,int b,int c);
void mistake_read_and_copy(int number);

//加法训练
void addition(){
	int num, range, i, num_true = 0;
	time_t first, second;
	FILE *file;
	printf("小朋友，欢迎来到加法训练！\n\n");
	printf("你这次要挑战几道题呢？：");
	scanf("%d",&num);
	printf("要挑战多少以内的加法呢？:");

   	//判断输入的数据范围是否合法
	do{
		scanf("%d",&range);
		if(range <= 1){
			printf("要输入大于1的数哦！:");
		}
	} while(range <= 1);

	printf("\n好的！本次加法训练共%d题，数字都在%d以内！\n", num, range);
	printf("\n准备好了吗，按下Enter键就计时开始咯！\n");
	getchar();
	getchar();
	
	srand((unsigned)time(NULL));
	time(&first);
	for(i = 0;i < num;i++){
		if(give_one_addition(range)){
			num_true++;
		}
	}
	time(&second);
	printf("本次加法训练结束，共%d题，做对%d题，耗时%d秒，你真棒！\n", num, num_true, (unsigned)difftime(second,first));

	if(num != num_true){
		printf("\n你做错了下面几道题，已加入错题本中，要多多复习哟！\n");
		mistake_read_and_copy(num-num_true);
		file = fopen("tmp.txt","w");				//清空tmp.txt
		fclose(file);
	}
}

//生成一个加法题目并判断对错
BOOL give_one_addition(int range){ 					//range为范围
	int addend1,addend2,result,input;

    addend1 = rand() % range + 1;			//生成（1~范围）的随机数作为第一个加数
	do {
		addend2 = rand() % range + 1;		//生成（1~范围）的随机数作为第二个加数
        result = addend1 + addend2;
	} while(result > range);
	
    printf("%d+%d=", addend1, addend2);
	scanf("%d",&input);
	if(input == result){
		printf("回答正确！继续加油！\n\n");
		return TRUE;
	}else{
		printf("哎呀，不小心答错了，正确答案是%d，要细心哟！\n\n",result);
		mistake_input_add(addend1, addend2, result);
		return FALSE;
	}
}

//将加法错题写入tmp文件
void mistake_input_add(int a,int b,int c){
	FILE *fp = NULL;
	
	fp = fopen("tmp.txt", "a");
	fprintf(fp,"%d+%d=%d\n",a,b,c);
	fclose(fp);
}

//从tmp文件中读取错题输出并写入错题本
void mistake_read_and_copy(int number){
	int i;
	char str[255];
	FILE *ftmp = NULL;
	FILE *fmistakes = NULL;
	
	ftmp = fopen("tmp.txt", "r");
	fmistakes = fopen("mistakes.txt", "a+");
	
	for(i = 1;i <= number;i++){
		fscanf(ftmp,"%s",str);
		printf("%d:%s\n",i,str);
		fprintf(fmistakes,"%s\n",str);
	}
	fclose(ftmp);
	fclose(fmistakes);
}

int main(int argc, char const *argv[])
{
    addition();
    return 0;
}



