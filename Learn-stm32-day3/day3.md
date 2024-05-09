# Learn-stm32-day3-2024/05/09
## GPIO理论简介
* GPIO(General Purpose Input Output)通用输入输出口
* 具体分为八种模式
* 引脚电平：0V~3.3V，部分引脚可容忍5V（容忍5V指可在这个端口输入5V的电压，但是输出仍最高只能为3.3V，受电源限制。具体哪些端口可以容忍5V，可查阅[引脚定义图](https://github.com/Fu0804/Learn-stm32/blob/main/Learn-stm32-day1-2024/05/day1.md#%E5%BC%95%E8%84%9A%E5%AE%9A%E4%B9%89)。）
* 输出模式下可**控制端口输出高低电平**，用以**驱动LED**、**控制蜂鸣器**、**模拟通信协议输出时序**等
* 输入模式下可**读取端口的高低电平或电压**，用于**读取按键输入(最常见)**、**外接模块电平信号输入**、**ADC电压采集**、**模拟通信协议接收数据**等

## GPIO基本结构
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/8f609f3b-c9b2-4eb5-b44e-05890af75fcd">
</div>

* 如上图所示，在stm32中，GPIO均挂载在APB2总线上。
* 多个GPIO以GPIOA，GPIOB...方式命名。每个GPIO外设有16个引脚，从0到15编号。第0号引脚叫PA0，第1号叫PA1，以此类推。
* 在每个GPIO模块内，主要包含寄存器与驱动器。其中，寄存器为一块特殊的存储器，内核通过APB2总线对寄存器进行读写，以完成输出电平和读取电平的功能。
* 寄存器的每一位对应一个引脚，输出寄存器写入1，则对应引脚输出高电平，反之为低电平；输入寄存器读取为1，则证明对应端口目前为高电平，反之为低电平。
* 而STM32是32位单片机，故内部寄存器均为32位，而端口仅有16位，故**寄存器仅有低16位有对应端口**，而高16位用不到。
* 驱动器用于增加信号驱动能力，寄存器只负责存储数据。
* 如果要执行点灯操作，是需要驱动器增大驱动能力的。

## GPIO位结构
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/5518af1f-c05b-4f36-bf8f-ac10f783b7a6">
</div>

* 整体结构可以分为两个部分，上面为输入部分，下面为输出部分。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/9ad32e3d-e10b-46d1-b77d-e00923b22fdf">
</div>

* 首先看输入部分右侧的I/O引脚，接了两个保护二极管，用于对输入电压限幅，避免过高的电压，或电流汲取对内部电路造成损害。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/a12342fa-8383-4ee0-afdf-d6dee5baf8d6">
</div>

* 这一部分由一上拉电阻和下拉电阻组成，通过控制开关开断来选择不同的模式。为避免引脚悬空导致输入不确定，在此处加上拉下拉电阻。如果引脚悬空，假设接了上拉电阻，那还将有上拉电阻保证输入高电平。
* 所以上拉输入可以称作默认为高电平的输入模式；下拉输入称作默认为低电平的输入模式。这两个电阻都比较大，目的是不过大影响输入操作。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/2ed7be60-fb8a-4e53-87d1-68a277a15c51">
</div>

* 施密特触发器，用于输入信号整形。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/e0d85a7e-6b5d-489c-8414-45996ff86049">
</div>

* 将经施密特触发器处理后的信号写入输入数据寄存器，即完成信号输入。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/e0d85a7e-6b5d-489c-8414-45996ff86049">
</div>


