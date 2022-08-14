#include "Adafruit_Pico_I2CDevice.h"

Adafruit_Pico_I2CDevice::Adafruit_Pico_I2CDevice(uint8_t addr, i2c_inst_t* i2c) {
    _i2c = i2c;
    _addr = addr;
    _begun = false;
}

bool Adafruit_Pico_I2CDevice::begin(void)
{
    _begun = true;

    i2c_init(_i2c, 100 * 1000);

    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    return true;
}

void Adafruit_Pico_I2CDevice::end(void)
{
    i2c_deinit(_i2c);
    _begun = false;
}

bool Adafruit_Pico_I2CDevice::read(uint8_t *buffer, size_t len, bool stop)
{
    int ret = i2c_read_blocking(_i2c, _addr, buffer, len, !stop);

    if (ret == PICO_ERROR_GENERIC || ret != len)
    {
        return false;
    }

    return true;
}

bool Adafruit_Pico_I2CDevice::write(const uint8_t *buffer, size_t len, bool stop)
{
    int ret = i2c_write_blocking(_i2c, _addr, buffer, len, !stop);

    if (ret == PICO_ERROR_GENERIC || ret != len)
    {
        return false;
    }

    return true;
}

bool Adafruit_Pico_I2CDevice::write_then_read(const uint8_t *write_buffer, size_t write_len, uint8_t *read_buffer, size_t read_len, bool stop)
{
    if (!write(write_buffer, write_len, stop)) {
        return false;
    }

    return read(read_buffer, read_len);
}