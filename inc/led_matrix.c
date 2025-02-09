#include "led_matrix.h"



// Cores pré-definidas para cada número
static const uint32_t cores_numeros[10] = {
    0xFF0000, // Vermelho
    0x00FF00, // Verde
    0x40E0D0, // Azul turquesa
    0xFFFF00, // Amarelo
    0xFF00FF, // Magenta
    0x00FFFF, // Ciano
    0xFF8000, // Laranja
    0x800080, // Roxo
    0x008080, // Teal
    0x808000  // Oliva
};

// Padrões dos números para matriz 5x5
static const uint8_t numeros[10][LED_COUNT] = {
        // 0
        { 0,1,1,1,0,
            1,0,0,0,1,
            1,0,0,0,1,
            1,0,0,0,1,
            0,1,1,1,0 },
          // 1
          { 0,1,1,1,0,
            0,0,1,0,0,
            0,0,1,0,0,
            0,1,1,0,0,
            0,0,1,0,0 },
          // 2
          { 1,1,1,1,1,
            0,0,1,0,0,
            0,1,0,0,0,
            1,0,0,0,1,
            0,1,1,1,0 },
          // 3
          { 0,1,1,1,1,
            0,0,0,0,1,
            0,1,1,0,0,
            0,0,0,0,1,
            0,1,1,1,1 },
          // 4
          { 0,1,0,0,0,
            1,1,1,1,1,
            0,1,0,0,1,
            0,1,0,1,0,
            0,1,1,0,0 },
          // 5
          { 0,1,1,1,1,
            0,0,0,0,1,
            0,1,1,1,1,
            1,0,0,0,0,
            1,1,1,1,1 },
          // 6
          { 0,1,1,1,0,
            1,0,0,0,1,
            0,1,1,1,1,
            1,0,0,0,0,
            0,1,1,1,0 },
          // 7
          { 0,0,0,1,0,
            0,0,1,0,0,
            0,1,0,0,0,
            0,0,0,0,1,
            1,1,1,1,1 },
          // 8
          { 0,1,1,1,0,
            1,0,0,0,1,
            0,1,1,1,0,
            1,0,0,0,1,
            0,1,1,1,0 },
          // 9
          { 0,1,1,1,0,
            0,0,0,0,1,
            1,1,1,1,0,
            1,0,0,0,1,
            0,1,1,1,0 },
           
      };


      static PIO ws2812_pio;
      static uint ws2812_sm = 0;
      
      void led_matrix_init(PIO pio, uint pin) {
          ws2812_pio = pio;
          uint offset = pio_add_program(ws2812_pio, &ws2812_program);
          ws2812_program_init(ws2812_pio, ws2812_sm, offset, pin, 800000, false);
      }

// Função para exibir o padrão de um número na matriz WS2812 com cores personalizadas
void display_number_on_ws2812(int number) {
    uint32_t led_colors[LED_COUNT];
    // Define as cores: "on" é a cor específica para o número; "off" é desligado (preto)
    uint32_t on_color = cores_numeros[number]; // Utiliza a cor definida para este número
    uint32_t off_color = 0x000000;
    
    // Para cada LED na matriz, verifica o padrão (1 ou 0)
    for (int i = 0; i < LED_COUNT; i++) {
        led_colors[i] = (numeros[number][i] == 1) ? on_color : off_color;
    }
    // Envia os dados para cada LED usando o PIO (cada LED recebe 32 bits)
    for (int i = 0; i < LED_COUNT; i++) {
        pio_sm_put_blocking(pio0, 0, led_colors[i] << 8u);
    }
}

void turn_off_led_matrix() {
  uint32_t led_colors[LED_COUNT];
  
  // Define a cor "off" como preta
  uint32_t off_color = 0x000000;

  // Define todos os LEDs como apagados
  for (int i = 0; i < LED_COUNT; i++) {
      led_colors[i] = off_color;
  }

  // Envia os dados para cada LED (todos apagados)
  for (int i = 0; i < LED_COUNT; i++) {
      pio_sm_put_blocking(ws2812_pio, ws2812_sm, led_colors[i] << 8u);
  }
}
