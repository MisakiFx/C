#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#pragma comment(lib,"Winmm.lib")
#define High 590 //画面尺寸
#define Width 800
long int count = 0;//轮数
IMAGE img_bk; // 背景图片
double position_x, position_y; // 主角位置
IMAGE img_normal1, img_normal2; // 正常主角图片
IMAGE img_explode1, img_explode2; // 爆炸主角图片
IMAGE img_bullet1, img_bullet2; // 子弹图片
int score = 0; // 得分
int isExplode = 0;//是否存活
typedef struct  _bullet
{
	double x;
	double y;
	struct _bullet* next;
}Bullet;
Bullet* g_head = NULL;
void InitData()
{
	srand(time(NULL));
	mciSendString("open D:\\bk_Music.mp3 alias bkmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  // 循环播放
	initgraph(Width, High);
	loadimage(&img_bk, "D:\\bk.jpg");
	loadimage(&img_normal1, "D:\\normal1.jpg");
	loadimage(&img_normal2, "D:\\normal2.jpg");
	loadimage(&img_bullet1, "D:\\bullet1.jpg");
	loadimage(&img_bullet2, "D:\\bullet2.jpg");
	loadimage(&img_explode1, "D:\\explode1.jpg");
	loadimage(&img_explode2, "D:\\explode2.jpg");
	position_x = Width * 0.3;
	position_y = High * 0.5;
	for (int i = 0; i < 3; i++)
	{
		Bullet* p = (Bullet*)malloc(sizeof(Bullet));
		p->next = g_head;
		p->x = Width;
		p->y = rand() % High;
		g_head = p;
	}
	BeginBatchDraw();
}
void show()
{
	putimage(0, 0, &img_bk);	// 显示背景	
	if (isExplode == 0)
	{
		putimage(position_x - 50, position_y - 60, &img_normal1, NOTSRCERASE); // 显示正常飞机	
		putimage(position_x - 50, position_y - 60, &img_normal2, SRCINVERT);
		Bullet* p = g_head;
		while (p != NULL)
		{
			putimage(p->x, p->y - 7, &img_bullet1, NOTSRCERASE); // 显示子弹	
			putimage(p->x, p->y - 7, &img_bullet2, SRCINVERT);
			p = p->next;
		}
	}
	else
	{
		putimage(position_x - 50, position_y - 60, &img_explode1, NOTSRCERASE); // 显示爆炸飞机	
		putimage(position_x - 50, position_y - 60, &img_explode2, SRCINVERT);
	}
	outtextxy(Width*0.48, High*0.95, "得分：");
	char s[5] = { 0 };
	sprintf_s(s, 5, "%d", score);
	outtextxy(Width*0.55, High*0.95, s);
	FlushBatchDraw();
	Sleep(2);
}
void updateWithoutInput()
{
	Bullet* p1 = g_head;
	while (p1 != NULL)//更新弹幕
	{
			p1->x -= count / 10000 + 1;
		p1 = p1->next;
	}
	if (count != 0 && count % (((100 - (count / 10000) * 30) > 10) ? (100 - (count / 10000) * 30) : 10)== 0)//创造新的弹幕
	{
		for (int i = 0; i < 5; i++)
		{
			Bullet* p2 = (Bullet*)malloc(sizeof(Bullet));
			p2->next = g_head;
			p2->x = Width;
			p2->y = rand() % High;
			g_head = p2;
		}
	}
	p1 = g_head;
	while (p1 != NULL)//删除失效弹幕
	{
		if (p1->x < 0)
		{
			Bullet* p2 = g_head;
			while (p2->next != p1)
			{
				p2 = p2->next;
			}
			Bullet* p3 = p1;
			p1 = p1->next;
			p2->next = p1;
			free(p3);
			continue;
		}
		p1 = p1->next;
	}
	p1 = g_head;
	while (p1 != NULL)
	{
		if (abs((int)(position_x - p1->x)) + abs((int)(position_y - p1->y)) < 20)//弹幕击中我们
		{
			isExplode = 1;
			mciSendString("close exmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString("open D:\\explode.mp3 alias exmusic", NULL, 0, NULL); // 打开音乐
			mciSendString("play exmusic", NULL, 0, NULL); // 仅播放一次		
		}
		p1 = p1->next;
	}
	if (count != 0 && count % 100 == 0)
	{
		score++;
	}
}
void updateWithInput()
{
	if (isExplode == 0)
	{
		MOUSEMSG m;		// 定义鼠标消息
		while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_MOUSEMOVE)
			{
				// 飞机的位置等于鼠标所在的位置
				position_x = m.x;
				position_y = m.y;
			}
		}
	}
}
void gameover()
{
	EndBatchDraw();
	outtextxy(Width*0.48, High*0.9, "游戏结束按任意键退出！");
	_getch();
	closegraph();
}
int main()
{
	InitData();
	while (1)
	{
		show();
		if (isExplode == 1)
		{
			break;
		}
		updateWithoutInput();
		updateWithInput();
		count++;
	}
	gameover();
}