#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	//��gpio����0000 0000 0000 0000������gpio��
	//���������0x000f��ʾ�Ժ���λ�˿��øߵ�ƽ����ʾѡ�ж�Ӧ�˿�
	GPIO_InitStructure.GPIO_Pin=0x000f;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);
	while(1)
	{
//��Ϊ����ѵ�ƽ��Ϊ0000 0000 0000 1111������ֱ��ȡ���Զ˿���������Ա���Ϊ�͵�ƽ����
		GPIO_Write(GPIOA,~GPIO_Pin_0);
		Delay_ms(500);
		GPIO_Write(GPIOA,~GPIO_Pin_1);
		Delay_ms(500);
		GPIO_Write(GPIOA,~GPIO_Pin_2);
		Delay_ms(500);
		GPIO_Write(GPIOA,~GPIO_Pin_3);
		Delay_ms(500);
		
//��Ϊ����GPIO_InitStructure.GPIO_Pin=0x000f;��δ���û��ѡ��PA4�˿ڣ����������������Ч
	    GPIO_Write(GPIOA,~GPIO_Pin_4);
	}
}