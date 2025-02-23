#include "IR.h"


/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	���洫����c�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.8.10
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/

void IR_Init(void)
{
	#if MODE
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		
		RCC_APB2PeriphClockCmd (IR_AO_GPIO_CLK, ENABLE );	// �� ADC IO�˿�ʱ��
		GPIO_InitStructure.GPIO_Pin = IR_AO_GPIO_PIN;					// ���� ADC IO ����ģʽ
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		// ����Ϊģ������
		
		GPIO_Init(IR_AO_GPIO_PORT, &GPIO_InitStructure);				// ��ʼ�� ADC IO

		ADCx_Init();
	}
	#else
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		
		RCC_APB2PeriphClockCmd (IR_DO_GPIO_CLK, ENABLE );	// ������ ������DO �ĵ�Ƭ�����Ŷ˿�ʱ��
		GPIO_InitStructure.GPIO_Pin = IR_DO_GPIO_PIN;			// �������� ������DO �ĵ�Ƭ������ģʽ
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			// ����Ϊ��������
		
		GPIO_Init(IR_DO_GPIO_PORT, &GPIO_InitStructure);				// ��ʼ�� 
		
	}
	#endif
	
}

#if MODE
uint16_t IR_ADC_Read(void)
{
	//����ָ��ADC�Ĺ�����ͨ��������ʱ��
	return ADC_GetValue(ADC_CHANNEL, ADC_SampleTime_55Cycles5);
}
#endif

uint16_t IR_FireData(void)
{
	
	#if MODE
	uint32_t  tempData = 0;
	for (uint8_t i = 0; i < IR_READ_TIMES; i++)
	{
		tempData += IR_ADC_Read();
		delay_ms(5);
	}

	tempData /= IR_READ_TIMES;
	return 4095 - (uint16_t)tempData;
	
	#else
	uint16_t tempData;
	tempData = !GPIO_ReadInputDataBit(IR_DO_GPIO_PORT, IR_DO_GPIO_PIN);
	return tempData;
	#endif
}



