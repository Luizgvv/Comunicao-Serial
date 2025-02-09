#include "inc/uart.h"


int main() {
    stdio_init_all();  // Inicializa o USB padrão para comunicação

    led_matrix_init(pio0, WS2812_PIN);

    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_t ssd;
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, ENDERECO, I2C_PORT);
    ssd1306_config(&ssd);
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

    setup_button_led();

    printf("Digite um número entre 0 e 9:\n");

    while (true) {
        usb_read_handler(&ssd);  // Lê via USB
        check_button(&ssd);
    }
}
