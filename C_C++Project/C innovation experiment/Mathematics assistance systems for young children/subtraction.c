// #include "Mathematic_assistance_systems_for_young_children.h"

// //减法训练
// void subtraction(){
// 	int num, range, i, num_true = 0;
// 	time_t first, second;
// 	FILE *file;
// 	printf("小朋友，欢迎来到减法训练！\n\n");
// 	printf("你这次要挑战几道题呢？：");
// 	scanf("%d",&num);
// 	printf("要挑战多少以内的减法呢？:");
//     scanf("%d",&range);

// 	printf("\n好的！本次减法训练共%d题，数字都在%d以内！\n", num, range);
// 	printf("\n准备好了吗，按下Enter键就计时开始咯！\n");
// 	getchar();
// 	getchar();
	
// 	srand((unsigned)time(NULL));
// 	time(&first);
// 	for(i = 0;i < num;i++){
// 		if(give_one_addition(range)){
// 			num_true++;
// 		}
// 	}
// 	time(&second);
// 	printf("本次减法训练结束，共%d题，做对%d题，耗时%d秒，你真棒！\n", num, num_true, (unsigned)difftime(second,first));

// 	if(num != num_true){
// 		printf("\n你做错了下面几道题，已加入错题本中，要多多复习哟！\n");
// 		mistake_read_and_copy(num-num_true);
// 		file = fopen("tmp.txt","w");				//清空tmp.txt
// 		fclose(file);
// 	}
// }

// //生成一个减法题目并判断对错
// BOOL give_one_addition(int range){ 					//range为范围
// 	int addend1,addend2,result,input;

//     addend1 = rand() % range + 1;		//生成（1~范围）的随机数作为第一个加数
// 	do {
// 		addend2 = rand() % range + 1;		//生成（1~范围）的随机数作为第二个加数
//         result = addend1 + addend2;
// 	} while(result > range);
	
//     printf("%d+%d=", addend1, addend2);
// 	scanf("%d",&input);
// 	if(input == result){
// 		printf("回答正确！继续加油！\n\n");
// 		return TRUE;
// 	}else{
// 		printf("哎呀，不小心答错了，正确答案是%d，要细心哟！\n\n",result);
// 		mistake_input_add(addend1, addend2, result);
// 		return FALSE;
// 	}
// }



