#include "Mathematic_assistance_systems_for_young_children.h"

//主菜单
void run(){
	int choice;
	BOOL isRunning = TRUE;
	while(isRunning){
		printf("          主菜单\n");
		printf("          --------------------------------------------------\n");
		printf("          |                                                |\n");
		printf("          |         小朋友！欢迎进入数学练习系统           |\n");
		printf("          |      ***********************************       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      **|**      1.基 础 训 练      **|**       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      ***********************************       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      **|**      2.进 阶 训 练      **|**       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      ***********************************       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      **|**      0.退 出 系 统      **|**       |\n");
		printf("          |      **|**                         **|**       |\n");
		printf("          |      ***********************************       |\n");
		printf("          |                                                |\n");
		printf("          --------------------------------------------------\n");
		printf("          请输入你的选择：");

		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			basic_training();
			break;
		case 2:
			advanced_training();
			break;
		case 0:
			printf("感谢您的使用！下次再见咯！\n");
			isRunning = FALSE;
			break;
		default:
			break;
		}
	}
}
void basic_training(){
	int choice;
		printf("                   主界面>>基础训练\n");
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
		printf("                   *                                                                                      +\n");
		printf("                   +                                                                                      *\n");	
		printf("                   *                               欢迎来到数学辅助学习系统                               +\n");
		printf("                   +                                                                                      *\n");
		printf("                   *                               _______________________                                +\n");
		printf("                   +                               |                     |                                *\n");
		printf("                   *                               |     1、加法训练     |                                +\n");
		printf("                   +                               |_____________________|                                *\n");
		printf("                   *                                                                                      +\n");
		printf("                   +                               _______________________                                *\n");
		printf("                   *                               |                     |                                +\n");
		printf("                   +                               |     2、减法训练     |                                *\n");
		printf("                   *                               |_____________________|                                +\n");
		printf("                   +                                                                                      *\n");
		printf("                   *                               _______________________                                +\n");
		printf("                   +                               |                     |                                *\n");
		printf("                   *                               |     3、乘法训练     |                                +\n");
		printf("                   +                               |_____________________|                                *\n");
		printf("                   *                                                                                      +\n");	
		printf("                   +                               _______________________                                *\n");
		printf("                   *                               |                     |                                +\n");
		printf("                   +                               |     4、除法训练     |                                *\n");
		printf("                   *                               |_____________________|                                +\n");
		printf("                   +                                                                                      *\n");
		printf("                   *                               _______________________                                +\n");
		printf("                   +                               |                     |                                *\n");
		printf("                   *                               |   0、返回上级菜单   |                                +\n");
		printf("                   +                               |_____________________|                                *\n");	
		printf("                   *                                                                                      +\n");	
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");	
		printf("                   请输入您的需求：");
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
		case 0:
			printf("\n");
			run();
			break;
		default:
			break;
	}
}
void advanced_training(){
	int choice;
		
		printf("                   主界面>>进阶训练\n");
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
		printf("                   *                                                                                  +\n");
		printf("                   +                                                                                  *\n");	
		printf("                   *                             欢迎来到数学辅助学习系统                             +\n");
		printf("                   +                                                                                  *\n");
		printf("                   *                               ___________________                                +\n");
		printf("                   +                               |                 |                                *\n");
		printf("                   *                               |   1、综合训练   |                                +\n");
		printf("                   +                               |_________________|                                *\n");
		printf("                   *                                                                                  +\n");
		printf("                   +                               ____________________                               *\n");
		printf("                   *                               |                  |                               +\n");
		printf("                   +                               |   2、限时挑战    |                               *\n");
		printf("                   *                               |__________________|                               +\n");
		printf("                   +                                                                                  *\n");
		printf("                   *                                                                                  +\n");
		printf("                   +                               ____________________                               *\n");
		printf("                   *                               |                  |                               +\n");
		printf("                   +                               |   3、错题训练    |                               *\n");
		printf("                   *                               |__________________|                               +\n");
		printf("                   +                                                                                  *\n");
		printf("                   *                               ____________________                               +\n");
		printf("                   +                               |                  |                               *\n");
		printf("                   *                               | 0、返回上级菜单  |                               +\n");
		printf("                   +                               |__________________|                               *\n");
		printf("                   *                                                                                  +\n");
		printf("                   +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
		printf("                   请输入您的需求：");
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
	case 0:
		printf("\n");
		run();
		break;
	default:
		break;
	}

}
