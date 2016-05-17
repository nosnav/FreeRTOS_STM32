#include "main.h"

void LED_Init(void);
static void LED_GREEN(void *pvParameters);
static void LED_ORANGE(void *pvParameters);
static void LED_RED(void *pvParameters);
static void LED_BLUE(void *pvParameters);

int main(void)
{
    SystemInit();
    LED_Init();
    xTaskCreate(LED_GREEN, "GREEN", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
    xTaskCreate(LED_ORANGE, "ORANGE", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(LED_RED, "RED", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(LED_BLUE, "BLUE", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    vTaskStartScheduler();
}

void LED_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
        
    /* Configure output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

static void LED_GREEN(void *pvParameters)
{
    for(;;)
    {
        GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
        vTaskDelay(250/portTICK_PERIOD_MS);
    }
}

static void LED_ORANGE(void *pvParameters)
{
    for(;;)
    {
        GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

static void LED_RED(void *pvParameters)
{
    for(;;)
    {
        GPIO_ToggleBits(GPIOD, GPIO_Pin_14);
        vTaskDelay(750/portTICK_PERIOD_MS);
    }
}

static void LED_BLUE(void *pvParameters)
{
    for(;;)
    {
        GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
