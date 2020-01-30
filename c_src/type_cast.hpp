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
    struct type_caster<lot::GpioMode>
    {
    public:
        /**
         * This macro establishes the name 'lot::GpioMode' in
         * function signatures and declares a local variable
         * 'value' of type lot::GpioMode
         */
        PYBIND11_TYPE_CASTER( lot::GpioMode, _( "lot::GpioMode" ) );

        /**
         * Conversion part 1 (Python->C++): convert a PyObject into
         * a lot::GpioMode instance or return false upon failure.
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
            /* Now try to convert into a C++ lot::GpioMode */
            value = static_cast<lot::GpioMode>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            /* Ensure return code was OK (to avoid out-of-range errors etc) */
            return !( value == -1 && !PyErr_Occurred() );
        }

        /**
         * Conversion part 2 (C++ -> Python): convert an lot::GpioMode
         * instance into a Python object. The second and third arguments
         * are used to indicate the return value policy and parent object
         * (for ``return_value_policy::reference_internal``) and are
         * generally ignored by implicit casters.
         */
        static handle cast( lot::GpioMode src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::PUDMode>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::PUDMode, _( "lot::PUDMode" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::PUDMode>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::PUDMode src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::BitOrder>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::BitOrder, _( "lot::BitOrder" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::BitOrder>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::BitOrder src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::UartMode>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::UartMode, _( "lot::UartMode" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::UartMode>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::UartMode src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::SpiMode>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::SpiMode, _( "lot::SpiMode" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::SpiMode>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::SpiMode src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };

    template<>
    struct type_caster<lot::LogLevel>
    {
    public:
        PYBIND11_TYPE_CASTER( lot::LogLevel, _( "lot::LogLevel" ) );
        bool load( handle src, bool )
        {
            PyObject *source = src.ptr();
            PyObject *tmp    = PyNumber_Long( source );
            if( !tmp )
                return false;
            value = static_cast<lot::LogLevel>( PyLong_AsLong( tmp ) );
            Py_DECREF( tmp );
            return !( value == -1 && !PyErr_Occurred() );
        }

        static handle cast( lot::LogLevel src,
                            return_value_policy /* policy */,
                            handle /* parent */ )
        {
            return PyLong_FromLong( static_cast<int>( src ) );
        }
    };
}    // namespace detail
}    // namespace pybind11