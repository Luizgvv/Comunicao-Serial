// Botões e LEDs (LED RGB)
#define BUTTON_B 6
#define BUTTON_A 5
// Função para ler uma linha completa da UART
#define LINE_BUFFER_SIZE 64
#define G_PIN 11
#define B_PIN 12
#include <stdlib.h>
#include <stdio.h>
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h" // Inclua o arquivo gerado pelo PIO

void setup_button_led(void);


