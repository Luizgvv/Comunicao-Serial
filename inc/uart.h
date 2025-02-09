#include "led_matrix.h"
#include "botao.h"
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ssd1306.h"
#include "font.h"
#include "pico/time.h"
#include "ws2812.pio.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 10

#define WIDTH 128
#define HEIGHT 64

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define ENDERECO 0x3C

#define LINE_BUFFER_SIZE 64  // Tamanho do buffer

char line_buffer[LINE_BUFFER_SIZE] = {0};
int line_index = 0;

void check_button(ssd1306_t *ssd);

void process_line(ssd1306_t *ssd) {
    if (line_index == 1 && line_buffer[0] >= '0' && line_buffer[0] <= '9') {
        int number = line_buffer[0] - '0';
        ssd1306_fill(ssd, false); // Limpa o display
        ssd1306_draw_char(ssd, line_buffer[0], 60, 20);   // Exibe o número
         // Informações adicionais no display
         ssd1306_draw_string(ssd, "Numero Exibido:", 5, 5);
         ssd1306_send_data(ssd);  // Atualiza o display

         // Informações no Serial Monitor
        display_number_on_ws2812(number);
        printf("Número %c exibido!\n", line_buffer[0]);
    
    } 
    else if (strcmp(line_buffer, "d") == 0) {  // Exceção para o 'd'
        turn_off_led_matrix();
        printf("Matriz de LEDs desligada!\n");
        ssd1306_fill(ssd, false);
        ssd1306_draw_string(ssd, "Matriz OFF", 25, 25);
        ssd1306_send_data(ssd);

    }else if (line_index > 0 && strcmp(line_buffer, "d") != 0) {
        printf("Entrada inválida! Digite um número entre 0 e 9.\n");
        ssd1306_fill(ssd, false); // Limpa o display
        ssd1306_draw_string(ssd, "Entrada", 30, 20);
        ssd1306_draw_string(ssd, "Invalida", 30, 30);
        ssd1306_send_data(ssd);  // Atualiza o display

    }
    
    line_index = 0; // Reseta o buffer
}
char command_buffer[MAX_LINE_LENGTH];
int command_index = 0;

void usb_read_handler(ssd1306_t *ssd) {
    while (true) {
        int c = getchar_timeout_us(0);  // Leitura não bloqueante via USB

        if (c == PICO_ERROR_TIMEOUT) break;  // Nenhum caractere disponível

        putchar(c);  // Ecoa o caractere de volta para o terminal
        command_buffer[command_index] = '\0';  // Finaliza a string
        if (c == '\r' || c == '\n') {  // Enter detectado
            if (line_index > 0) {
                process_line(ssd);  // Processa o comando
                line_index = 0;
                line_buffer[0] = '\0';
            }
        }  else {
            line_buffer[line_index++] = (char)c;
            line_buffer[line_index] = '\0';
        }
    }
}
