// //加法的60s限时训练
// int xianshi() {
// 	int correctAnswers = 0;
// 	time_t startTime = time(NULL);
// 	time_t currentTime = startTime;
// 	time_t endTime = startTime + 60;
	
// 	int n;
// 	printf("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
// 	printf("请输入出题范围: ");
// 	scanf("%d",&n);
	
// 	int all=0;
// 	while (currentTime < endTime) {
// 		// 生成n以内的未知数
// 		int num1 = rand() % n + 1;
// 		int num2 = rand() % n + 1;
		
// 		printf("%d + %d =", num1, num2);
		
// 		int userAnswer;
// 		scanf("%d", &userAnswer);
		
// 		int correctAnswer = num1 + num2;
		
// 		currentTime = time(NULL);
		
// 		time_t remainingTime = endTime - currentTime;
		
// 		if(remainingTime<0)//记录时间，时间到则停止
// 		{
// 			break;
// 		}
		
// 		//比较用户答案
// 		if (userAnswer == correctAnswer) {
// 			printf("回答正确!\n");
// 			correctAnswers++;
// 			all++;
// 		} else {
// 			printf("回答错误!，正确答案是%d\n",correctAnswer);
// 			all++;
// 		}
		
		
// 		printf("剩余时间为: %ld 秒\n", remainingTime);//提示用户剩余时间
		
// 	}
// 	printf("时间到!\n");
// 	float a=all*1.00,b=correctAnswers*1.00;
// 	printf("您共计在60秒内回答了%d道题目，其中正确回答对了%d道题，您的正确率为%.2f\n", all,correctAnswers,b/a);
	
	
// 	return 0;
// }
