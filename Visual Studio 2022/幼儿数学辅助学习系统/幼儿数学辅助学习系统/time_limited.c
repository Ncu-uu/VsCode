#include "Mathematic_assistance_systems_for_young_children.h"

// 限时的综合训练
void time_limited(){
	int tlm, range, num, second = 1, total_num = 0, true_num = 0, false_num = 0;
	time_t start_time, current_time;
	FILE *file;

	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("         小朋友，欢迎来到限时挑战！         \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("要做多少秒以内的限时挑战呢？：");
	do{
		scanf("%d",&tlm);
		if(tlm < 10){
			printf("要输入至少为10的数哦!:");
		}
	} while(tlm < 10);

	printf("请输入本次训练的数字范围：");
	do{
		scanf("%d",&range);
		if(range < 100){
			printf("要输入至少为100的数哦!:");
		}
	} while(range < 100);

	printf("\n好的!本次限时挑战共%d秒,数字都在%d以内!\n", tlm, range);
	printf("\n准备好了吗,按下Enter键就计时开始咯!\n");
	getchar();
	getchar();
	
	// 倒计时60s
	start_time=time(NULL);
	while(second > 0){
		// 生成1-4的随机数
		srand((unsigned)time(NULL));
		num = rand() % 4 + 1;
		switch (num){
			case 1:
				total_num++;
				if(give_one_addition(range)){
					true_num++;
				}
				else{
					false_num++;
				}
				break;
			case 2:
				total_num++;
				if(give_one_subtraction(range)){
					true_num++;
				}
				else{
					false_num++;
				}
				break;
			case 3:
				total_num++;
				if(give_one_multiplication(range)){
					true_num++;
				}
				else{
					false_num++;
				}
				break;
			case 4:
				total_num++;
				if(give_one_division(range)){
					true_num++;
				}
				else{
					false_num++;
				}
				break;
		}
		current_time = time(NULL);
		second = tlm - (current_time - start_time);
	}
	printf("\n时间到!本次限时训练结束.\n");
	printf("共做%d题,做对%d题,做错%d题,正确率%.2f%%.\n", total_num, true_num, false_num, (float)true_num/total_num*100);
	printf("做对一题平均用时 %.2f 秒，要继续加油，不断挑战自己哟!\n", (float)tlm/true_num);
	if(false_num != 0){
		printf("\n你做错了下面几道题,已加入错题本中,要多多复习哟!\n");
		mistake_read_and_copy(false_num);
		file = fopen("tmp.txt","w");				//清空tmp.txt
		fclose(file);
	}
}
