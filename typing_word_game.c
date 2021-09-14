#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <setjmp.h>
void play_game();
struct words
{
	char word[20];
};
int main(int argc, char* argv[])
{
	int choice = 0;	
	while(choice == 0)
	{
		printf("\n Hello welcome to typing speed game\n");
		printf("\n1: Play Game\n");
		printf("2: Exit game\n");
		printf("Please Enter in choice of number: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				play_game();
				break;
			case 2:
				choice = 1;
				break;
		}	
	}
	return 0;
}
void play_game()
{
	struct words game[9] ={ {"The"},{"quick"},{"brown"},{"fox"},{"jumps"},{"over"},{"the"},{"lazy"},{"dog"} };
	srand(time(0));
	int count = 1;
	jmp_buf env,try,exit;
	int words_used[9];
	int used = 0;
	int track = 0;
	char tmp[20];
	for(int loop = 0;loop < 9;loop++)
	{
		words_used[loop] = 99;
	}
	struct timeval start, end;
	gettimeofday(&start,NULL);
	setjmp(env);
	while(count <= 9)
	{
		int value = rand() % 9;
		if(value == 9) {value = 0;}
		for(int loop = 0;loop < 9;loop++)
		{
			if(value == words_used[loop])
			{
				longjmp(env,46);
			}
		}
		setjmp(try);
		printf("Word #%d is ",count);
		printf("%s:\n",game[value].word);
		scanf("%s",tmp);
		if(strcmp(tmp,game[value].word) != 0)
		{
			longjmp(try,62);
		}
		words_used[track] = value;
		track++;
		count++;
	}
	gettimeofday(&end,NULL);
	int seconds = end.tv_sec - start.tv_sec;
	int microseconds = end.tv_usec - start.tv_usec;
	printf("Your timne is : %d seconds %d useconds ",seconds,microseconds);
}

