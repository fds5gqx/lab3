#include <stdio.h>
#include <time.h>
#include <string.h>


int main()
{
	int check = 0;
	float gap;
	time_t startTime=0, endTime=0;
	char string[100];
	char question[100] = "I want to play LostArk";

	printf("start check\n");
	printf("%s\n",question);
	time(&startTime);
	gets(string);

	
	printf("check over\n");
	time(&endTime);
	printf("text length = %d\n", strlen(string));
	
	int i = 0;
	for(i=0; i<strlen(string); i++){
		if(question[i] != string[i])
			check++;
	}

	gap=(float)(endTime-startTime);

	printf("time : %fseconds \n", gap);
	printf("time per length : %f\n",strlen(string)/gap);
	printf("wrong char : %d\n",check);

	return 0;
}
