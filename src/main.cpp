#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "Adafruit_Pico/Adafruit_Pico_Si7021.h"
 
int main()
{
    stdio_init_all();

    Adafruit_Pico_Si7021 sensor = Adafruit_Pico_Si7021();

    if(!sensor.begin())
    {
        puts("Error, sensor not found!");
        while(1);
    }

    puts("Found model");

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
}