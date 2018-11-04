#include <stdio.h>
//嵌套结构
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
	//玩家Player
	//玩家有属性所属门派（种族，阵营）
	struct Player player={1,"Misaki","123456",'m',{1,"loli必胜",500,1}}; 
	printf("%s\t%s\n",player.name,player.martial.name);
}
