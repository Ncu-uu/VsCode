#include "Mathematic_assistance_systems_for_young_children.h"

//���˵�
void run(){
	int choice;
	BOOL isRunning = TRUE;
	while(isRunning){
		printf("          ���˵�\n");
		printf("          --------------------------------------------------\n");
		printf("          |                                                |\n");
		printf("          |         С���ѣ���ӭ������ѧ��ϰϵͳ           |\n");
		printf("          |      ***********************************       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      **|**      1.�� �� ѵ ��      **|**       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      ***********************************       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      **|**      2.�� �� ѵ ��      **|**       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      ***********************************       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      **|**      0.�� �� ϵ ͳ      **|**       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      ***********************************       |\n");
		printf("          |                                                |\n");
		printf("          --------------------------------------------------\n");
		printf("          ���������ѡ��");

		scanf("%d",&choice);
		switch (choice)
		{
			case 0:
				printf("��л����ʹ�ã��´��ټ�����\n");
				isRunning = FALSE;
				break;
			case 1:
				basic_training();
				break;
			case 2:
				advanced_training();
				break;
			default:
				break;
		}
	}
}
void basic_training(){
	int choice;
		printf("\n");
		printf("                   ������>>����ѵ��\n");
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
		printf("                   *                                                                                      +\n");
		printf("                   +                                                                                      *\n");	
		printf("                   *                               ��ӭ������ѧ����ѧϰϵͳ                               +\n");
		printf("                   +                                                                                      *\n");
		printf("                   *                               _______________________                                +\n");
		printf("                   +                               |                     |                                *\n");
		printf("                   *                               |     1���ӷ�ѵ��     |                                +\n");
		printf("                   +                               |_____________________|                                *\n");
		printf("                   *                                                                                      +\n");
		printf("                   +                               _______________________                                *\n");
		printf("                   *                               |                     |                                +\n");
		printf("                   +                               |     2������ѵ��     |                                *\n");
		printf("                   *                               |_____________________|                                +\n");
		printf("                   +                                                                                      *\n");
		printf("                   *                               _______________________                                +\n");
		printf("                   +                               |                     |                                *\n");
		printf("                   *                               |     3���˷�ѵ��     |                                +\n");
		printf("                   +                               |_____________________|                                *\n");
		printf("                   *                                                                                      +\n");	
		printf("                   +                               _______________________                                *\n");
		printf("                   *                               |                     |                                +\n");
		printf("                   +                               |     4������ѵ��     |                                *\n");
		printf("                   *                               |_____________________|                                +\n");
		printf("                   +                                                                                      *\n");
		printf("                   *                               _______________________                                +\n");
		printf("                   +                               |                     |                                *\n");
		printf("                   *                               |   0�������ϼ��˵�   |                                +\n");
		printf("                   +                               |_____________________|                                *\n");	
		printf("                   *                                                                                      +\n");	
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");	
		printf("                   ��������������");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			addition();
			break;
		case 2:
			subtraction();
			break;
		case 3:
			multiplication();
			break;
		case 4:
			division();
			break;
		default:
			break;
	}
}
void advanced_training(){
	int choice;
		printf("\n");
		printf("                   ������>>����ѵ��\n");
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
		printf("                   *                                                                                  +\n");
		printf("                   +                                                                                  *\n");	
		printf("                   *                             ��ӭ������ѧ����ѧϰϵͳ                             +\n");
		printf("                   +                                                                                  *\n");
		printf("                   *                               ___________________                                +\n");
		printf("                   +                               |                 |                                *\n");
		printf("                   *                               |   1���ۺ�ѵ��   |                                +\n");
		printf("                   +                               |_________________|                                *\n");
		printf("                   *                                                                                  +\n");
		printf("                   +                               ____________________                               *\n");
		printf("                   *                               |                  |                               +\n");
		printf("                   +                               |   2����ʱ��ս    |                               *\n");
		printf("                   *                               |__________________|                               +\n");
		printf("                   *                                                                                  +\n");
		printf("                   +                               ____________________                               *\n");
		printf("                   *                               |                  |                               +\n");
		printf("                   +                               |   3������ѵ��    |                               *\n");
		printf("                   *                               |__________________|                               +\n");
		printf("                   +                                                                                  *\n");
		printf("                   *                               ____________________                               +\n");
		printf("                   +                               |                  |                               *\n");
		printf("                   *                               | 0�������ϼ��˵�  |                               +\n");
		printf("                   +                               |__________________|                               *\n");
		printf("                   *                                                                                  +\n");
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
		printf("                   ��������������");
		scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			mixed();
			break;
		case 2:
			time_limited();
			break;
		case 3:
			mistakes();
			break;
		default:
			break;
	}

}
