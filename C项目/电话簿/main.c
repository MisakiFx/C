#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define ADDRESS_INFOS_MAX 200
typedef struct AddressInfo
{
  char name[1024];
  char phone[1024];
}AddressInfo;
typedef struct AddressBook
{
  AddressInfo* infos;
  int size;
  int capacity;//容量
}AddressBook;
AddressBook g_addr_book;
//初始化
void Init(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  addr_book->size = 0;
  addr_book->capacity = 10;
  addr_book->infos = (AddressInfo*)malloc(sizeof(AddressInfo) * addr_book->capacity);
  return;
}
//菜单
int Menu()
{
  printf("===========================\n");
  printf("1、新增\n");
  printf("2、删除\n");
  printf("3、修改\n");
  printf("4、查找\n");
  printf("5、排序\n");
  printf("6、显示全部\n");
  printf("7、删除全部\n");
  printf("0、退出\n");
  printf("===========================\n");
  int choice;
  scanf("%d", &choice);
  return choice;
}
//扩容
void Realloc(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  //1、扩大capacity的取值
  addr_book->capacity *= 2;
  //2、申请一个更大的内存
  AddressInfo* old_infos = addr_book->infos;
  addr_book->infos = (AddressInfo*)malloc(sizeof(AddressInfo) * addr_book->capacity);
  //3、将原有内存中的数据复制过来
  for(int i = 0; i < addr_book->size; i++)
  {
    addr_book->infos[i] = old_infos[i];
  }
  //4、释放原有的内存
  free(old_infos);  
  //此处每次扩容阔多少由我们自己定制
  printf("扩容成功！\n");
}
//新增
void AddAddressBook(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  if(addr_book->size >= addr_book->capacity)
  {
    printf("空间已满进行扩容！\n");
    Realloc(addr_book);
  }
  printf("请输入联系人信息！\n");
  AddressInfo* p = &addr_book->infos[addr_book->size];
  printf("请输入联系人姓名：");
  scanf("%s", p->name);
  printf("请输入联系人电话：");
  scanf("%s", p->phone);
  addr_book->size++;
  printf("添加成功！\n");
  return;
}
//删除
void DelAddressBook(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  int id;
  printf("请输入要删除的联系人序号：");
  scanf("%d", &id);
  if(id < 0 || id >= addr_book->size)
  {
    printf("输入需要有误！\n");
    return;
  }
  printf("删除的序号为[%d]，确认删除请输入Y:", id);
  char sure[1024] = {0};
  scanf("%s", sure);
  if(strcmp(sure, "Y") != 0)
  {
    printf("删除中止！\n");
    return;
  }
  AddressInfo* from = &addr_book->infos[addr_book->size - 1];
  AddressInfo* to = &addr_book->infos[0];
  *to = *from;
  addr_book->size--;
  return;
}
//修改
void ModifyAddressBook(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  printf("修改联系人！\n");
  printf("请输入需要修改的联系人序号：");
  int id = 0;
  scanf("%d", &id);
  if(id < 0 || id >= addr_book->size)
  {
    printf("输入序号错误！\n");
    return;
  }
  AddressInfo* p = &addr_book->infos[id];
  char input[1024] = {0};
  printf("请输入要修改的姓名：");
  scanf("%s", input);
  if(strcmp(input, "#") != 0)
  {
    strcpy(p->name, input);
  }
  printf("请输入要修改的电话：");
  scanf("%s", input);
  if(strcmp(input, "#") != 0)
  {
    strcpy(p->phone, input);
  }
  printf("修改成功！\n");
  return;
}
//查找
void FindAddressBook(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  printf("开始进行查找！\n");
  printf("请输入要查找的姓名：");
  char name[1024] = {0};
  scanf("%s", name);
  int count = 0;
  for(int i = 0; i < addr_book->size; i++)
  {
    AddressInfo* p = &addr_book->infos[i];
    if(strcmp(name, p->name) == 0)
    {
      printf("[%d] %s\t %s", i, p->name, p->phone);
      ++count;
    }
  }
  return;
}
//排序
void SortAddressBook(AddressBook* addr_book)
{
  return;
}
//打印全部
void PrintAllAddressBook(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  printf("显示所有联系人！\n");
  for(int i = 0; i < addr_book->size; i++)
  {
    AddressInfo* p = &addr_book->infos[i];
    printf("[%d] %s\t%s\n", i, p->name, p->phone);
  }
  printf("共显示了%d条数据！\n", addr_book->size);
  return;
}
//清楚全部
void ClearAllAddressBook(AddressBook* addr_book)
{
  assert(addr_book != NULL);
  printf("确定要清除全部信息么，确定请输入Y：");
  char sure[1024] = {0};
  scanf("%s", sure);
  if(strcmp(sure, "Y") != 0)
  {
    printf("清除已经取消！\n");
    return;
  }
  addr_book->size = 0;
  return;
}
int main()
{
  Init(&g_addr_book);
  typedef void (*ptr_func)(AddressBook*);
  ptr_func table[] = {
    AddAddressBook,
    DelAddressBook,
    ModifyAddressBook,
    FindAddressBook,
    SortAddressBook,
    PrintAllAddressBook,
    ClearAllAddressBook,
  };
  while(1)
  {
    int choice = Menu();
    if(choice == 0)
    {
      printf("使用完毕，退出！\n");
      return 0;
    }
    table[choice - 1](&g_addr_book);
  }

}
