#include "botao.h"
#include "led_matrix.h"
#include "pico/stdlib.h"
#include "ssd1306.h"
#include "ws2812.pio.h" 

const uint32_t debounce_delay = 100;  // Ajustado para 100ms
bool button_a_pressed = false;
bool button_b_pressed = false;
bool led_a_state = false;  // Estado do LED A
bool led_b_state = false;  // Estado do LED B

uint32_t last_button_a_press_time = 0;
uint32_t last_button_b_press_time = 0;// Protótipo das funções
void setup_button_led(void);
void display_static_message(ssd1306_t *ssd);


// Configuração dos botões e LEDs
void setup_button_led() {
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(G_PIN);
    gpio_set_dir(G_PIN, GPIO_OUT);
    gpio_put(G_PIN, 0);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    gpio_init(B_PIN);
    gpio_set_dir(B_PIN, GPIO_OUT);
    gpio_put(B_PIN, 0);
}

// Função para exibir uma mensagem fixa
void display_static_message(ssd1306_t *ssd) {
    ssd1306_fill(ssd, false);  // Limpa o display
    ssd1306_draw_string(ssd, "EMBARCATECH", 5, 0);  // Mensagem fixa no topo
    ssd1306_draw_string(ssd, "Aluno:", 5, 10);  // Mensagem fixa no topo
    ssd1306_draw_string(ssd, "Luiz Gustavo", 5, 20);  // Mensagem fixa no topo
    ssd1306_send_data(ssd);
}


// Função para verificar o estado dos botões e aplicar debounce
void check_button(ssd1306_t *ssd) {
    uint32_t current_time_ms = to_ms_since_boot(get_absolute_time());

    // === Botão A: LED Verde ===
    if (!gpio_get(BUTTON_A)) {
        if (!button_a_pressed && (current_time_ms - last_button_a_press_time) > debounce_delay) {
            button_a_pressed = true;
            led_a_state = !led_a_state;  // Alterna o estado do LED verde
            gpio_put(G_PIN, led_a_state);  // Atualiza o LED

            last_button_a_press_time = current_time_ms;

            // Atualiza o display
            display_static_message(ssd);
            if (led_a_state) {
                ssd1306_draw_string(ssd, "LED VERDE:", 25, 35);
                ssd1306_draw_string(ssd, "Ligado", 35, 45);
                 // Envia mensagem para o Serial Monitor
            printf("O LED VERDE foi LIGADO.\n");
            } else {
                ssd1306_draw_string(ssd, "LED VERDE:", 25, 35);
                ssd1306_draw_string(ssd, "Desligado", 35, 45);
                 // Envia mensagem para o Serial Monitor
            printf("O LED VERDE foi DESLIGADO.\n");
            }
            ssd1306_send_data(ssd);
        }
    } else {
        button_a_pressed = false;
    }

    // === Botão B: LED Azul ===
    if (!gpio_get(BUTTON_B)) {
        if (!button_b_pressed && (current_time_ms - last_button_b_press_time) > debounce_delay) {
            button_b_pressed = true;
            led_b_state = !led_b_state;  // Alterna o estado do LED azul
            gpio_put(B_PIN, led_b_state);  // Atualiza o LED

            last_button_b_press_time = current_time_ms;

            // Atualiza o display
            display_static_message(ssd);
            if (led_b_state) {
                ssd1306_draw_string(ssd, "LED AZUL:", 25, 35);
                ssd1306_draw_string(ssd, "Ligado", 35, 45);
                 // Envia mensagem para o Serial Monitor
            printf("O LED AZUL foi LIGADO.\n");
            } else {
                ssd1306_draw_string(ssd, "LED AZUL:", 25, 35);
                ssd1306_draw_string(ssd, "Desligado", 35, 45);
                // Envia mensagem para o Serial Monitor
            printf("O LED AZUL foi DESLIGADO.\n");
            }
            ssd1306_send_data(ssd);
        }
    } else {
        button_b_pressed = false;
    }
}