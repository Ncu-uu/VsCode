#include "Mathematic_assistance_systems_for_young_children.h"

//���ӷ�����д��tmp�ļ�
void mistake_input_add(int a,int b,int c){
	FILE *fp = NULL;
	
	fp = fopen("tmp.txt", "a");
	fprintf(fp,"%d+%d=%d\n",a,b,c);
	fclose(fp);
}

//����������д��tmp�ļ�
void mistake_input_sub(int a,int b,int c){
	FILE *fp = NULL;
	
	fp = fopen("tmp.txt", "a");
	fprintf(fp,"%d-%d=%d\n",a,b,c);
	fclose(fp);
}

//���˷�����д��tmp�ļ�
void mistake_input_mult(int a,int b,int c){
	FILE *fp = NULL;
	
	fp = fopen("tmp.txt", "a");
	fprintf(fp,"%d��%d=%d\n",a,b,c);
	fclose(fp);
}

//����������д��tmp�ļ�
void mistake_input_div(int a,int b,int c){
	FILE *fp = NULL;
	
	fp = fopen("tmp.txt", "a");
	fprintf(fp,"%d��%d=%d\n",a,b,c);
	fclose(fp);
}

//��tmp�ļ��ж�ȡ���������д����Ȿ
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
//��ȡmistakes.txt������
int get_num_of_mistakes(){
	int count = 0;
	FILE *fmistakes = NULL;
	char ch;
	fmistakes = fopen("mistakes.txt", "r");
	if (fmistakes == NULL) {
		printf("Failed to open mistakes.txt\n");
		return -1;
	}
	while ((ch = fgetc(fmistakes)) != EOF) {
		if (ch == '\n') {
			count++;
		}
	}
	fclose(fmistakes);
	return count;
}