# 示例 11: 输入触发输出

## 功能描述

本示例演示如何实现数字量输入触发继电器输出的联动控制功能。

## 硬件说明

### 输入输出映射
- IN1 → OUT1
- IN2 → OUT2
- IN3 → OUT3
- IN4 → OUT4

### 触发模式
- 电平触发: 输入为高电平时输出导通
- 边沿触发: 输入状态变化时切换输出
- 可配置延时和消抖

## 软件说明

### 依赖库
- `PCF8574` by Rob Tillaart - I/O扩展芯片控制
- `Wire` - I2C通信库

### 关键代码
```cpp
#define PCF8574_OUTPUT_ADDR 0x22
#define PCF8574_INPUT_ADDR 0x21

PCF8574 pcf_out(PCF8574_OUTPUT_ADDR);
PCF8574 pcf_in(PCF8574_INPUT_ADDR);

uint8_t lastInputState = 0;

void setup() {
  Wire.begin(8, 9);
  pcf_out.begin();
  pcf_in.begin();
}

void loop() {
  uint8_t inputState = pcf_in.read8();
  
  // 检测输入变化
  if (inputState != lastInputState) {
    // 输入触发输出
    pcf_out.write8(inputState);
    lastInputState = inputState;
  }
  
  delay(50);  // 消抖延时
}
```

## 使用方法

1. 连接输入信号到IN1-IN4
2. 连接负载到OUT1-OUT4
3. 输入信号变化将自动触发对应输出

## 预编译固件

本目录下的`precompiled/`文件夹包含预编译的固件文件，可直接烧录到F4控制器。

## 相关资源

- [F4产品页面](https://www.kincony.com)
