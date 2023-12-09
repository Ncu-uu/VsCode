#include "Mathematic_assistance_systems_for_young_children.h"

void mistakes() {
	int num, num_true = 0, i;
	char str[255];
	time_t first, second;
	FILE *ftmp = NULL;

	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("          小朋友，欢迎来到错题训练！       \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("输入本次错题训练的量：");
	scanf("%d", &num);
	printf("\n准备好了吗,按下Enter键就计时开始咯!\n");
	getchar();
	getchar();

	time(&first);
	for (i = 0; i < num; i++) {
		if (give_one_mistake(i)) {
			num_true++;
		}
	}
	time(&second);
	printf("本次错题训练结束，共%d题，做对%d题，耗时%d秒\n", num, num_true, (unsigned)difftime(second, first));
	if (num != num_true) {
		printf("接下来显示本次训练的错题\n");
		ftmp = fopen("tmp.txt", "r");
		for (i = 1; i <= num - num_true; i++) {
			fgets(str, 255, ftmp);
			printf("%d:%s", i, str);
		}
		fclose(ftmp);
		ftmp = fopen("tmp.txt", "w"); //清空tmp.txt
		fclose(ftmp);
	}
}

BOOL give_one_mistake(int num) {
	int whichLine[255], currentIndex, input, result = 0;
	int i = 0, j = 0, x;
	char str[255] = {'0'}, out[255] = {'0'}, answer[255] = {'0'};
	BOOL flag;
	FILE *fmistakes = NULL;
	FILE *ftmp = NULL;
	int num_of_mistakes = get_num_of_mistakes();
	srand((unsigned)time(NULL));
	do{
		flag=TRUE;
		whichLine[num] = rand() % num_of_mistakes + 1;
		for(x=0;x<num;x++){
			if(whichLine[num]==whichLine[x]){
				flag=FALSE;
				break;
			}
		}
	}while(!flag);
	
	fmistakes = fopen("mistakes.txt", "r");
	for (currentIndex = 1; currentIndex <= whichLine[num]; currentIndex++) {
		fgets(str, 255, fmistakes);
	}
	do {
		out[i] = str[i];
	} while (str[i++] != '=');

	while (str[i] != '\n') {
		answer[j++] = str[i];
		i++;
	}
	for (i = 0; i < j; i++) {
		result = result * 10 + answer[i] - 48;
	}
	printf("%s", out);
	scanf("%d", &input);
	if (input == result) {
		return TRUE;
	} else {
		printf("错误，正确答案为：%d\n", result);
		ftmp = fopen("tmp.txt", "a");
		fprintf(ftmp, "%s%d\n", out, result);
		fclose(ftmp);
		return FALSE;
	}
}