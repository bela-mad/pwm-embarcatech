#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

/* 
   Definindo a frequência do PWM para, aproximadamente, 50Hz, a frequência do clock 
   para 125MHz, o wrap como 19999µs e o divisor fracionário como 0, podemos realizar
   o cálculo do divisor inteiro do clock, usando a fórmula da frequência do PWM:

   f_pwm = f_clock / (div_int + (div_frac / 16)) * (wrap + 1)
   50 = 125.000.000 / (div_int + (0 / 16)) * (19.999 + 1)
   50 = 125.000.000 / (div_int * 20.000)
   div_int = 125.000.000 / (50 * 20.000)
   div_int = 125.000.000 / 1.000.000
   div_int = 125

   Portanto, esse é o valor da parte inteira do divisor do clock e 
   com essas informações, seguiremos com o uso para configurar o PWM

*/

// Define
#define PWM_SERVO 22

// Declaração de variáveis
const float PWM_DIVISOR = 125.0;    // divisor do clock para o PWM
const uint16_t WRAP_PERIOD = 19999; // valor máximo do contador (wrap)
const float frequencia = 50.0;      // frequência do PWM
uint slice;                         // slice do PWM

// Funções

// Função que configura o módulo PWM
void pwm_setup() {
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM); // habilita o pino GPIO como PWM
    slice = pwm_gpio_to_slice_num(PWM_SERVO);    // obtém o canal PWM da GPIO
    pwm_set_clkdiv(slice, PWM_DIVISOR);          // define o divisor do clock do PWM
    pwm_set_wrap(slice, WRAP_PERIOD);            // define o valor de wrap
    pwm_set_enabled(slice, true);                // habilita o PWM no slice correspondente
}

// Função que modifica o duty cycle do PWM
void pwm_set_duty_cycle(uint ciclo_ativo) {
    uint32_t level = (ciclo_ativo * WRAP_PERIOD) / (1000000 / frequencia);
    pwm_set_gpio_level(PWM_SERVO, level);
}

int main() {

    stdio_init_all();

    pwm_setup();   // configura o PWM

    // Ajuste da flange do servomotor para a posição desejada, de acordo com 
    // o valor do ciclo ativo, em que ele aguarda 05 segundos nesta posição
    pwm_set_duty_cycle(2400);    // 180°
    sleep_ms(5000);              
    pwm_set_duty_cycle(1470);    // 90°
    sleep_ms(5000);
    pwm_set_duty_cycle(500);     // 0°
    sleep_ms(5000);

    while (true) {
        
        // Rotina para movimentação periódica e suave da flange do servomotor entre os ângulos de 0° e 180°
        // Está sendo feito o incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms
        for (int ciclo_atv = 500; ciclo_atv <= 2400; ciclo_atv += 5) {
            pwm_set_duty_cycle(ciclo_atv);
            sleep_ms(10);
        }
        for (int ciclo_atv = 2400; ciclo_atv >= 500; ciclo_atv -= 5) {
            pwm_set_duty_cycle(ciclo_atv);
            sleep_ms(10);
        }
    }

    return 0;
}
