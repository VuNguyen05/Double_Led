#include <Arduino.h>
#include "LED.h"       
#include "OneButton.h" 
#define LED1_PIN 25  
#define LED2_PIN 5  
#define BTN_PIN 23  

#define LED_ACTIVE_LEVEL HIGH

LED led1(LED1_PIN, LED_ACTIVE_LEVEL);
LED led2(LED2_PIN, LED_ACTIVE_LEVEL);

OneButton button(BTN_PIN, true, true);

int currentLed = 1;

void handleDoubleClick()
{
    if (currentLed == 1)
    {
        currentLed = 2;
        Serial.println(">> Double Click: Chuyen sang dieu khien LED 2 (GPIO 5)");
    }
    else
    {
        currentLed = 1;
        Serial.println(">> Double Click: Chuyen sang dieu khien LED 1 (GPIO 2)");
    }
}
void handleClick()
{
    if (currentLed == 1)
    {
        led1.flip();
        Serial.println("Single Click: Dao trang thai LED 1");
    }
    else
    {
        led2.flip();
        Serial.println("Single Click: Dao trang thai LED 2");
    }
}
void handleLongPress()
{
    if (currentLed == 1)
    {
        led1.blink(200);
        Serial.println("Long Press: LED 1 nhap nhay (200ms)");
    }
    else
    {
        led2.blink(200);
        Serial.println("Long Press: LED 2 nhap nhay (200ms)");
    }
}

void setup()
{
    Serial.begin(115200);
    button.attachClick(handleClick);
    button.attachDoubleClick(handleDoubleClick);
    button.attachLongPressStart(handleLongPress);
}

void loop()
{
    button.tick();
    led1.loop();
    led2.loop();
}
