#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	//在gpio中用0000 0000 0000 0000来控制gpio口
	//所以这里的0x000f表示对后四位端口置高电平来表示选中对应端口
	GPIO_InitStructure.GPIO_Pin=0x000f;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);
	while(1)
	{
//因为上面把电平置为0000 0000 0000 1111；这里直接取反对端口输出，所以表现为低电平点亮
		GPIO_Write(GPIOA,~GPIO_Pin_0);
		Delay_ms(500);
		GPIO_Write(GPIOA,~GPIO_Pin_1);
		Delay_ms(500);
		GPIO_Write(GPIOA,~GPIO_Pin_2);
		Delay_ms(500);
		GPIO_Write(GPIOA,~GPIO_Pin_3);
		Delay_ms(500);
		
//因为上面GPIO_InitStructure.GPIO_Pin=0x000f;这段代码没有选中PA4端口，所以下面这语句无效
	    GPIO_Write(GPIOA,~GPIO_Pin_4);
	}
}