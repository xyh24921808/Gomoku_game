#include"game.h"


void Menu()
{
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("***1.play***********************0.exit***\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
}

int main(void)
{
	int input=0;
	do
	{
		Menu();
		printf("pls chose:>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("exit game\n");
				break;
			defuatl:
				printf("error try again\n");
				break;
		}
	}while(input);
	return 0;
}
