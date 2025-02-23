#ifndef __STEPMOTOR_H
#define	__STEPMOTOR_H
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	28BYJ-48�������h�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.8.31
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/


/***************�����Լ��������****************/
// ������� GPIO�궨��

#define	MOTOR_CLK				RCC_APB2Periph_GPIOA
#define MOTOR_A 				GPIO_Pin_5
#define MOTOR_B 				GPIO_Pin_6
#define MOTOR_C 				GPIO_Pin_7
#define MOTOR_D 				GPIO_Pin_8
#define MOTOR_PROT 			    GPIOA

#define MOTOR_A_HIGH GPIO_SetBits(MOTOR_PROT,MOTOR_A)
#define MOTOR_A_LOW GPIO_ResetBits(MOTOR_PROT,MOTOR_A)

#define MOTOR_B_HIGH GPIO_SetBits(MOTOR_PROT,MOTOR_B)
#define MOTOR_B_LOW GPIO_ResetBits(MOTOR_PROT,MOTOR_B)

#define MOTOR_C_HIGH GPIO_SetBits(MOTOR_PROT,MOTOR_C)
#define MOTOR_C_LOW GPIO_ResetBits(MOTOR_PROT,MOTOR_C)

#define MOTOR_D_HIGH GPIO_SetBits(MOTOR_PROT,MOTOR_D)
#define MOTOR_D_LOW GPIO_ResetBits(MOTOR_PROT,MOTOR_D)

/*********************END**********************/

void MOTOR_Init(void);
void MOTOR_Init1(void);
void MOTOR_Rhythm_4_1_4(u8 step,u8 dly);
void MOTOR_Direction(u8 dir,u8 num,u8 dly);
void MOTOR_Direction_Angle(u8 dir,u8 num,u16 angle,u8 dly);
void MOTOR_STOP(void);
#endif



