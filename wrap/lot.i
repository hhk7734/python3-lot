%module lot

%{
    #include <lot/lot.h>
    #include <lot/Spi.h>
    #include <lot/I2c.h>
    #include <lot/Uart.h>
    using namespace lot;
%}

%typemap(in) uint32_t = int;
%typemap(out) uint32_t = int;

/*
 * lot/lot-API/lot_def.h
 */
%typemap(in) lot_mode_t = int;
%typemap(out) lot_mode_t = int;
%typemap(in) pin_size_t = int;
%typemap(out) pin_size_t = int;
%typemap(in) pin_mode_t = int;
%typemap(out) pin_mode_t = int;
%typemap(in) pud_mode_t = int;
%typemap(out) pud_mode_t = int;
%typemap(in) pin_status_t = int;
%typemap(out) pin_status_t = int;
%typemap(in) bit_order_t = int;
%typemap(out) bit_order_t = int;

/*
 * lot/lot-API/ISpi.h
 */
%typemap(in) spi_mode_t = int;
%typemap(out) spi_mode_t = int;

/*
 * lot/lot-API/IUart.h
 */
%typemap(in) uart_mode_t = int;
%typemap(out) uart_mode_t = int;

%include <lot/lot-API/lot_gpio.h>
%include <lot/lot-API/lot_time.h>
%include <lot/Spi.h>
%include <lot/I2c.h>
%include <lot/Uart.h>

/*
 * Don't write code after this.
 */
typedef enum
{
    SPI_MODE0 = 0,
    SPI_MODE1,
    SPI_MODE2,
    SPI_MODE3
} spi_mode_t;

typedef enum
{
    UART_5N1 = 0,
                UART_6N1,   UART_7N1,   UART_8N1,
    UART_5N2,   UART_6N2,   UART_7N2,   UART_8N2,
    UART_5E1,   UART_6E1,   UART_7E1,   UART_8E1,
    UART_5E2,   UART_6E2,   UART_7E2,   UART_8E2,
    UART_5O1,   UART_6O1,   UART_7O1,   UART_8O1,
    UART_5O2,   UART_6O2,   UART_7O2,   UART_8O2,
    UART_5M1,   UART_6M1,   UART_7M1,   UART_8M1,
    UART_5M2,   UART_6M2,   UART_7M2,   UART_8M2,
    UART_5S1,   UART_6S1,   UART_7S1,   UART_8S1,
    UART_5S2,   UART_6S2,   UART_7S2,   UART_8S2
} uart_mode_t;

%include <lot/lot-API/lot_def.h>