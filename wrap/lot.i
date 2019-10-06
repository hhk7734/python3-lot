%module lot

%{
    #include <lot/lot.h>
    #include <lot/Spi.h>
    #include <lot/I2c.h>
    #include <lot/Uart.h>
    using namespace lot;
%}


/*
 *  lot/lot-API/lot_def.h
 */
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

/*
 *  lot/lot-API/lot_gpio.h
 */
void init( lot_mode_t mode );
void set_pin_mode( pin_size_t pin, pin_mode_t mode );
pin_mode_t get_pin_mode( pin_size_t pin );
void set_pin_pull_up_down( pin_size_t pin, pud_mode_t pud );
pud_mode_t get_pin_pull_up_down( pin_size_t pin );
void set_pin_speed( pin_size_t pin, uint32_t speed );
uint32_t get_pin_speed( pin_size_t pin );
void set_pin_drive( pin_size_t pin, uint32_t drive );
uint32_t get_pin_drive( pin_size_t pin );
void digital_write( pin_size_t pin, pin_status_t status );
pin_status_t digital_read( pin_size_t pin );
void analog_write( pin_size_t pin, uint32_t value );
uint32_t analog_read( pin_size_t pin );