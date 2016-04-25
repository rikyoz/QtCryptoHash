/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2015 by Riccardo Ostani                                    *
 *   email: rik20@live.it                                                  *
 *                                                                         *
 *   copyright (C) 2002, 2003, 2004 by Michael Buesch                      *
 *   email: mbuesch@freenet.de                                             *
 *                                                                         *
 *   tiger.c  -  The TIGER hash function                                   *
 *	 Copyright (C) 1998, 2001, 2002 Free Software Foundation, Inc.         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2        *
 *   as published by the Free Software Foundation.                         *
 *                                                                         *
 ***************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "hashalgorithm.hpp"

#include <QtGlobal>

#define TIGER_HASHLEN_BYTE (192 / 8)

class Tiger : public HashAlgorithm {
        struct TIGER_CONTEXT {
            uint64_t a, b, c;
            byte buf[64];
            int count;
            uint32_t nblocks;
        };

    public:
        Tiger();
        virtual ~Tiger();

        void init() Q_DECL_OVERRIDE;
        void write( const byte* inbuf, int inlen ) Q_DECL_OVERRIDE;
        byte* final() Q_DECL_OVERRIDE;

        int hash_length() const Q_DECL_OVERRIDE { return TIGER_HASHLEN_BYTE; }

    protected:
        TIGER_CONTEXT* context;

    private:
        Q_DISABLE_COPY( Tiger )

        void burn_stack( int bytes );
        void round( uint64_t* ra, uint64_t* rb, uint64_t* rc, uint64_t x, int mul );
        void pass( uint64_t* ra, uint64_t* rb, uint64_t* rc, uint64_t* x, int mul );
        void key_schedule( uint64_t* x );
        void transform( const byte* data );
};

#endif
