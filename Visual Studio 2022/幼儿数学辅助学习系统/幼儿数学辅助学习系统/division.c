#include "Mathematic_assistance_systems_for_young_children.h"

//����ѵ��
void division(){
	int num, range, i, num_true = 0;
	time_t first, second;
	FILE *file;
	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("          С���ѣ���ӭ��������ѵ����       \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("�����Ҫ��ս�������أ���");
	do{
		scanf("%d",&num);
		if(num <= 0){
			printf("Ҫ�������0����Ŷ!:");
		}
	} while(num <= 0);
	printf("Ҫ��ս�������ڵĳ����أ�:");

	//�ж���������ݷ�Χ�Ƿ�Ϸ�
	do{
		scanf("%d",&range);
		if(range <= 4){
			printf("Ҫ�������4����Ŷ!:");
		}
	} while(range <= 4);

	printf("\n�õ�!���γ���ѵ����%d��,���ֶ���%d����!\n", num, range);
	printf("\n׼��������,����Enter���ͼ�ʱ��ʼ��!\n");
	getchar();
	getchar();
	
	time(&first);
	for(i = 0;i < num;i++){
		if(give_one_division(range)){
			num_true++;
		}
	}
	time(&second);
	printf("���γ���ѵ������,��%d��,����%d��,��ʱ%d��,�����!\n", num, num_true, (unsigned)difftime(second,first));

	if(num != num_true){
		printf("\n�����������漸����,�Ѽ�����Ȿ��,Ҫ��ิϰӴ!\n");
		mistake_read_and_copy(num-num_true);
		file = fopen("tmp.txt","w");				//���tmp.txt
		fclose(file);
	}
}

//����һ��������Ŀ���ж϶Դ�
BOOL give_one_division(int range){ 						//rangeΪ��Χ
	int dividend,divisor,result,input;
	srand((unsigned)time(NULL));
	divisor = (rand() % (range / 2 - 1 )) + 2;			//���ɣ�2~��Χ����2�����������Ϊ����
	do {	
		result = (rand() % (range - 1 )) + 2;			//���ɣ�2~��Χ�����������Ϊ���
	} while(result * divisor > range);					//�жϽ���Ƿ��ڷ�Χ��
	
	dividend = result * divisor;
			
	printf("%d��%d=", dividend, divisor);
	scanf("%d",&input);
	if(input == result){
		printf("�ش���ȷ!��������!\n\n");
		return TRUE;
	}else{
		printf("��ѽ,��С�Ĵ����,��ȷ����%d,Ҫϸ��Ӵ!\n\n",result);
		mistake_input_div(dividend, divisor, result);
		return FALSE;
	}
}



