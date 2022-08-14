#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "Adafruit_Pico_Si7021.h"
 
/*
int i2c_read_register(uint8_t reg, uint8_t * data)
{
    int ret;

    ret = i2c_write_blocking(i2c_default, SI7021_ADDRESS, &reg, 1, false);

    if (ret == PICO_ERROR_GENERIC)
    {
        return PICO_ERROR_GENERIC;
    }

    return i2c_read_blocking(i2c_default, SI7021_ADDRESS, data, 1, false);
}*/

#define SI7021_DEFAULT_ADDRESS 0x40

int main()
{
    stdio_init_all();

    Adafruit_Pico_Si7021 sensor = Adafruit_Pico_Si7021();

    if(!sensor.begin())
    {
        puts("Error, sensor not found!");
        while(1);
    }

    puts("Found model ");
    switch(sensor.getModel()) {
        case SI_Engineering_Samples:
        puts("SI engineering samples"); break;
        case SI_7013:
        puts("Si7013"); break;
        case SI_7020:
        puts("Si7020"); break;
        case SI_7021:
        puts("Si7021"); break;
        case SI_UNKNOWN:
        default:
        puts("Unknown");
    }

    while(1)
    {
        float temp = sensor.readTemperature();
        float hum = sensor.readHumidity();

        printf("Temp: %f, Hum: %f\n", temp, hum);
        
        sleep_ms(1000);
    }


/* 
    Adafruit_Pico_I2CDevice i2c(SI7021_DEFAULT_ADDRESS, i2c_default);

    i2c.begin();

    bool ret;

    uint8_t rxData = 0xE7;

    ret = i2c.write_then_read(&rxData, 1, &rxData, 1);

    printf("%d, %d\n", ret, rxData);

    i2c.end(); */

/* 
    setup_i2c();

    int ret;
    uint8_t rxData;

    ret = i2c_read_register(SI7021_READRHT_REG_CMD, &rxData);

    printf("%d, %d\n", ret, rxData); */

    return 0;
}