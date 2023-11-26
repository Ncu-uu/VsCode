#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int second = 60;
	time_t start_time=time(NULL);
	while(second > 0){
		// printf("倒计时：%d\n",second);
		time_t current_time=time(NULL);
		second = 60 - (current_time - start_time);

	}
	printf("时间到！\n");
	return 0;
}