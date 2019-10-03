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
%typemap(in) pin_status_t = int;

%include<lot/lot-API/lot_gpio.h>
%include<lot/lot-API/lot_def.h>
