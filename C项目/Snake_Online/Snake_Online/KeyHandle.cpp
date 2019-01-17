/**
事件处理定义文件
*/
#include "KeyHandle.h"
/**
外部调用按键处理函数
*/
void key_handle_operator(DefaultHandle * handle, KeyMapping * mappings, int len)
{
	char recivekey = 0;
	recivekey = readChar();
	if (recivekey != 0)
	{
		//常规按键处理
		if (recivekey == 0xffffffe0)
		{
			recivekey = readChar();
		}
		if (handle != NULL)//0xffffffe0
		{
			switch (recivekey)
			{
			case 'w'://上方向 0x48
			case 0x48:
				if (handle->up != NULL)
				{
					handle->up('w');
				}
				break;
			case 's'://下方向 0x50
			case 0x50:
				if (handle->down != NULL)
				{
					handle->down('s');
				}
				break;
			case 'a'://左方向 0x4b
			case 0x4b:
				if (handle->left != NULL)
				{
					handle->left('a');
				}
				break;
			case 'd'://右方向 0x4d
			case 0x4d:
				if (handle->right != NULL)
				{
					handle->right('d');
				}
				break;
			}
		}
		//特殊按键映射处理
		if (NULL != mappings && len > 0)
		{
			int i;
			for (i = 0; i < len; i++)
			{
				KeyMapping* mapping = mappings + i;
				if (mapping->key == recivekey)
				{
					if (mapping->key_handle != NULL)
					mapping->key_handle(mapping->key);
				}
			}
		}
	}
}
