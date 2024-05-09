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

### 输入部分
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
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/99c9248c-f480-4ae5-9cf7-f01768472877">
</div>

* 此处两个连接到外设。模拟输入接ADC，复用功能输入接其他端口。

### 输出部分
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/cde2994e-ab22-483e-b1cd-719293e5b2ec">
</div>

* 首先通过输出数据选择器或片上外设控制输出，然后通过数据选择器进入输出控制。
* 如果选择输出数据选择器输出，就是普通I/O口输出，写某一位就可以操作对应的端口了。但是该方式整体操作
* 位设置/清楚寄存器用来单独操作输出寄存器的某一位，而不影响其他位。
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/fc4e9ffd-71cb-421e-b90f-fa44fa2bde5d">
</div>

* 下一部分由两个MOS管组成，MOS管相当于电子开关，通过控制开关开闭选择不同模式。
* 推挽输出模式：P-MOS, N-MOS均有效。**1激活P-MOS管，0激活N-MOS管**。这种模式下，高低电平具有较强驱动能力，也叫强推输出模式。
* 开漏模式：N-MOS有效。可以做通信协议方式。
* 关闭：两个MOS管均无效，端口电平由外部控制。

## GPIO八种工作模式
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/fc4e9ffd-71cb-421e-b90f-fa44fa2bde5d">
</div>

### 浮空/上拉/下拉输入
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/b5aac76d-23db-4f74-9708-78b580a4f3d2">
</div>

### 模拟输入
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/0c63f5f0-e1e5-49e6-864e-af95c6f19739">
</div>

### 开漏/推挽输出
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/e40875ca-10f9-4af5-ada2-15b1e3a33202">
</div>

PS：为什么这里输入是开启的？  
因为一个端口可以有多个输入，但是只能有一个输出。所以这里开启输入让他输入点信号是没什么影响的。

### 复用开漏/推挽输出
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/d7cbbb78-7fa1-45d6-b80b-9fcebb263c97">
</div>

### 有关推挽/开漏输出的详细解释
推挽输出（Push-Pull Output）和开漏输出（Open-Drain Output）是两种常见的数字电路输出类型，用于控制和驱动外部负载。它们的工作方式和应用场景不同，下面是对这两种输出方式的详细解释：  

#### 推挽输出
推挽输出是一种能够在高电平和低电平之间切换的输出方式。在这种配置中，输出端连接了两个晶体管（通常是一个N沟道MOSFET和一个P沟道MOSFET）。这两个晶体管分别控制到地线和电源的连接，但是它们不会同时导通。  

* 高电平时：P沟道MOSFET导通，N沟道MOSFET截止，输出端连接到正电源，输出高电平。
* 低电平时：N沟道MOSFET导通，P沟道MOSFET截止，输出端连接到地线，输出低电平。
推挽输出可以直接驱动负载，不需要外部上拉电阻。它适用于需要快速切换高低电平状态的应用，因为能够提供更强的驱动能力和较快的响应速度。

#### 开漏输出
开漏输出只有一个晶体管控制到地线的连接，没有直接连接到正电源的晶体管。输出状态依赖于外部上拉电阻来定义高电平状态。

* 低电平时：晶体管导通，输出端连接到地线，输出低电平。
* 高电平时：晶体管截止，输出端通过外部上拉电阻连接到正电源，由上拉电阻决定高电平的电压。
开漏输出不能直接提供高电平电压，需要外部电阻来“拉高”电压。这种方式常用于多主机通信接口，如I2C，因为多个设备可以共享同一条线路，任何一个设备可以拉低线路电平而不影响其他设备。

#### 应用场景对比
* 推挽输出：适合于需要提供稳定输出电压和较大电流的应用，如LED驱动、电机控制等。
* 开漏输出：适合于需要多个设备共享同一输出线的通信接口，如I2C、1-Wire等总线系统。

## stm32外部电路设备LED和蜂鸣器简介
* LED：发光二极管，正向通电点亮，反向通电不亮
* 有源蜂鸣器：内部自带振荡源，将正负极接上直流电压即可持续发声，频率固定
* 无源蜂鸣器：内部不带振荡源，需要控制器提供振荡脉冲才可发声，调整提供振荡脉冲的频率，可发出不同频率的声音
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/db37d1e0-b45a-439c-aebc-c41f09211ea8">
</div>

### 硬件电路
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/facf8dd8-0e84-457d-89fd-bcd78546102d">
</div>

* LED驱动电路一般选择第一种，因为一般单片机设计为高电平弱驱动（防止高电平打架），第三种可能不适用。

## 面包板
<div align=center>
<img src="https://github.com/Fu0804/Learn-stm32/assets/151499353/152545ad-cd3e-4a8d-8b8f-2bd923616a41">
</div>

