#include "Mathematic_assistance_systems_for_young_children.h"

// ��ʱ60s���ۺ�ѵ��
void mixed(){
	int num, range, i, num_true = 0, choice;
	time_t first, second;
	FILE *file;
	printf("\n\n+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("          С���ѣ���ӭ�����ۺ�ѵ����       \n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n\n");
	printf("�����Ҫ��ս�������أ���");
	do{
		scanf("%d",&num);
		if(num <= 0){
			printf("Ҫ�������0����Ŷ!:");
		}
	} while(num <= 0);
	printf("Ҫ��ս�������ڵ��ۺ�ѵ���أ�:");

   	//�ж���������ݷ�Χ�Ƿ�Ϸ�
	do{
		scanf("%d",&range);
		if(range < 100){
			printf("Ҫ��������100����Ŷ!:");
		}
	} while(range < 100);

	printf("\n�õ�!�����ۺ�ѵ����%d��,���ֶ���%d����!\n", num, range);
	printf("\n׼��������,����Enter���ͼ�ʱ��ʼ��!\n");
	getchar();
	getchar();

	time(&first);

    for(i = 0;i < num;i++){
        // ����1-4�������
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
	printf("�����ۺ�ѵ������,��%d��,����%d��,��ʱ%d��,�����!\n", num, num_true, (unsigned)difftime(second,first));

	if(num != num_true){
		printf("\n�����������漸����,�Ѽ�����Ȿ��,Ҫ��ิϰӴ!\n");
		mistake_read_and_copy(num-num_true);
		file = fopen("tmp.txt","w");				//���tmp.txt
		fclose(file);
	}
}