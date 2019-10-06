%module lot

%{
    #include <lot/lot.h>
    #include <lot/Spi.h>
    #include <lot/I2c.h>
    #include <lot/Uart.h>
    using namespace lot;
%}

%typemap(in) lot_mode_t = int;
%typemap(in) pin_size_t = int;
%typemap(in) pin_mode_t = int;
%typemap(in) pud_mode_t = int;
%typemap(in) pin_status_t = int;
%typemap(in) bit_order_t = int;

%typemap(out) lot_mode_t = int;
%typemap(out) pin_size_t = int;
%typemap(out) pin_mode_t = int;
%typemap(out) pud_mode_t = int;
%typemap(out) pin_status_t = int;
%typemap(out) bit_order_t = int;

%include <lot/lot-API/lot_gpio.h>

/*
 * Don't write code after this.
 */
%include <lot/lot-API/lot_def.h>