# SimpleLed

`SimpleLed` 是一个 Arduino 库，它的功能是控制 LED 亮、灭和闪烁。这是一个特别简单的项目，想要在不使用阻塞式延时的情况下能够控制 LED 进行闪烁。

## 使用说明

你需要在你项目中包含 `SimpleLed.h`：
```cpp
#include "SimpleLed.h"
```

### 如何初始化
在对 LED 引脚进行初始化之后，会默认将 LED 设置关闭状态。

当引脚输出为高电平时点亮 LED：
```cpp
#define LED_PIN LED_BUILTIN

SimpleLed led(LED_PIN);
```
或者：
```cpp
#define LED_PIN LED_BUILTIN

SimpleLed led(LED_PIN, HIGH);
```

当引脚输出为低电平时点亮 LED：
```cpp
#define LED_PIN LED_BUILTIN

SimpleLed led(LED_PIN, LOW);
```

### 如何控制 LED

点亮 LED：
```cpp
    led.setState(SimpleLed::LedState::ON);
```

关闭 LED：
```cpp
    led.setState(SimpleLed::LedState::OFF);
```

LED 每 1s 切换一次状态（亮-1s->灭-1s->亮->...），需要在 loop() 中调用 update()：
```cpp
void setup() {
    led.setState(SimpleLed::LedState::BLINK, 1000);
}

void loop() {
    led.update();
}
```
