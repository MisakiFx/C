/*
������ż��㺯�����ô����ĺ���ʵ�ּ�ԭ��
*/
int whileCount;//�ⲿ�����ڲ�ͬ�ļ���ʹ��ʱ��Ҫ���¶���
void counter(int);//���㵱ǰ�ĺ���ִ���˶��ٴ�
void counter(int i)
{
    static int subTotal=0;
    subTotal++;
    printf("counter������������%d��\n",subTotal);
    printf("whileѭ���ĵ�ǰ�����ǵ�%d��\n",whileCount);
    return 0;
}
