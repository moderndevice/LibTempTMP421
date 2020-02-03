/*
  LibTemperature - A Temperature Sensor Library for Arduino.

  Supported Temperature Sensor modules:
    TMP421-Breakout Module - http://www.moderndevice.com/products/tmp421-temperature-sensor

  Created by Christopher Ladden at Modern Device on December 2009.
  Modified Paul Badger 2012, 2020

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef LibTempTMP421_H
#define LibTempTMP421_H

#include <inttypes.h>

class LibTempTMP421
{
  private:
    uint8_t getRegisterValue(void);
    void setPtrLoc(uint8_t ptrLoc);

  public:
    uint8_t I2C_address;
    LibTempTMP421(uint8_t TempSensorType,uint8_t I2Caddress);
    void Init();
    float GetTemperature(void);
};

#endif
