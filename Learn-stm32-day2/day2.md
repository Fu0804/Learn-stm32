# Learn-stm32-day1-2024/05/08
## 软件安装 
[教程地址: 软件安装_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1th411z7sn/?p=3&spm_id_from=pageDriver&vd_source=6a76004ab22d8805367a30ab5bb4d4f0)
### 安装Keil5 MDK
day1中已安装完成，图标见下：
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/c46b8fcc-0bbe-4df1-b10e-9166ce5802d6">
</div>

### 安装器件支持包
在keil5中，需要开发哪款芯片，就安装哪款芯片对应器件支持包。
1. 打开keil5，点击Project-New uvision Project新建工程
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/a1083cb1-0e12-4a8c-840e-967f7bf02a15">
</div>

**注**：
- 目前只有ARM一个器件列表，且没有stm32型号，这是没有安装stm32器件支持包的情况。
- 如果想要切换为C51，只需在列表中选择Legacy Device即可。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/1848e4ba-9b8b-4e99-bb1f-ba5239686b21">
</div>

2. 接下来按照视频教程离线安装即可。  
**如何在线获取器件支持包？**：
- 如图点击此按键即可在线获取。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/1354d239-161a-41a6-9bb7-e4c8ecbfdeb4">
</div>

### 软件注册
熟悉的keygen小曲

### 安装STLINK软件驱动
依照视频教程即可。
PS：发现自己购买的是入门实验套件里面不包含STLINK，含泪再等快递两天。

### 安装USB转串口驱动
按照视频教程即可。

## 新建工程
采用库函数开发方式，这种方式友好且操作不复杂。
1. 新建好工程后里面空空如也仍无法使用，需要添加必要文件。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/58535e4e-5790-45b6-baf5-6ee02c382886">
</div>

2. 添加好必要文件后如下图所示：
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/a1f48948-8c07-4448-a673-7ca7dc354f97">
</div>

3. 添加文件路径
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/e0519ef2-656b-492f-818c-0ee21235657c">
</div>

4. 创建main.c文件
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/5ff973a5-c346-41f7-b59c-067bc5bec3f9">
</div>

<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/3a62fc6a-def8-4fcd-809c-ba61bb47cea2">
</div>

**中文乱码问题**  
在扳手处修改编码为UTF-8：
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/ef3c25d8-f861-403d-9e91-69741909623b">
</div>

5. 下载程序到stm32（此时stlink还未到，不能执行load操作）  
进行一些有关stlink的初始化工作，然后点击下图按钮load程序到stm32中。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/8dc0117f-95bc-4599-9d7d-51a0f82f824c">
</div>

### 尝试点灯
up主正在使用寄存器进行电灯，简单看了下视频，很懵，还要结合手册，不知道在讲什么，感觉很有必要预习一下数电后面的知识，以及恶补一下51单片机的知识。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/eb70c617-8056-48bd-b494-6980530faa40">
</div>

这样的方式虽然代码简洁、占用内存少但是存在一系列缺点，譬如对新手不友好，编写复杂需查看手册、语义不明确等，所以接下来采用库函数的方式来进行编写，难度低一些且更有优势。  

1. 添加库函数到工程文件中
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/f59b3bb9-d3c3-4eee-8bfa-ba54d9d4a0e2">
</div>

2. 工程选项配置
在工程选项C/C++中加入宏定义以及路径添加以正确配置库函数
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/56c02d30-bd2c-488f-ae5c-ece90be05e2d">
</div>

3. 使用RCC_APB2PeriphClockCmd函数开启时钟
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/98317663-5329-4e17-8bf3-f74fc3d2db90">
</div>

查找源文件查看参数解释及可填写值：
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/6ba1b976-561d-4fa2-8fc9-760afab8b31d">
</div>

```c
/**
  * @brief  Enables or disables the High Speed APB (APB2) peripheral clock.
  * @param  RCC_APB2Periph: specifies the APB2 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *     @arg RCC_APB2Periph_AFIO, RCC_APB2Periph_GPIOA, RCC_APB2Periph_GPIOB,
  *          RCC_APB2Periph_GPIOC, RCC_APB2Periph_GPIOD, RCC_APB2Periph_GPIOE,
  *          RCC_APB2Periph_GPIOF, RCC_APB2Periph_GPIOG, RCC_APB2Periph_ADC1,
  *          RCC_APB2Periph_ADC2, RCC_APB2Periph_TIM1, RCC_APB2Periph_SPI1,
  *          RCC_APB2Periph_TIM8, RCC_APB2Periph_USART1, RCC_APB2Periph_ADC3,
  *          RCC_APB2Periph_TIM15, RCC_APB2Periph_TIM16, RCC_APB2Periph_TIM17,
  *          RCC_APB2Periph_TIM9, RCC_APB2Periph_TIM10, RCC_APB2Periph_TIM11     
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
```
4. 使用GPIO-Init函数配置端口模式  

**补充C语言结构体知识**：[C语言结构体（struct）最全的讲解（万字干货）_struct a *b(const char *name)-CSDN博客](https://blog.csdn.net/lyh290188/article/details/104326450)  
**什么是通用推挽输出？**[推挽输出 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E6%8E%A8%E6%8C%BD%E8%BE%93%E5%87%BA)  
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/2a8b7172-366d-42e8-8b05-a2a70df04ed7">
</div>

ps：原来模电学过这个推挽输出，电路图有点眼熟，灌电流、拉电流...  
**GPIO的八种配置**[STM32初学篇-推挽输出、开漏输出、复用开漏输出、复用推挽输出以及上拉输入、下拉输入、浮空输入、模拟输入区别-CSDN博客](https://blog.csdn.net/wenke8619/article/details/76678545)

<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/18301f87-f0f6-4171-9907-e8cd28e49141">
</div>

函数源代码解释：
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/ba9d292d-e28b-4f77-8c95-4be6412abda9">
</div>

```c
/**
  * @brief  Initializes the GPIOx peripheral according to the specified
  *         parameters in the GPIO_InitStruct.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
  *         contains the configuration information for the specified GPIO peripheral.
  * @retval None
  */
```

配置后：  
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/018d35eb-1b45-4309-bf77-0ac3e7da72ca">
</div>

5. 使用GPIO_SetBits、GPIO_ResetBits函数设置端口高低电平进行电灯

### 最终点灯程序
该程序的功能是初始化STM32F10x微控制器上的C端口的13号引脚，并将其设置为输出高电平，用于点亮连接到该引脚的LED灯。
```c
#include "stm32f10x.h"                  // Device header

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能GPIOC端口的时钟。RCC_APB2PeriphClockCmd是用来控制高级外设时钟的函数； RCC_APB2Periph_GPIOC指定了要控制的外设（这里是GPIOC），ENABLE是使能时钟。
	GPIO_InitTypeDef GPIO_InitStructure; // 声明一个GPIO_InitTypeDef类型的结构体变量GPIO_InitStructure，用于初始化GPIO端口。
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 设置GPIO端口的模式为推挽输出。
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; // 指定GPIO端口的引脚号为13号引脚，因为灯在这个引脚相接。
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置GPIO端口的速度为50MHz。
	GPIO_Init(GPIOC, &GPIO_InitStructure); // 根据GPIO_InitStructure中的配置初始化GPIOC端口。
	GPIO_SetBits(GPIOC, GPIO_Pin_13); // 设置GPIOC的13号引脚为高电平，开灯。
//	GPIO_ResetBits(GPIOC, GPIO_Pin_13); // 设置GPIOC的13号引脚为低电平，关灯。
	while (1)
	{
		
	}
}

```

