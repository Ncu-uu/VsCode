#include "Mathematic_assistance_systems_for_young_children.h"

// 限时60s的综合训练
void mixed(){
	int num, range, i, num_true = 0, choice;
	time_t first, second;
	FILE *file;
	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("          小朋友，欢迎来到综合训练！       \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("你这次要挑战几道题呢？：");
	do{
		scanf("%d",&num);
		if(num <= 0){
			printf("要输入大于0的数哦!:");
		}
	} while(num <= 0);
	printf("要挑战多少以内的综合训练呢？:");

   	//判断输入的数据范围是否合法
	do{
		scanf("%d",&range);
		if(range < 100){
			printf("要输入至少100的数哦!:");
		}
	} while(range < 100);

	printf("\n好的!本次综合训练共%d题,数字都在%d以内!\n", num, range);
	printf("\n准备好了吗,按下Enter键就计时开始咯!\n");
	getchar();
	getchar();

	time(&first);

    for(i = 0;i < num;i++){
        // 生成1-4的随机数
        srand((unsigned)time(NULL));
        choice = rand() % 4 + 1;
        switch (choice){
            case 1:
                if(give_one_addition(range)){
                    num_true++;
                }
                break;
            case 2:
                if(give_one_subtraction(range)){
                    num_true++;
                }
                break;
            case 3:
                if(give_one_multiplication(range)){
                    num_true++;
                }
                break;
            case 4:
                if(give_one_division(range)){
                    num_true++;
                }
                break;
            default:
                break;
        }
    }	
	time(&second);
	printf("本次综合训练结束,共%d题,做对%d题,耗时%d秒,你真棒!\n", num, num_true, (unsigned)difftime(second,first));

	if(num != num_true){
		printf("\n你做错了下面几道题,已加入错题本中,要多多复习哟!\n");
		mistake_read_and_copy(num-num_true);
		file = fopen("tmp.txt","w");				//清空tmp.txt
		fclose(file);
	}
}