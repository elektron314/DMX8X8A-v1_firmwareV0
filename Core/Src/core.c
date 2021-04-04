#include <stdint.h>
#include "main.h"
#include "core.h"

uint8_t duty = 0;
extern uint8_t rotary();
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

bool core_init(void)
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

	return true;
}

void core_process(void)
{
	HAL_GPIO_WritePin(uLED1_GPIO_Port, uLED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(uLED2_GPIO_Port, uLED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(uLED3_GPIO_Port, uLED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(uLED4_GPIO_Port, uLED4_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(uLED1_GPIO_Port, uLED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(uLED2_GPIO_Port, uLED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(uLED3_GPIO_Port, uLED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(uLED4_GPIO_Port, uLED4_Pin, GPIO_PIN_SET);
	HAL_Delay(500);

	duty = rotary(1)*10+rotary(2);
	htim2.Instance->CCR1 = duty;
	htim2.Instance->CCR2 = duty;
	htim2.Instance->CCR3 = duty;
	htim2.Instance->CCR4 = duty;
	htim3.Instance->CCR1 = duty;
	htim3.Instance->CCR2 = duty;
	htim3.Instance->CCR3 = duty;
	htim3.Instance->CCR4 = duty;
}
