# Learn-stm32-day1-2024/05/07
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

2. 



