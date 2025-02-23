/**************************************************************************************
����ģʽ

    -���븡�գ�GPIO_Mode_IN_FLOATING��

    -��������(GPIO_Mode_IPU)

    -��������(GPIO_Mode_IPD)

    -ģ������(GPIO_Mode_AIN)

���ģʽ

    -��©���(GPIO_Mode_Out_OD)

    -��©���ù���(GPIO_Mode_AF_OD)

    -����ʽ���(GPIO_Mode_Out_PP)

    -����ʽ���ù���(GPIO_Mode_AF_PP)	 

**************************************************************************************/


#include "key.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//�������� ��������		   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/06
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019




//������ʼ������ 
//PA15��PC5 ���ó�����
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTA,PORTCʱ��

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;       //PA4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;    //���ó��������룬ƽʱΪ�ߣ�����ʱ�͵�ƽ����
 	GPIO_Init(GPIOB, &GPIO_InitStructure);           //��ʼ��GPIOA4
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;        //PA5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;     //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);             //��ʼ��GPIOA5
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;       //PC15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;    //���ó��������룬ƽʱΪ�ߣ�����ʱ�͵�ƽ����
 	GPIO_Init(GPIOB, &GPIO_InitStructure);           //��ʼ��GPIOC15
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				    //��������-->PC14 �˿�����,��������Ҫһ���ߵ�ƽ���壬����Ҫ����Ϊ����ʽ���
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		  //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		  //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOC.14
	
	
	
} 
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//����ֵ��
//0��û���κΰ�������
//KEY0_PRES��KEY0����
//KEY1_PRES��KEY1����
//KEY2_PRES��KEY2����
//KEY3_PRES��KEY3����
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		     
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||KEY3==0))
	{
//		delay_ms(10);//ȥ���� 
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(KEY3==0)return KEY3_PRES;
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&KEY3==1)key_up=1; 	     
	return 0;// �ް�������
}












