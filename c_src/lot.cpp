/*
 * MIT License
 * 
 * Copyright (c) 2020 Hyeonki Hong <hhk7734@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <pybind11/pybind11.h>
#include <lot/lot.h>
#include <lot/Gpio.h>
#include <lot/Uart.h>
#include <lot/I2c.h>
#include <lot/Spi.h>

#include "type_cast.hpp"

namespace py = pybind11;

PYBIND11_MODULE( _lot, m )
{
    /*
     * lot/lot-API/lotdef.h
     */
    m.attr( "UNUSED" ) = -1;

    m.attr( "ALT0" ) = lot::ALT0;
    m.attr( "ALT1" ) = lot::ALT1;
    m.attr( "ALT2" ) = lot::ALT2;
    m.attr( "ALT3" ) = lot::ALT3;
    m.attr( "ALT4" ) = lot::ALT4;
    m.attr( "ALT5" ) = lot::ALT5;
    m.attr( "ALT6" ) = lot::ALT6;
    m.attr( "ALT7" ) = lot::ALT7;
    m.attr( "DIN" )  = lot::DIN;
    m.attr( "DOUT" ) = lot::DOUT;
    m.attr( "AIN" )  = lot::AIN;
    m.attr( "AOUT" ) = lot::AOUT;
    m.attr( "PWM" )  = lot::PWM;

    m.attr( "PULL_OFF" )  = lot::PULL_OFF;
    m.attr( "PULL_DOWN" ) = lot::PULL_DOWN;
    m.attr( "PULL_UP" )   = lot::PULL_UP;

    m.attr( "LOW" )  = static_cast<int>( lot::LOW );
    m.attr( "HIGH" ) = static_cast<int>( lot::HIGH );

    m.attr( "LSB_FIRST" ) = lot::LSB_FIRST;
    m.attr( "MSB_FIRST" ) = lot::MSB_FIRST;

    m.attr( "U5N1" ) = lot::U5N1;
    m.attr( "U6N1" ) = lot::U6N1;
    m.attr( "U7N1" ) = lot::U7N1;
    m.attr( "U8N1" ) = lot::U8N1;
    m.attr( "U5N2" ) = lot::U5N2;
    m.attr( "U6N2" ) = lot::U6N2;
    m.attr( "U7N2" ) = lot::U7N2;
    m.attr( "U8N2" ) = lot::U8N2;
    m.attr( "U5E1" ) = lot::U5E1;
    m.attr( "U6E1" ) = lot::U6E1;
    m.attr( "U7E1" ) = lot::U7E1;
    m.attr( "U8E1" ) = lot::U8E1;
    m.attr( "U5E2" ) = lot::U5E2;
    m.attr( "U6E2" ) = lot::U6E2;
    m.attr( "U7E2" ) = lot::U7E2;
    m.attr( "U8E2" ) = lot::U8E2;
    m.attr( "U5O1" ) = lot::U5O1;
    m.attr( "U6O1" ) = lot::U6O1;
    m.attr( "U7O1" ) = lot::U7O1;
    m.attr( "U8O1" ) = lot::U8O1;
    m.attr( "U5O2" ) = lot::U5O2;
    m.attr( "U6O2" ) = lot::U6O2;
    m.attr( "U7O2" ) = lot::U7O2;
    m.attr( "U8O2" ) = lot::U8O2;
    m.attr( "U5M1" ) = lot::U5M1;
    m.attr( "U6M1" ) = lot::U6M1;
    m.attr( "U7M1" ) = lot::U7M1;
    m.attr( "U8M1" ) = lot::U8M1;
    m.attr( "U5M2" ) = lot::U5M2;
    m.attr( "U6M2" ) = lot::U6M2;
    m.attr( "U7M2" ) = lot::U7M2;
    m.attr( "U8M2" ) = lot::U8M2;
    m.attr( "U5S1" ) = lot::U5S1;
    m.attr( "U6S1" ) = lot::U6S1;
    m.attr( "U7S1" ) = lot::U7S1;
    m.attr( "U8S1" ) = lot::U8S1;
    m.attr( "U5S2" ) = lot::U5S2;
    m.attr( "U6S2" ) = lot::U6S2;
    m.attr( "U7S2" ) = lot::U7S2;
    m.attr( "U8S2" ) = lot::U8S2;

    m.attr( "MODE0" ) = lot::MODE0;
    m.attr( "MODE1" ) = lot::MODE1;
    m.attr( "MODE2" ) = lot::MODE2;
    m.attr( "MODE3" ) = lot::MODE3;

    m.attr( "DEBUG" )   = lot::DEBUG;
    m.attr( "INFO" )    = lot::INFO;
    m.attr( "WARNING" ) = lot::WARNING;
    m.attr( "ERROR" )   = lot::ERROR;

    /*
     * lot/lot-API/lot_time.h
     */
    m.def( "init_time",
           &lot::init_time,
           "/**\n"
           " * @brief Initializes registers or variables about time.\n"
           " */" );
    m.def( "delay_us",
           &lot::delay_us,
           py::arg( "us" ),
           "/**\n"
           " * @brief Pauses program for the amount of time in microseconds.\n"
           " * @param us Minimum pause time in microseconds.\n"
           " */" );
    m.def( "delay_ms",
           &lot::delay_ms,
           py::arg( "ms" ),
           "/**\n"
           " * @brief Pauses program for the amount of time in milliseconds.\n"
           " * @param us Minimum pause time in milliseconds.\n"
           " */" );
    m.def( "micros",
           &lot::micros,
           "/**\n"
           " * @brief Returns the elapsed time in microseconds\n"
           " *      since program called init_time().\n"
           " * @return The number of microseconds.\n"
           " */" );
    m.def( "millis",
           &lot::millis,
           "/**\n"
           " * @brief Returns the elapsed time in milliseconds\n"
           " *      since program called init_time().\n"
           " * @return The number of microseconds.\n"
           " */" );

    /*
     * lot/Gpio.h
     */
    py::class_<lot::Gpio>( m, "Gpio" )
        .def( py::init<int>(),
              py::arg( "pin" ),
              "/**\n"
              " * @brief Creates an instance of Gpio class and initializes "
              "GPIO.\n"
              " * @param pin\n"
              " */" )
        .def( "mode",
              ( void ( lot::Gpio::* )( lot::pin_mode_t ) ) & lot::Gpio::mode,
              py::arg( "pin_mode" ),
              "/**\n"
              " * @brief Sets pin mode.\n"
              " * @param pin_mode\n"
              " *      This parameter can be a value of @ref pin_mode_t.\n"
              " */" )
        .def( "mode",
              ( lot::pin_mode_t( lot::Gpio::* )( void ) ) & lot::Gpio::mode,
              "/**\n"
              " * @brief Gets pin mode.\n"
              " * @return Pin mode.\n"
              " *      This return value can be a value of @ref pin_mode_t.\n"
              " */" )
        .def( "pull_up_down",
              ( void ( lot::Gpio::* )( lot::pud_mode_t ) )
                  & lot::Gpio::pull_up_down,
              py::arg( "pud" ),
              "/**\n"
              " * @brief Sets pull up/down/off.\n"
              " * @param pud\n"
              " *      This parameter can be a value of @ref pud_mode_t.\n"
              " */" )
        .def( "pull_up_down",
              ( lot::pud_mode_t( lot::Gpio::* )( void ) )
                  & lot::Gpio::pull_up_down,
              "/**\n"
              " * @brief Gets pull up/down/off.\n"
              " * @return Pull up/down/off mode. \n"
              " *      This return value can be a value of @ref pud_mode_t.\n"
              " */" )
        .def( "drive",
              ( void ( lot::Gpio::* )( uint32_t ) ) & lot::Gpio::drive,
              py::arg( "pin_drive" ),
              "/**\n"
              " * @brief Sets pin drive strength.\n"
              " * @param pin_drive\n"
              " */" )
        .def( "drive",
              ( uint32_t( lot::Gpio::* )( void ) ) & lot::Gpio::drive,
              "/**\n"
              " * @brief Gets pin drive strength.\n"
              " * @return Pin drive.\n"
              " */" )
        .def(
            "digital",
            ( void ( lot::Gpio::* )( int ) ) & lot::Gpio::digital,
            py::arg( "status" ),
            "/**\n"
            " * @brief Sets digital output status.\n"
            " * @param status\n"
            " *      This parameter can be @ref LOW (0) or @ref HIGH (not 0).\n"
            " */" )
        .def( "digital",
              ( int ( lot::Gpio::* )( void ) ) & lot::Gpio::digital,
              "/**\n"
              " * @brief Gets digital output status.\n"
              " * @return Digital output status.\n"
              " *      This return value can be @ref LOW (0) or @ref HIGH (not "
              "0).\n"
              " */" )
        .def( "on",
              ( void ( lot::Gpio::* )( void ) ) & lot::Gpio::on,
              "/**\n"
              " * @brief Sets digital output to @ref HIGH.\n"
              " */" )
        .def( "off",
              ( void ( lot::Gpio::* )( void ) ) & lot::Gpio::off,
              "/**\n"
              " * @brief Sets digital output to @ref LOW.\n"
              " */" )
        .def( "toggle",
              ( int ( lot::Gpio::* )( void ) ) & lot::Gpio::toggle,
              "/**\n"
              " * @brief Toggle digital output.\n"
              " * @return Digital output status. \n"
              " *      This return value can be @ref LOW (0) or @ref HIGH (not "
              "0).\n"
              " */" )
        .def( "analog",
              ( void ( lot::Gpio::* )( int ) ) & lot::Gpio::analog,
              py::arg( "value" ),
              "/**\n"
              " * @brief Sets analog output value.\n"
              " * @param value\n"
              " */" )
        .def( "analog",
              ( int ( lot::Gpio::* )( void ) ) & lot::Gpio::analog,
              "/**\n"
              " * @brief Gets analog output value.\n"
              " * @return Analog output value.\n"
              " */" );

    /*
     * lot/Uart.h
     */
    py::class_<lot::Uart>( m, "Uart" )
        .def( py::init<const char *>() )
        .def( py::init<uint16_t>() )
        .def( "init",
              &lot::Uart::init,
              py::arg( "baud_rate" ) = 115200,
              py::arg( "uart_mode" ) = lot::U8N1 )
        .def( "baudrate", &lot::Uart::baudrate )
        .def( "mode", &lot::Uart::mode )
        .def( "available", &lot::Uart::available )
        .def( "transmit",
              []( lot::Uart &self, py::bytes data ) {
                  std::string str = data;
                  if( str.size() > 0 )
                  {
                      self.transmit( reinterpret_cast<uint8_t *>(
                                         const_cast<char *>( str.c_str() ) ),
                                     str.size() );
                  }
              } )
        .def( "receive", []( lot::Uart &self ) {
            uint16_t size = self.available();
            if( size > 0 )
            {
                uint8_t *buf = new uint8_t[size];
                self.receive( buf, size );
                py::bytes data( reinterpret_cast<const char *>( buf ), size );
                delete buf;
                return data;
            }
            return py::bytes( "" );
        } );

    /*
     * lot/I2c.h
     */
    py::class_<lot::I2c>( m, "I2c" )
        .def( py::init<uint16_t>() )
        .def( py::init<const char *>() )
        .def( "init", &lot::I2c::init, py::arg( "i2c_clock" ) = 400000 )
        .def( "clock", &lot::I2c::clock )
        .def( "transmit",
              []( lot::I2c &self, int slave_address, py::bytes data ) {
                  std::string str = data;
                  if( str.size() > 0 )
                  {
                      self.transmit( static_cast<uint8_t>( slave_address ),
                                     reinterpret_cast<uint8_t *>(
                                         const_cast<char *>( str.c_str() ) ),
                                     str.size() );
                  }
              } )
        .def(
            "receive",
            []( lot::I2c &self, int slave_address, int size ) {
                if( size > 0 )
                {
                    uint8_t *buf = new uint8_t[size];
                    self.receive(
                        static_cast<uint8_t>( slave_address ), buf, size );
                    py::bytes data( reinterpret_cast<const char *>( buf ),
                                    size );
                    delete buf;
                    return data;
                }
                return py::bytes( "" );
            },
            py::arg( "slave_address" ),
            py::arg( "size" ) = 1 )
        .def( "write_reg",
              []( lot::I2c &self,
                  int       slave_address,
                  int       register_address,
                  py::bytes data ) {
                  std::string str = data;
                  if( str.size() > 0 )
                  {
                      self.write_reg( static_cast<uint8_t>( slave_address ),
                                      static_cast<uint8_t>( register_address ),
                                      reinterpret_cast<uint8_t *>(
                                          const_cast<char *>( str.c_str() ) ),
                                      str.size() );
                  }
              } )
        .def(
            "read_reg",
            []( lot::I2c &self,
                int       slave_address,
                int       register_address,
                int       size ) {
                if( size > 0 )
                {
                    uint8_t *buf = new uint8_t[size];
                    self.read_reg( static_cast<uint8_t>( slave_address ),
                                   static_cast<uint8_t>( register_address ),
                                   buf,
                                   size );
                    py::bytes data( reinterpret_cast<const char *>( buf ),
                                    size );
                    delete buf;
                    return data;
                }
                return py::bytes( "" );
            },
            py::arg( "slave_address" ),
            py::arg( "register_address" ),
            py::arg( "size" ) = 1 );

    /*
     * lot/Spi.h
     */
    py::class_<lot::Spi>( m, "Spi" )
        .def( py::init<uint16_t, uint16_t>() )
        .def( py::init<const char *>() )
        .def( "init",
              &lot::Spi::init,
              py::arg( "spi_clock" )     = 1000000,
              py::arg( "spi_mode" )      = lot::MODE0,
              py::arg( "spi_bit_order" ) = lot::MSB_FIRST )
        .def( "clock", &lot::Spi::clock )
        .def( "mode", &lot::Spi::mode )
        .def( "bit_order", &lot::Spi::bit_order )
        .def( "transceive",
              []( lot::Spi &self, py::bytes tx_data ) {
                  std::string str  = tx_data;
                  int         size = str.size();
                  if( size > 0 )
                  {
                      uint8_t *buf = new uint8_t[size];
                      self.transceive( reinterpret_cast<uint8_t *>(
                                           const_cast<char *>( str.c_str() ) ),
                                       buf,
                                       size );
                      py::bytes rx_data( reinterpret_cast<const char *>( buf ),
                                         size );
                      delete buf;
                      return rx_data;
                  }
                  return py::bytes( "" );
              } )
        .def( "transceive",
              []( lot::Spi &self, int cs_pin, py::bytes tx_data ) {
                  std::string str  = tx_data;
                  int         size = str.size();
                  if( size > 0 )
                  {
                      uint8_t *buf = new uint8_t[size];
                      self.transceive( cs_pin,
                                       reinterpret_cast<uint8_t *>(
                                           const_cast<char *>( str.c_str() ) ),
                                       buf,
                                       size );
                      py::bytes rx_data( reinterpret_cast<const char *>( buf ),
                                         size );
                      delete buf;
                      return rx_data;
                  }
                  return py::bytes( "" );
              } )
        .def( "write_reg",
              []( lot::Spi &self, int register_address, py::bytes data ) {
                  std::string str = data;
                  if( str.size() > 0 )
                  {
                      self.write_reg( static_cast<uint8_t>( register_address ),
                                      reinterpret_cast<uint8_t *>(
                                          const_cast<char *>( str.c_str() ) ),
                                      str.size() );
                  }
              } )
        .def( "write_reg",
              []( lot::Spi &self,
                  int       cs_pin,
                  int       register_address,
                  py::bytes data ) {
                  std::string str = data;
                  if( str.size() > 0 )
                  {
                      self.write_reg( cs_pin,
                                      static_cast<uint8_t>( register_address ),
                                      reinterpret_cast<uint8_t *>(
                                          const_cast<char *>( str.c_str() ) ),
                                      str.size() );
                  }
              } )
        .def(
            "read_reg",
            []( lot::Spi &self, int register_address, int size ) {
                if( size > 0 )
                {
                    uint8_t *buf = new uint8_t[size];
                    self.read_reg(
                        static_cast<uint8_t>( register_address ), buf, size );
                    py::bytes data( reinterpret_cast<const char *>( buf ),
                                    size );
                    delete buf;
                    return data;
                }
                return py::bytes( "" );
            },
            py::arg( "register_address" ),
            py::arg( "size" ) = 1 )
        .def(
            "read_reg",
            []( lot::Spi &self, int cs_pin, int register_address, int size ) {
                if( size > 0 )
                {
                    uint8_t *buf = new uint8_t[size];
                    self.read_reg( cs_pin,
                                   static_cast<uint8_t>( register_address ),
                                   buf,
                                   size );
                    py::bytes data( reinterpret_cast<const char *>( buf ),
                                    size );
                    delete buf;
                    return data;
                }
                return py::bytes( "" );
            },
            py::arg( "cs_pin" ),
            py::arg( "register_address" ),
            py::arg( "size" ) = 1 );
}
