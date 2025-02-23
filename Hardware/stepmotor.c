#include "stepmotor.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	28BYJ-48�������c�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.8.31
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/


void MOTOR_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(MOTOR_CLK, ENABLE ); //���ø���ʱ��
	GPIO_InitStructure.GPIO_Pin = MOTOR_A|MOTOR_B|MOTOR_C|MOTOR_D;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(MOTOR_PROT,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOA, MOTOR_A|MOTOR_B|MOTOR_C|MOTOR_D);
	
	

	

}

void MOTOR_Rhythm_4_1_4(uint8_t step,uint8_t dly)
{
	switch(step)
	{
		case 0 :
			;;
		break;
		
		case 1 :
			MOTOR_A_LOW;MOTOR_B_HIGH;MOTOR_C_HIGH;MOTOR_D_HIGH;	//1
		break;
		
		case 2 :
			MOTOR_A_HIGH;MOTOR_B_LOW;MOTOR_C_HIGH;MOTOR_D_HIGH;	//2
		break;
		
		case 3 :
			MOTOR_A_HIGH;MOTOR_B_HIGH;MOTOR_C_LOW;MOTOR_D_HIGH;	//3
		break;
		
		case 4 :
			MOTOR_A_HIGH;MOTOR_B_HIGH;MOTOR_C_HIGH;MOTOR_D_LOW;	//4
		break;		
	}
	Delay_ms(dly);
}

void MOTOR_Rhythm_4_2_4(uint8_t step,uint8_t dly)
{
	switch(step)
	{
		case 0 :
			;;
		break;
		
		case 1 :
			MOTOR_A_LOW;MOTOR_B_HIGH;MOTOR_C_HIGH;MOTOR_D_LOW;	//1
		break;
		
		case 2 :
			MOTOR_A_LOW;MOTOR_B_LOW;MOTOR_C_HIGH;MOTOR_D_HIGH;	//2
		break;
		
		case 3 :
			MOTOR_A_HIGH;MOTOR_B_LOW;MOTOR_C_LOW;MOTOR_D_HIGH;	//3
		break;
		
		case 4 :
			MOTOR_A_HIGH;MOTOR_B_HIGH;MOTOR_C_LOW;MOTOR_D_LOW;	//4
		break;		
	}
	
	Delay_ms(dly);
}

void MOTOR_Rhythm_4_1_8(uint8_t step,uint8_t dly)
{
	switch(step)
	{
		case 0 :
			;;
		break;
		
		case 1 :
			MOTOR_A_LOW;MOTOR_B_HIGH;MOTOR_C_HIGH;MOTOR_D_HIGH;	//1
		break;
		
		case 2 :
			MOTOR_A_LOW;MOTOR_B_LOW;MOTOR_C_HIGH;MOTOR_D_HIGH;	//2
		break;
		
		case 3 :
			MOTOR_A_HIGH;MOTOR_B_LOW;MOTOR_C_HIGH;MOTOR_D_HIGH;	//3
		break;
		
		case 4 :
			MOTOR_A_HIGH;MOTOR_B_LOW;MOTOR_C_LOW;MOTOR_D_HIGH;	//4
		break;	
		
		case 5 :
			MOTOR_A_HIGH;MOTOR_B_HIGH;MOTOR_C_LOW;MOTOR_D_HIGH;	//5
		break;
		
		case 6 :
			MOTOR_A_HIGH;MOTOR_B_HIGH;MOTOR_C_LOW;MOTOR_D_LOW;	//6
		break;
		
		case 7 :
			MOTOR_A_HIGH;MOTOR_B_HIGH;MOTOR_C_HIGH;MOTOR_D_LOW;	//7
		break;
		
		case 8 :
			MOTOR_A_LOW;MOTOR_B_HIGH;MOTOR_C_HIGH;MOTOR_D_LOW;	//8
		break;			
	}
	
	Delay_ms(dly);
}

void MOTOR_Direction(uint8_t dir,uint8_t num,uint8_t dly)	//���� ���� Ƶ��
{
	if(dir)
	{
		switch(num)
		{
			case 0:for(uint8_t i=1;i<9;i++){MOTOR_Rhythm_4_1_8(i,dly);}break;
			case 1:for(uint8_t i=1;i<5;i++){MOTOR_Rhythm_4_1_4(i,dly);}break;
			case 2:for(uint8_t i=1;i<5;i++){MOTOR_Rhythm_4_2_4(i,dly);}break;
			default:break;
		}
	}
	else
	{
		switch(num)
		{
			case 0:for(uint8_t i=8;i>0;i--){MOTOR_Rhythm_4_1_8(i,dly);}break;
			case 1:for(uint8_t i=4;i>0;i--){MOTOR_Rhythm_4_1_4(i,dly);}break;
			case 2:for(uint8_t i=4;i>0;i--){MOTOR_Rhythm_4_2_4(i,dly);}break;
			default:break;
		}	
	}
}

void MOTOR_Direction_Angle(uint8_t dir,uint8_t num,u16 angle,uint8_t dly) //���� ����  �Ƕ� Ƶ��
{
		for(u16 i=0;i<(64*angle/45);i++)	//64*64=4096 64*180=256 //512
		{
			MOTOR_Direction(dir,num,dly);	
		}
}

void MOTOR_STOP(void)
{
	GPIO_ResetBits(GPIOA, MOTOR_A|MOTOR_B|MOTOR_C|MOTOR_D);
}

