#ifndef IR_COMMUNICATION_H
#define IR_COMMUNICATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esp_log.h>
#include <driver/rmt.h>
//#include <hal/gpio_types.h>
//#include <rmt.h>

// Inicjalizacja modułu RMT
void ir_init();
// Wysyłanie pojedynczego bitu
void ir_send_bit(int bit);
// Wysyłanie pojedynczego bajtu
void ir_send_byte(uint8_t byte);
// Wysyłanie ramki IR
void ir_send_frame(const uint8_t *frame, int length);
// Wysyłanie ramki IR dla trybu chłodzenia
void ir_send_cool_frame();
// Wysyłanie ramki IR dla trybu ogrzewania
void ir_send_heat_frame();
// Wysyłanie ramki IR dla trybu wentylacji
void ir_send_fan_frame();
// Wysyłanie ramki IR dla trybu osuszania
void ir_send_dry_frame();

#endif /*IR_COMMUNICATION_H*/