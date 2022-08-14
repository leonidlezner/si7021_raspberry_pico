#ifndef Adafruit_I2C_PICO_Device_h
#define Adafruit_I2C_PICO_Device_h

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

///< The class which defines how we will talk to this device over I2C
class Adafruit_Pico_I2CDevice {
public:
  Adafruit_Pico_I2CDevice(uint8_t addr, i2c_inst_t* i2c);

  bool begin(void);
  void end(void);

  bool read(uint8_t *buffer, size_t len, bool stop = true);

  bool write(const uint8_t *buffer, size_t len, bool stop = true);

  bool write_then_read(const uint8_t *write_buffer, size_t write_len,
                       uint8_t *read_buffer, size_t read_len,
                       bool stop = false);

private:
  i2c_inst_t* _i2c;
  uint8_t _addr;
  bool _begun;
};

#endif // Adafruit_I2C_PICO_Device_h