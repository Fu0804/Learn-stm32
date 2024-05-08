#include "stm32f10x.h"                  // Device header

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能GPIOC端口的时钟。RCC_APB2PeriphClockCmd是用来控制高级外设时钟的函数； RCC_APB2Periph_GPIOC指定了要控制的外设（这里是GPIOC），ENABLE是使能时钟。
	GPIO_InitTypeDef GPIO_InitStructure; // 声明一个GPIO_InitTypeDef类型的结构体变量GPIO_InitStructure，用于初始化GPIO端口。
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 设置GPIO端口的模式为推挽输出。
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; // 指定GPIO端口的引脚号为13号引脚，因为灯在这个引脚相接。
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置GPIO端口的速度为50MHz。
	GPIO_Init(GPIOC, &GPIO_InitStructure); // 根据GPIO_InitStructure中的配置初始化GPIOC端口。
	GPIO_SetBits(GPIOC, GPIO_Pin_13); // 设置GPIOC的13号引脚为高电平。
//	GPIO_ResetBits(GPIOC, GPIO_Pin_13); // 设置GPIOC的13号引脚为低电平。
	while (1)
	{
		
	}
}
