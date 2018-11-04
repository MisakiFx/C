#include <stdio.h>
//结构体的指针（结构指针变量）
//机构指针变量中的值是所指向的结构变量的首地址
//struct 结构名称*结构指针变量名
struct Martial//门派 
{
	int id;//门派的编号 
	char name[50];//门派的人称 
	int count;//当前门派的总人数
	int type;//门派的类型——1正派；2中立；3邪派	
};
struct Player
{
	int id;//玩家的编号
	char name[50];//玩家的名称
	char pass[50];//玩家的登录密码
	char sex;//玩家的性别
	struct Martial martial;//玩家所属门派	
}; 
int main()
{
	struct Player player1={1,"Misaki","123456",'m',{1,"loi必胜",500,3}};
	struct Player *ptr_player1=&player1;
	printf("%s\t%s\n",player1.name,player1.martial.name);
	printf("%s\t%s\n",(*ptr_player1).name,(*ptr_player1).martial.name);//使用指针来访问（别忘了要给指针名加括号用来先访问指针取指针对应的值）
	printf("%s\t%s\n",ptr_player1->name,ptr_player1->martial.name);//可以用指针直接来访问，->，前面是指针后面是指针所指向内容的里面的属性0 
} 
