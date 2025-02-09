# Projeto de Comunicação Serial com RP2040 - Unidade 4 | Capítulo 6

## Descrição do Projeto

Este projeto foi desenvolvido para consolidar os conceitos sobre o uso de interfaces de comunicação serial no microcontrolador RP2040, com foco nas interfaces UART e I2C. Através deste projeto, exploramos a manipulação de LEDs, botões e display, enquanto implementamos interrupções, tratamento de debouncing e controle de dispositivos via UART.

### Componentes Utilizados:
- **Matriz 5x5 de LEDs (WS2812)** conectada à GPIO 7.
- **LED RGB** conectado às GPIOs 11, 12 e 13.
- **Botão A** conectado à GPIO 5.
- **Botão B** conectado à GPIO 6.
- **Display SSD1306** conectado via I2C (GPIO 14 e GPIO 15).

### Funcionalidades Implementadas:
1. **Modificação da Biblioteca font.h**:
   - Adição de caracteres minúsculos à biblioteca font.h para exibição no display SSD1306.

2. **Entrada de Caracteres via PC**:
   - Utilização do Serial Monitor do VS Code para digitar um caractere de cada vez, que é exibido no display SSD1306.
   - Quando um número de 0 a 9 for digitado, um símbolo correspondente ao número é exibido na matriz 5x5 de LEDs.

3. **Interação com o Botão A**:
   - Ao pressionar o botão A, o estado do LED RGB Verde alterna entre ligado e desligado.
   - Uma mensagem informativa sobre o estado do LED é exibida no display SSD1306.
   - Um texto descritivo sobre a operação é enviado ao Serial Monitor.

4. **Interação com o Botão B**:
   - Ao pressionar o botão B, o estado do LED RGB Azul alterna entre ligado e desligado.
   - Uma mensagem informativa sobre o estado do LED é exibida no display SSD1306.
   - Um texto descritivo sobre a operação é enviado ao Serial Monitor.

### Requisitos Técnicos:
- **Uso de interrupções (IRQ)** para funcionalidades relacionadas aos botões.
- **Debouncing** implementado via software para garantir um acionamento de botões preciso.
- **Controle de LEDs** (comuns e WS2812) para demonstração do domínio sobre diferentes tipos de controle de LEDs.
- **Uso do Display SSD1306** (128x64), incluindo a modificação da fonte e o controle via I2C.
- **Envio de dados via UART**, mostrando o entendimento sobre a comunicação serial.
- **Código bem estruturado e comentado** para fácil compreensão.

## Instruções de Uso:

1. **Configuração de Hardware**:
   - Conecte a Matriz 5x5 de LEDs à GPIO 7.
   - Conecte o LED RGB aos pinos GPIO 11, 12 e 13.
   - Conecte o Botão A à GPIO 5 e o Botão B à GPIO 6.
   - Conecte o Display SSD1306 aos pinos GPIO 14 e GPIO 15 via I2C.

2. **Compilação e Execução**:
   - Certifique-se de que o ambiente de desenvolvimento esteja configurado corretamente, com o SDK do Raspberry Pi Pico.
   - Compile e faça o upload do código para a placa BitDogLab.

3. **Interação**:
   - Abra o Serial Monitor do VS Code para enviar caracteres e interagir com o sistema.
   - Use os botões A e B para alternar o estado dos LEDs RGB.

## Vídeo de Demonstração:

[![Demonstração na Placa](https://img.youtube.com/vi/kE9x9r7A8eQ/0.jpg)](https://youtu.be/kE9x9r7A8eQ)
- [Link para o vídeo de demonstração](https://youtu.be/kE9x9r7A8eQ) 

## Considerações Finais:
Este projeto oferece uma excelente oportunidade para aplicar e consolidar os conhecimentos adquiridos sobre comunicação serial, manipulação de LEDs e displays, interrupções, e uso de botões em sistemas embarcados.


