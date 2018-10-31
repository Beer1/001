#include"game.h"
void menu()
{
printf("********************\n");
printf("*****1. play *******\n");
printf("*****0. exit *******\n");
printf("********************\n");
}

void game()
{
	char board[ROW][COL] = {0};
	char ret = 0;
	Initb(board, ROW, COL);//��ʼ������
	Showb(board, ROW, COL);//��ӡ����
	while(1)
	{
		P1_Move(board, ROW, COL);//�������
		ret = Is_Win(board, ROW, COL);
		if(ret != ' ')
			break;
		Showb(board, ROW, COL);
		Computer_Move(board, ROW, COL);//��������
		ret = Is_Win(board, ROW, COL);
		if(ret != ' ')
			break;
		//system("cls");
		Showb(board, ROW, COL);

	}
	if(ret == 'X')
		printf("You win!!!\n");
	 else if(ret == '0')
		printf("You lost!!\n");
	 else if(ret == 'Q')
		printf("It ends in a draw!!!\n");
	Showb(board, ROW, COL);

}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
	menu();//��Ϸ�˵�
	printf("Please select��");
	scanf_s("%d", &input);
	switch(input)
	{
	case 1:
		game();
		break;
	case 0:
		printf("Exit the game����");
		break;
	default:
		printf("There is a error ,please select again ����\n");
		break;
	}
	}while(input);
	system("pause");
	return 0;
}