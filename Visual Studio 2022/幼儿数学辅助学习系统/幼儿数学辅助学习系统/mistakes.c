#include "Mathematic_assistance_systems_for_young_children.h"

void mistakes() {
	int num, num_true = 0, i;
	char str[255];
	time_t first, second;
	FILE *ftmp = NULL;

	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("          С���ѣ���ӭ��������ѵ����       \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("���뱾�δ���ѵ��������");
	scanf("%d", &num);
	printf("\n׼��������,����Enter���ͼ�ʱ��ʼ��!\n");
	getchar();
	getchar();

	time(&first);
	for (i = 0; i < num; i++) {
		if (give_one_mistake(i)) {
			num_true++;
		}
	}
	time(&second);
	printf("���δ���ѵ����������%d�⣬����%d�⣬��ʱ%d��\n", num, num_true, (unsigned)difftime(second, first));
	if (num != num_true) {
		printf("��������ʾ����ѵ���Ĵ���\n");
		ftmp = fopen("tmp.txt", "r");
		for (i = 1; i <= num - num_true; i++) {
			fgets(str, 255, ftmp);
			printf("%d:%s", i, str);
		}
		fclose(ftmp);
		ftmp = fopen("tmp.txt", "w"); //���tmp.txt
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
		printf("������ȷ��Ϊ��%d\n", result);
		ftmp = fopen("tmp.txt", "a");
		fprintf(ftmp, "%s%d\n", out, result);
		fclose(ftmp);
		return FALSE;
	}
}