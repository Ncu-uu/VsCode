#include "Mathematic_assistance_systems_for_young_children.h"

// ��ʱ���ۺ�ѵ��
void time_limited(){
	int tlm, range, num, second = 1, total_num = 0, true_num = 0, false_num = 0;
	time_t start_time, current_time;
	FILE *file;

	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("         С���ѣ���ӭ������ʱ��ս��         \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("Ҫ�����������ڵ���ʱ��ս�أ���");
	do{
		scanf("%d",&tlm);
		if(tlm < 10){
			printf("Ҫ��������Ϊ10����Ŷ!:");
		}
	} while(tlm < 10);

	printf("�����뱾��ѵ�������ַ�Χ��");
	do{
		scanf("%d",&range);
		if(range < 100){
			printf("Ҫ��������Ϊ100����Ŷ!:");
		}
	} while(range < 100);

	printf("\n�õ�!������ʱ��ս��%d��,���ֶ���%d����!\n", tlm, range);
	printf("\n׼��������,����Enter���ͼ�ʱ��ʼ��!\n");
	getchar();
	getchar();
	
	// ����ʱ60s
	start_time=time(NULL);
	while(second > 0){
		// ����1-4�������
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
	printf("\nʱ�䵽!������ʱѵ������.\n");
	printf("����%d��,����%d��,����%d��,��ȷ��%.2f%%.\n", total_num, true_num, false_num, (float)true_num/total_num*100);
	printf("����һ��ƽ����ʱ %.2f �룬Ҫ�������ͣ�������ս�Լ�Ӵ!\n", (float)tlm/true_num);
	if(false_num != 0){
		printf("\n�����������漸����,�Ѽ�����Ȿ��,Ҫ��ิϰӴ!\n");
		mistake_read_and_copy(false_num);
		file = fopen("tmp.txt","w");				//���tmp.txt
		fclose(file);
	}
}
