#include "Key.h"
extern Person* person[2];
extern Panel* gamePanel;
extern MenuChoice* menuChoice[3];
extern Panel* menuPanel;
extern int isOver;
Key* personKey = NULL;
Key* menuKey = NULL;
//const char* music[] = {
//	{"Music\\GameBGM1.wav"},
//	{"Music\\GameBGM2.wav"},
//	{"Music\\GameBGM3.wav"}
//};
/**
找到当前选项
*/
int findCurChoice()
{
	int index = 0;
	for (index = 0; index < 3; index++)
	{
		if (menuChoice[index] == NULL)
		{
			continue;
		}
		if (menuChoice[index]->bjColor == 0x9)
		{
			return index;
			break;
		}
	}
}
/**
菜单方向上键
*/
void menuKey_up(char a)
{
	int index = findCurChoice();
	menuChoice[index]->bjColor = 0xF;
	if (index == 0)
	{
		index = 2;
	}
	else
	{
		index -= 1;
	}
	menuChoice[index]->bjColor = 0x9;
}
/**
菜单方向下键
*/
void menuKey_down(char a)
{
	int index = findCurChoice();
	menuChoice[index]->bjColor = 0xF;
	if (index == 2)
	{
		index = 0;
	}
	else
	{
		index += 1;
	}
	menuChoice[index]->bjColor = 0x9;
}
/**
菜单方向回车键
*/
void menuKey_enter(char a)
{
	srand(time(NULL));
	int index = findCurChoice();
	int index2;
	switch (index)
	{
		case 0:
			/*index2 = rand() % 3;
			PlaySound(music[index2],
				NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/
			gameStart();
			isOver = 1;
			break;
		case 1:
			gameInstruction();
			isOver = 1;
			break;
		case 2:
			isOver = 0;
	}
}
/**
菜单按键初始化
*/
void menuKeyInit()
{
	if (menuKey == NULL)
	{
		menuKey = (Key*)malloc(sizeof(Key));
		memset(menuKey, 0, sizeof(Key));
		menuKey->up = menuKey_up;
		menuKey->down = menuKey_down;
		menuKey->enter = menuKey_enter;

	}
}
/**
游戏控制上方向键
*/
void personKey_up(char a)
{

	if (person == NULL || person[0] == NULL)
	{
		return;
	}
	else
	{
		if (person[0]->y == 8)
		{
			setColor(0xFF);
				for (int j = 0; j < 2; j++)
				{
					setCursorPosition(person[0]->x + gamePanel->x + 1, person[0]->y + gamePanel->y + 1 + j);
					for (int k = 0; k < 3; k++)
					{
						printf(" ");
					}
				}
			person[0]->y = 2;
		}
		else
		{
			setColor(0xFF);
			for (int j = 0; j < 2; j++)
			{
				setCursorPosition(person[0]->x + gamePanel->x + 1, person[0]->y + gamePanel->y + 1 + j);
				for (int k = 0; k < 3; k++)
				{
					printf(" ");
				}
			}
			person[0]->y = 8;
		}
	}
}
void PersonKey_down(char a)
{

	if (person == NULL || person[1] == NULL)
	{
		return;
	}
	else
	{
		if (person[1]->y == 14)
		{
			setColor(0xFF);
			for (int j = 0; j < 2; j++)
			{
				setCursorPosition(person[1]->x + gamePanel->x + 1, person[1]->y + gamePanel->y + 1 + j);
				for (int k = 0; k < 3; k++)
				{
					printf(" ");
				}
			}
			person[1]->y = 20;
		}
		else
		{
			setColor(0xFF);
			for (int j = 0; j < 2; j++)
			{
				setCursorPosition(person[1]->x + gamePanel->x + 1, person[1]->y + gamePanel->y + 1 + j);
				for (int k = 0; k < 3; k++)
				{
					printf(" ");
				}
			}
			person[1]->y = 14;
		}
	}
}
void PersonKeyInit()
{
	if (personKey == NULL)
	{
		personKey = (Key*)malloc(sizeof(Key));
		memset(personKey, 0, sizeof(Key));
		personKey->up = personKey_up;
		personKey->down = PersonKey_down;
	}
}
void KeyBind(Key * key)
{
	char curChar = ReadChar();
	if (curChar != 0)
	{
		if (curChar == 0xffffffe0)
		{
			curChar = ReadChar();
		}
		if (key != NULL)
		{
			switch (curChar)
			{
				case 0x48:
				case 'w':
					if (key->up != NULL)
					{
						key->up(curChar);
					}
					break;
				case 0x50:
				case 's':
					if (key->down != NULL)
					{
						key->down(curChar);
					}
					break;
				case 0x4b:
				case 'a':
					if (key->left != NULL)
					{
						key->left(curChar);
					}
					break;
				case 0x4d:
				case 'd':
					if (key->right != NULL)
					{
						key->right(curChar);
					}
					break;
				case 13:
					if (key->enter != NULL)
					{
						key->enter(curChar);
					}
			}
		}
	}
}

char ReadChar()
{
	char rech = 0;
	if (_kbhit())
	{
		rech = _getch();
	}
	return rech;
}

void PersonKey()
{
	PersonKeyInit();
	KeyBind(personKey);
}

void MenuKey()
{
	menuKeyInit();
	KeyBind(menuKey);
}
