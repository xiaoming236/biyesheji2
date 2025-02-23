#include "stm32f10x.h"                  // Device header


void PWM_init(void)
{
	//TIM4��ʱ��1ͨ����ӦGPIOA0
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);// GPIO���ã�PA1��ΪPWM���
	 //RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);���д����޸�����
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//ʹ��Ӧ���Ź���ɥʧ����ӳ�����ţ�����GPIO���,���ֲ��ظ����岿�ֻ���GPIO15���
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//���������������ʱ�������ʽ    �����������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	   // ��ʱ������
	// PWMƵ�� = 72M / 720 / 100 = 1KHz
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//��ʼ��ʱ����Ԫ
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;//arr
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;//psc
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=0;//ccr
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	TIM_OC2Init(TIM2,&TIM_OCInitStructure);
	TIM_Cmd(TIM2, ENABLE);
}


void PWM_init1(void)
{
	//TIM4��ʱ��1ͨ����ӦGPIOA0
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); 
	 //RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);���д����޸�����
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//ʹ��Ӧ���Ź���ɥʧ����ӳ�����ţ�����GPIO���,���ֲ��ظ����岿�ֻ���GPIO15���
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//���������������ʱ�������ʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6; // GPIO���ã�PB6��ΪPWM���
	  // ��ʱ������
    // PWMƵ�� = 72M / 72 / 20000 = 50Hz (�����ڶ������)
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//��ʼ��ʱ����Ԫ
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;//arr
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//psc
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=0;//ccr
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);
	TIM_Cmd(TIM4, ENABLE);
}
void PWM_SetCompare2(uint16_t Compare)// ��������TIM2ͨ��2��PWMռ�ձȣ��������ڷ����ٶȿ��ƣ�
{
	
TIM_SetCompare2(TIM2,Compare);
 
}

void PWM_SetCompare1(uint16_t Compare)// ��������TIM4ͨ��1��PWMռ�ձȣ����ڶ���Ƕȿ��ƣ�
{
	
TIM_SetCompare1(TIM4,Compare);
 
}


