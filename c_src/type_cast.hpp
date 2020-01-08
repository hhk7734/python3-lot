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

#pragma once

#include <pybind11/pybind11.h>
#include <lot/lot.h>

namespace pybind11
{
namespace detail
{
    template<>
    struct type_caster<lot::pin_mode_t>
    {
    public:
        /**
         * This macro establishes the name 'lot::pin_mode_t' in
         * function signatures and declares a local variable
         * 'value' of type lot::pin_mode_t
         */
        PYBIND11_TYPE_CASTER( lot::pin_mode_t, _( "lot::pin_mode_t" ) );

        /**
         * Conversion part 1 (Python->C++): convert a PyObject into
         * a lot::pin_mode_t instance or return false upon failure.
         * The second argument indicates whether implicit conversions
         * should be applied.
         */
        bool load( handle src, bool )
        {
            /* Extract PyObject from handle */
            PyObject *source = src.ptr();
            /* Try converting into a Python integer value */
            PyObject *tmp = PyNumber_Long( source );
            if( !tmp )
                return false;
            /* Now try to convert into a C++ lot::pin_mode_t */
            value = static_cast<lot::pin_mode_t>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            /* Ensure return code was OK (to avoid out-of-range errors etc) */
            return !( value == -1 && !PyErr_Occurred() );
        }

        /**
         * Conversion part 2 (C++ -> Python): convert an lot::pin_mode_t
         * instance into a Python object. The second and third arguments
         * are used to indicate the return value policy and parent object
         * (for ``return_value_policy::reference_internal``) and are
         * generally ignored by implicit casters.
         */
        static handle cast( lot::pin_mode_t src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::pud_mode_t>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::pud_mode_t, _( "lot::pud_mode_t" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::pud_mode_t>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::pud_mode_t src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::bit_order_t>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::bit_order_t, _( "lot::bit_order_t" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::bit_order_t>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::bit_order_t src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::uart_mode_t>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::uart_mode_t, _( "lot::uart_mode_t" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::uart_mode_t>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::uart_mode_t src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::spi_mode_t>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::spi_mode_t, _( "lot::spi_mode_t" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::spi_mode_t>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::spi_mode_t src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::log_level_t>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::log_level_t, _( "lot::log_level_t" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::log_level_t>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::log_level_t src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };
}    // namespace detail
}    // namespace pybind11