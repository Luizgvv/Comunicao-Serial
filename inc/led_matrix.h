

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "ws2812.pio.h" // Inclua o arquivo gerado pelo PIO

#define LED_COUNT 25
#define WS2812_PIN 7 // Defina o pino aqui ou passe como argumento para led_matrix_init

// Declaração da função que exibe o padrão na matriz WS2812.
void display_number_on_ws2812(int number);

void led_matrix_init(PIO pio, uint pin);

void set_led_color(int index, uint8_t r, uint8_t g, uint8_t b);
void refresh_led_matrix(void);
void turn_off_led_matrix(void);  // Declaração da função
