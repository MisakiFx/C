/**
�¼��������ļ�
*/
#include "KeyHandle.h"
/**
�ⲿ���ð���������
*/
void key_handle_operator(DefaultHandle * handle, KeyMapping * mappings, int len)
{
	char recivekey = 0;
	recivekey = readChar();
	if (recivekey != 0)
	{
		//���水������
		if (recivekey == 0xffffffe0)
		{
			recivekey = readChar();
		}
		if (handle != NULL)//0xffffffe0
		{
			switch (recivekey)
			{
			case 'w'://�Ϸ��� 0x48
			case 0x48:
				if (handle->up != NULL)
				{
					handle->up('w');
				}
				break;
			case 's'://�·��� 0x50
			case 0x50:
				if (handle->down != NULL)
				{
					handle->down('s');
				}
				break;
			case 'a'://���� 0x4b
			case 0x4b:
				if (handle->left != NULL)
				{
					handle->left('a');
				}
				break;
			case 'd'://�ҷ��� 0x4d
			case 0x4d:
				if (handle->right != NULL)
				{
					handle->right('d');
				}
				break;
			}
		}
		//���ⰴ��ӳ�䴦��
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
