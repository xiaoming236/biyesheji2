#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK miniSTM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PAin(4)   	
//#define KEY1 PAin(5)	
//#define KEY1 PAin(6)
//#define KEY1 PAin(7)
////#define WK_UP  PAin(0)	 
 

#define KEY0    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)//��ȡ����0
#define KEY1    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)//��ȡ����1
#define KEY2    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)//��ȡ����2
#define KEY3    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)//��ȡ����3

#define KEY0_PRES	1		//KEY0  
#define KEY1_PRES	2		//KEY1 
#define KEY2_PRES	3		//KEY2
#define KEY3_PRES	4		//KEY2
 

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��	


#endif


