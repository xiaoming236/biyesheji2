#include "beep.h"
   

//��ʼ��PB8Ϊ�����.��ʹ������ڵ�ʱ��		    
//��������ʼ��
void BEEP_Init(void)
{
 
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��GPIOB�˿�ʱ��

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_13;				 //BEEP-->PB.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);	 //���ݲ�����ʼ��GPIOB.8
     GPIO_ResetBits(GPIOC,GPIO_Pin_13);
     GPIO_ResetBits(GPIOC,GPIO_Pin_14);
}
void shuikai(void)
{
 GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
}
	
void shuiguan(void)
{
 GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
}

void fengkai(void)
{
 GPIO_WriteBit(GPIOC,GPIO_Pin_14,Bit_SET);
}
void fengguan(void)
{
 GPIO_WriteBit(GPIOC,GPIO_Pin_14,Bit_RESET);
}