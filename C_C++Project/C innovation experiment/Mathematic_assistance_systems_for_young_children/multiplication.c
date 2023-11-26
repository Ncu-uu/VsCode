#include "Mathematic_assistance_systems_for_young_children.h"

//乘法训练
void multiplication(){
	int num, range, i, num_true = 0;
	time_t first, second;
	FILE *file;
	printf("小朋友,欢迎来到乘法训练!\n\n");
	printf("你这次要挑战几道题呢？：");
	do{
		scanf("%d",&num);
		if(num <= 0){
			printf("要输入大于0的数哦!:");
		}
	} while(num <= 0);
	printf("要挑战多少以内的乘法呢？:");

	//判断输入的数据范围是否合法
	do{
		scanf("%d",&range);
		if(range <= 1){
			printf("要输入大于1的数哦!:");
		}
	} while(range <= 1);

	printf("\n好的!本次乘法训练共%d题,数字都在%d以内!\n", num, range);
	printf("\n准备好了吗,按下Enter键就计时开始咯!\n");
	getchar();
	getchar();
	
	time(&first);
	for(i = 0;i < num;i++){
		if(give_one_multiplication(range)){
			num_true++;
		}
	}
	time(&second);
	printf("本次乘法训练结束,共%d题,做对%d题,耗时%d秒,你真棒!\n", num, num_true, (unsigned)difftime(second,first));

	if(num != num_true){
		printf("\n你做错了下面几道题,已加入错题本中,要多多复习哟!\n");
		mistake_read_and_copy(num-num_true);
		file = fopen("tmp.txt","w");				//清空tmp.txt
		fclose(file);
	}
}

//生成一个乘法题目并判断对错
BOOL give_one_multiplication(int range){ 					//range为范围
	int factor1,factor2,result,input;
	srand((unsigned)time(NULL));
	
	factor1 = rand() % range/2 + 1;			//生成（1~范围除以2）的随机数作为第一个因数
	do {
		result = rand() % range + 1;		//生成（1~范围）的随机数作为第二个因数
	} while(result % factor1 != 0);			//确保能整除
	factor2 = result / factor1;				//计算第二个因数
	printf("%d×%d=", factor1, factor2);
	scanf("%d",&input);
	if(input == result){
		printf("回答正确!继续加油!\n\n");
		return TRUE;
	}else{
		printf("哎呀,不小心答错了,正确答案是%d,要细心哟!\n\n",result);
		mistake_input_mult(factor1,factor2,result);
		return FALSE;
	}
}





