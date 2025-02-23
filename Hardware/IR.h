#ifndef __LDR_H
#define	__LDR_H
#include "stm32f10x.h"
#include "adcx.h"
#include "delay.h"
#include "math.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	���洫����h�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.8.10
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/

#define IR_READ_TIMES	10  //���洫����ADCѭ����ȡ����

//ģʽѡ��	
//ģ��AO:	1
//����DO:	0
#define	MODE 	1

/***************�����Լ��������****************/
// LDR GPIO�궨��
#if MODE
#define		IR_AO_GPIO_CLK								RCC_APB2Periph_GPIOA
#define 	IR_AO_GPIO_PORT								GPIOA
#define 	IR_AO_GPIO_PIN								GPIO_Pin_0
#define   ADC_CHANNEL               		ADC_Channel_0	// ADC ͨ���궨��

#else
#define		IR_DO_GPIO_CLK								RCC_APB2Periph_GPIOA
#define 	IR_DO_GPIO_PORT								GPIOA
#define 	IR_DO_GPIO_PIN								GPIO_Pin_1			

#endif
/*********************END**********************/


void IR_Init(void);
uint16_t IR_FireData(void);

#endif /* __ADC_H */

