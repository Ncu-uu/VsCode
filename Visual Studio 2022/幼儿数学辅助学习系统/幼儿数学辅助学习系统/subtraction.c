#include "Mathematic_assistance_systems_for_young_children.h"

//����ѵ��
void subtraction(){
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
	printf("Ҫ��ս�������ڵļ����أ�:");

    //�ж���������ݷ�Χ�Ƿ�Ϸ�
	do{
		scanf("%d",&range);
		if(range <= 1){
			printf("Ҫ�������1����Ŷ!:");
		}
	} while(range <= 1);

	printf("\n�õ�!���μ���ѵ����%d��,���ֶ���%d����!\n", num, range);
	printf("\n׼��������,����Enter���ͼ�ʱ��ʼ��!\n");
	getchar();
	getchar();
	
	
	time(&first);
	for(i = 0;i < num;i++){
		if(give_one_subtraction(range)){
			num_true++;
		}
	}
	time(&second);
	printf("���μ���ѵ������,��%d��,����%d��,��ʱ%d��,�����!\n", num, num_true, (unsigned)difftime(second,first));

	if(num != num_true){
		printf("\n�����������漸����,�Ѽ�����Ȿ��,Ҫ��ิϰӴ!\n");
		mistake_read_and_copy(num-num_true);
		file = fopen("tmp.txt","w");				//���tmp.txt
		fclose(file);
	}
}

//����һ��������Ŀ���ж϶Դ�
BOOL give_one_subtraction(int range){ 					//rangeΪ��Χ
	int minuend,subtrahend,result,input;
	
	srand((unsigned)time(NULL));
    minuend = rand() % range + 1;			//���ɣ�1~��Χ�����������Ϊ������
    subtrahend = rand() % minuend + 1;		//���ɣ�1~�����������������Ϊ����
    result = minuend - subtrahend;
    printf("%d-%d=", minuend, subtrahend);
	scanf("%d",&input);
	if(input == result){
		printf("�ش���ȷ!��������!\n\n");
		return TRUE;
	}else{
		printf("��ѽ,��С�Ĵ����,��ȷ����%d,Ҫϸ��Ӵ!\n\n",result);
		mistake_input_sub(minuend, subtrahend, result);
		return FALSE;
	}
}



