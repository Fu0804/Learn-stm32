# Learn-stm32-day3-2024/05/09
## GPIO理论简介
* GPIO(General Purpose Input Output)通用输入输出口
* 具体分为八种模式
* 引脚电平：0V~3.3V，部分引脚可容忍5V（容忍5V指可在这个端口输入5V的电压，但是输出仍最高只能为3.3V，受电源限制。具体哪些端口可以容忍5V，可查阅[引脚定义图](https://github.com/Fu0804/Learn-stm32/blob/main/Learn-stm32-day1-2024/05/day1.md#%E5%BC%95%E8%84%9A%E5%AE%9A%E4%B9%89)。）
* 输出模式下可**控制端口输出高低电平**，用以**驱动LED**、**控制蜂鸣器**、**模拟通信协议输出时序**等
* 输入模式下可**读取端口的高低电平或电压**，用于**读取按键输入(最常见)**、**外接模块电平信号输入**、**ADC电压采集**、**模拟通信协议接收数据**等

## GPIO基本结构
![image](https://github.com/Fu0804/Learn-stm32/assets/151499353/8f609f3b-c9b2-4eb5-b44e-05890af75fcd)


