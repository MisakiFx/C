#include "Panel.h"
HANDLE std_win_handle = 0;
Panel *gamePanel = NULL;
Stone *stone = NULL;
Person* person[2] = { NULL };
LONGLONG count;
int score = 0;
int speed = 10;
/**
��ʼ����Ϸ��������
*/
void gamePanelInit()
{
	if (gamePanel == NULL)
	{
		gamePanel = (Panel*)malloc(sizeof(Panel));
		gamePanel->x = 10;
		gamePanel->y = 2;
		gamePanel->high = 25;
		gamePanel->width = 80;
		gamePanel->a = '*';
	}
}
/**
��ʼ����������
*/
void personInit()
{
	int flag = 0;
	for (int i = 0; i < 2; i++)
	{
		if (person[i] == NULL)
		{
			person[i] = (Person*)malloc(sizeof(Person));
			person[i]->x = 0;
			flag = 1;
		}
	}
	if (flag)
	{
		person[0]->y = 8;
		person[1]->y = 14;
	}
}
/**
���þ��
*/
void setHandle()
{
	if (std_win_handle == 0)
	{
		std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}
}
/**
���ñ���
*/
void setTitle()
{
	SetConsoleTitle(TEXT("Brave_man"));
}
/**
���ô��ڴ�С
*/
void setWinSize(int width, int high)
{
	SMALL_RECT rect = { 0,0,width - 1, high - 1 };//����SMALL_RECT�ṹ���ʾ���������С�����-�յ㣩
	COORD coord = { width,high };//����COORD�ṹ���ʾ�������������꣨�ڿ���̨�������ӡλ�ã�
	setHandle();//�õ���׼�������������ڶ����ȫ�־����
	SetConsoleScreenBufferSize(std_win_handle, coord);//���ú������û�����λ��
	SetConsoleWindowInfo(std_win_handle, TRUE, &rect);//���ú������ô����С
}
/**
���ù��λ��
*/
void setCursorPosition(int x, int y)
{
	setHandle();
	COORD pos = { x, y };
	SetConsoleCursorPosition(std_win_handle, pos);
}
/**
���ƺ���
*/
void drawXLine(int x, int y, int len, char a)
{
	setCursorPosition(x, y);
	for (int i = 0; i < len; i++)
	{
		printf("%c", a);
	}
}
/**
��������
*/
void drawYLine(int x, int y, int len, char a)
{
	for (int i = 0; i < len; i++)
	{
		setCursorPosition(x, y++);
		printf("%c", a);
	}
}
/**
���ƽ���
*/
void drawPanel(int x, int y, int width, int high, char a)
{
	setColor(0xF4);
	drawXLine(x, y, width, a);
	drawXLine(x, y + high, width, a);
	drawYLine(x, y, high, a);
	drawYLine(x + width, y, high + 1, a);
}
/**
���ϰ��ﺯ��
*/
void drawStone()
{
	Stone* p = stone;
	if (p == NULL)
	{
		return;
	}
	else
	{
		while (p != NULL)
		{
			setColor(p->stonedata.bjcolor << 4 | p->stonedata.qjcolor);
			for (int i = 0; i < 6; i++)
			{
				setCursorPosition(p->stonedata.x + gamePanel->x + 1, 6 * (p->stonedata.y / 6) + gamePanel->y + 1 + i);
				printf("��");
			}
			p = p->next;
		}
	}
}
/**
���ع�꺯��
*/
void disableCurrsole()
{
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(std_win_handle, &cursor_info);
}
/**
����
*/
void clean()
{
	setColor(0xFF);
	for (int i = 0; i < gamePanel->high - 1; i++)
	{
		for (int j = 0; j < gamePanel->width - 1; j++)
		{
			if ((i == person[0]->y && j == person[0]->x) || (i == (person[0]->y + 1) && j == person[0]->x) || (i == person[0]->y && j == (person[0]->x + 1)) || (i == (person[0]->y + 1) && j == (person[0]->x + 1)))
			{
				continue;
			}
			if ((i == person[0]->y && j == person[0]->x+ 2) || (i == (person[0]->y + 1) && j == person[0]->x+2) || (i == person[0]->y && j == (person[0]->x + 3)) || (i == (person[0]->y + 1) && j == (person[0]->x + 3)))
			{
				continue;
			}
			if ((i == person[1]->y && j == person[1]->x) || (i == (person[1]->y + 1) && j == person[1]->x) || (i == person[1]->y && j == (person[1]->x + 1)) || (i == (person[1]->y + 1) && j == (person[1]->x + 1)))
			{
				continue;
			}
			if ((i == person[1]->y && j == person[1]->x + 2) || (i == (person[1]->y + 1) && j == person[1]->x + 2) || (i == person[1]->y && j == (person[1]->x + 3)) || (i == (person[1]->y + 1) && j == (person[1]->x + 3)))
			{
				continue;
			}
			setCursorPosition(gamePanel->x + 1 + j, gamePanel->y + 1 + i);
			printf(" ");
		}
	}
}
/**
�ϰ�����ƺ���
*/
void stoneControl()
{
	Stone* p;
	Stone* q = stone;
	srand(time(NULL));
	clean();
	while (q != NULL)
	{
		q->stonedata.x -= 11;
		q = q->next;
	}
	q = stone;
	//ɾ��ʧЧ�Ľڵ�
	while (q != NULL)
	{
		if (q->stonedata.x < 0)
		{
			stone = q->next;
			free(q);
			q = stone;
		}
		else
			q = q->next;
	}
	if (count %60 == 0)
	{
		for (int i = 0; i < 2; i++)//����2���½ڵ���������β��
		{
			p = (Stone*)malloc(sizeof(Stone));
			memset(p, 0, sizeof(Stone));
			p->stonedata.bjcolor = 0;
			p->stonedata.qjcolor = rand() % 0xF;
			p->stonedata.x = gamePanel->width - 3;
			p->stonedata.y = rand() % 12 + i * 12;
			if (p->stonedata.y >= 0 && p->stonedata.y < 6)
			{
				p->stonedata.y = 2;
			}
			if (p->stonedata.y >= 6 && p->stonedata.y < 12)
			{
				p->stonedata.y = 8;
			}
			if (p->stonedata.y >= 12 && p->stonedata.y < 18)
			{
				p->stonedata.y = 14;
			}
			if (p->stonedata.y >= 18 && p->stonedata.y < 24)
			{
				p->stonedata.y = 20;
			}
			p->next = NULL;
			if (stone == NULL)
			{
				stone = p;
			}
			else
			{
				Stone* t = stone;
				while (t->next != NULL)//�ҵ�β�ڵ�
				{
					t = t->next;
				}
				t->next = p;
			}
		}
	}
}
/**
��������
*/
void drawPerson()
{
	setColor(0xF9);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			setCursorPosition(person[i]->x + gamePanel->x + 1, person[i]->y + gamePanel->y + 1 + j);
			for (int k = 0; k < 2; k++)
			{
				printf("��");
			}
		}
	}
}
/**
������Ϸ
*/
void drawGame()
{
	personInit();
	gamePanelInit();
	drawPanel(gamePanel->x, gamePanel->y, gamePanel->width, gamePanel->high, gamePanel->a);
	if (count % 30 == 0)
	{
		stoneControl();
		drawStone();
	}
	drawPerson();
	if (count != 0 && count % 500 == 0 && speed > 0)
	{
		speed--;
	}
	messagePrint();
	Sleep(speed);
}
/**
����������ɫ
*/
void setColor(int color)
{
	setHandle();//�õ����
	SetConsoleTextAttribute(std_win_handle, color);
}
/**
����ִ�к���
*/
void dead()
{
	/*PlaySound(TEXT("Music\\GameOver.wav"),
		NULL, SND_FILENAME | SND_ASYNC);*/
	setCursorPosition(50, 12);
	setColor(0xF4);
	printf("Game Over!!");
	setCursorPosition(50, 13);
	printf("���س����أ�");
	while (char a = _getch() != 13);
	setColor(0x00);
	setCursorPosition(100, 12);
	printf("scaore:%3d", score);
	setCursorPosition(100, 13);
	printf("speed: %3d ", 10 - speed);
	/*PlaySound(TEXT("Music\\MenuBGM.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/
	drawPanelBackGround();
	Stone* p = stone;
	Stone* t;
	if (p != NULL)
	{
		while (p != NULL)
		{
			t = p;
			p = p->next;
			free(t);
		}
	}
	stone = NULL;
	for (int i = 0; i < 1; i++)
	{
		if (person[i] != NULL)
		{
			free(person[i]);
		}
		person[i] = NULL;
	}
	score = 0;
	speed = 10;
}
/**
�ж��Ƿ�����
*/
int isDead()
{
	Stone* p = stone;
	while (p != NULL)
	{
		if ((p->stonedata.x == person[0]->x && p->stonedata.y == person[0]->y) || (p->stonedata.x == person[1]->x && p->stonedata.y == person[1]->y))
		{
			dead();
			return 1;
		}
		else
		p = p->next;
	}
	if (p == NULL)
	{
		if (count % 30 == 0)
		{
			if (stone != NULL && person[0] != NULL && person[1] != NULL)
			{
				if (person[0]->x == stone->stonedata.x)
				{
					score++;
				}
			}
		}
		return 0;
	}
	return 0;
}
/**
��Ϣ��ӡ����
*/
void messagePrint()
{
	setColor(0xF5);
	setCursorPosition(100,12);
	printf("scaore:%3d", score);
	setCursorPosition(100, 13);
	printf("speed: %3d", 10 - speed);
}
void caiDan()
{
	drawPanelBackGround();
	/*PlaySound(TEXT("Music\\caidan.wav"),
		NULL, SND_FILENAME | SND_ASYNC);*/
	setColor(0xF4);
	setCursorPosition(45, 13);
	printf("�Ų�������������");
	setCursorPosition(45, 15);
	printf("��л������棡");
	while (char a = _getch() != 13);
}
/**
��Ϸ˵������
*/
void gameInstruction()
{
	int caidan = 0;
	char a = 0;
	drawPanelBackGround();
	setColor(0xF5);
	setCursorPosition(37, 10);
	printf("������ָ�����ɴ��ԣ�");
	setCursorPosition(25, 13);
	printf("ʹ��'��'��'w'��'��'��'s'�ֱ��������С�˶�ܷ������ϰ��");
	setCursorPosition(35, 16);
	printf("������һ��ȱ�˭�ķָ��߰ɣ�");
	setCursorPosition(70, 22);
	setColor(0xFD);
	printf("���س����أ�");
	while (a != 13) 
	{
		a = _getch();
		while(a == '1')
		{
			caidan++;
			a = _getch();
			if (caidan >= 10)
			{
				caiDan();
				/*PlaySound(TEXT("Music\\MenuBGM.wav"),
					NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/
				break;
			}
		}
		if (caidan >= 10)
		{
			break;
		}
	}
	drawPanelBackGround();
}
