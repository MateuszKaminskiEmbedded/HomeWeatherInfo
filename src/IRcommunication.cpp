

#include "IRcommunication.h"

#define TAG "HaierAC"

// Definicje pinów
#define IR_TX_PIN 4 //GPIO_NUM_4

// Definicje czasowe
#define T_HIGH_US 900
#define T_LOW_US 450
#define T_START_US 9000
#define T_STOP_US 4500

// Definicje ramek IR dla klimatyzacji Haier
#define FRAME_START 0x88
#define FRAME_STOP 0x8C
#define FRAME_DATA_LENGTH 7

// Dane ramek IR dla różnych trybów klimatyzacji Haier
const uint8_t FRAME_COOL[FRAME_DATA_LENGTH] = {0x02, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t FRAME_HEAT[FRAME_DATA_LENGTH] = {0x02, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t FRAME_FAN[FRAME_DATA_LENGTH] = {0x02, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t FRAME_DRY[FRAME_DATA_LENGTH] = {0x02, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x00};

// Inicjalizacja modułu RMT
void ir_init() {
    rmt_config_t config = RMT_DEFAULT_CONFIG_TX(GPIO_NUM_4, RMT_CHANNEL_0);
    rmt_config(&config);
    rmt_driver_install(config.channel, 0, 0);
}

// Wysyłanie pojedynczego bitu
void ir_send_bit(int bit) {
    rmt_item32_t item;
    item.level0 = 1;
    item.duration0 = bit ? T_HIGH_US : T_LOW_US;
    item.level1 = 0;
    item.duration1 = bit ? T_LOW_US : T_HIGH_US;
    rmt_write_items(RMT_CHANNEL_0, &item, 1, true);
}

// Wysyłanie pojedynczego bajtu
void ir_send_byte(uint8_t byte) {
    for (int i = 0; i < 8; i++) {
        ir_send_bit(byte & 0x80);
        byte <<= 1;
    }
}

// Wysyłanie ramki IR
void ir_send_frame(const uint8_t *frame, int length) {
    ir_send_byte(FRAME_START);
    for (int i = 0; i < length; i++) {
        ir_send_byte(frame[i]);
    }
    ir_send_byte(FRAME_STOP);
}

// Wysyłanie ramki IR dla trybu chłodzenia
void ir_send_cool_frame() {
    ir_send_frame(FRAME_COOL, FRAME_DATA_LENGTH);
}

// Wysyłanie ramki IR dla trybu ogrzewania
void ir_send_heat_frame() {
    ir_send_frame(FRAME_HEAT, FRAME_DATA_LENGTH);
}

// Wysyłanie ramki IR dla trybu wentylacji
void ir_send_fan_frame() {
    ir_send_frame(FRAME_FAN, FRAME_DATA_LENGTH);
}

// Wysyłanie ramki IR dla trybu osuszania
void ir_send_dry_frame() {
    ir_send_frame(FRAME_DRY, FRAME_DATA_LENGTH);
}