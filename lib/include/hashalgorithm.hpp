/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2015 by Riccardo Ostani                                 *
 *   email: rik20@live.it                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2        *
 *   as published by the Free Software Foundation.                         *
 *                                                                         *
 ***************************************************************************/

#ifndef HASHALGORITHM_HPP
#define HASHALGORITHM_HPP

#include <cstdint>

typedef uint8_t	byte;

class HashAlgorithm {
    public:
        virtual ~HashAlgorithm() {}

        virtual void init() = 0;
        virtual void write( const byte* inbuf, int inlen ) = 0;
        virtual byte* final() = 0;
        virtual unsigned int hash_length() const = 0;

    protected:
        HashAlgorithm() {}

};

#endif // HASHALGORITHM_HPP
