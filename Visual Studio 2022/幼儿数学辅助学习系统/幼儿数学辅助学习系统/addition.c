#include "Mathematic_assistance_systems_for_young_children.h"

//�ӷ�ѵ��
void addition(){
	int num, range, i, num_true = 0;
	time_t first, second;
	FILE *file;
	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("          С���ѣ���ӭ�����ӷ�ѵ����       \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("�����Ҫ��ս�������أ���");
	do{
		scanf("%d",&num);
		if(num <= 0){
			printf("Ҫ�������0����Ŷ!:");
		}
	} while(num <= 0);
	printf("Ҫ��ս�������ڵļӷ��أ�:");

   	//�ж���������ݷ�Χ�Ƿ�Ϸ�
	do{
		scanf("%d",&range);
		if(range <= 1){
			printf("Ҫ�������1����Ŷ!:");
		}
	} while(range <= 1);

	printf("\n�õ�!���μӷ�ѵ����%d��,���ֶ���%d����!\n", num, range);
	printf("\n׼��������,����Enter���ͼ�ʱ��ʼ��!\n");
	getchar();
	getchar();
	
	time(&first);
	
	for(i = 0;i < num;i++){
		if(give_one_addition(range)){
			num_true++;
		}
	}
	time(&second);
	printf("���μӷ�ѵ������,��%d��,����%d��,��ʱ%d��,�����!\n", num, num_true, (unsigned)difftime(second,first));

	if(num != num_true){
		printf("\n�����������漸����,�Ѽ�����Ȿ��,Ҫ��ิϰӴ!\n");
		mistake_read_and_copy(num-num_true);
		file = fopen("tmp.txt","w");				//���tmp.txt
		fclose(file);
	}
}

//����һ���ӷ���Ŀ���ж϶Դ�,������д��tmp.txt
BOOL give_one_addition(int range){ 					//rangeΪ��Χ
	int addend1,addend2,result,input;
	srand((unsigned)time(NULL));

	addend1 = rand() % (range - 1) + 1;			//���ɣ�1~��Χ-1�����������Ϊ��һ������
	addend2 = rand() % (range - addend1) + 1;		//���ɣ�1~����Χ-��һ�������������������Ϊ�ڶ�������
	result = addend1 + addend2;

    printf("%d+%d=", addend1, addend2);
	scanf("%d",&input);
	if(input == result){
		printf("�ش���ȷ!��������!\n\n");
		return TRUE;
	}else{
		printf("��ѽ,��С�Ĵ����,��ȷ����%d,Ҫϸ��Ӵ!\n\n",result);
		mistake_input_add(addend1, addend2, result);
		return FALSE;
	}
}



