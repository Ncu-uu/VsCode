// #include "Mathematic_assistance_systems_for_young_children.h"

// // 混合出题
// void mixed(){
// 	int num,num_true,range[4];
// 	int i,j;
// 	time_t first,second;
// 	FILE *file;
	
// 	printf("输入本次综合训练的题量：");
// 	scanf("%d",&num);
	
// 	printf("输入本次综合训练中加法的数据范围：");
// 	do{
// 		scanf("%d",&range[0]);
// 		if(range[0]<=2){
// 			printf("请输入大于2的自然数");
// 		}
// 	}while(range[0]<=2);
	
// 	printf("输入本次综合训练中减法的数据范围：");
// 	do{
// 		scanf("%d",&range[1]);
// 		if(range[1]<=2){
// 			printf("请输入大于2的自然数");
// 		}
// 	}while(range[1]<=2);
	
// 	printf("输入本次综合训练中乘法的数据范围：");
// 	do{
// 		scanf("%d",&range[2]);
// 		if(range[2]<=2){
// 			printf("请输入大于2的自然数");
// 		}
// 	}while(range[2]<=2);
	
// 	printf("输入本次综合训练中除法的数据范围：");
// 	do{
// 		scanf("%d",&range[3]);
// 		if(range[3]<=2){
// 			printf("请输入大于2的自然数");
// 		}
// 	}while(range[3]<=2);
// 	printf("本次除法训练共%d题\n现在开始\n",num);
	
// 	srand((unsigned)time(NULL));
// 	time(&first);
// 	for(i=0;i<num;i++){
// 		j=rand()%4;
// 		switch (j) {
// 		case 0:
// 			if(give_one_addition(range[0])){
// 				num_true++;
// 			}
// 			break;
// 		case 1:
// 			if(give_one_subtraction(range[1])){
// 				num_true++;
// 			}
// 			break;
// 		case 2:
// 			if(give_one_multiplication(range[2])){
// 				num_true++;
// 			}
// 			break;
// 		case 3:
// 			if(give_one_division(range[3])){
// 				num_true++;
// 			}
// 			break;
// 		}
// 	}
// 	time(&second);
// 	printf("本次综合训练结束，共%d题，做对%d题，耗时%d秒\n",num,num_true,(unsigned)difftime(second,first));
// 	if(num!=num_true){
// 		printf("接下来显示本次训练的错题\n");
// 		mistake_read_and_copy(num-num_true);
// 		file = fopen("tmp.txt","w");//清空tmp.txt
// 		fclose(file);
// 	}
// }
