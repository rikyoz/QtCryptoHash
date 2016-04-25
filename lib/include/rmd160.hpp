/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2015 by Riccardo Ostani                                 *
 *   email: rik20@live.it                                                  *
 *                                                                         *
 *   copyright (C) 2004 by Michael Buesch                                  *
 *   email: mbuesch@freenet.de                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2        *
 *   as published by the Free Software Foundation.                         *
 *                                                                         *
 ***************************************************************************/

#ifndef RMD160_HPP
#define RMD160_HPP

#include "hashalgorithm.hpp"

#include <QtGlobal>

#define RMD160_HASHLEN_BYTE	(160 / 8)

class Rmd160 : public HashAlgorithm {
        struct RMD160_CONTEXT {
            uint32_t  h0, h1, h2, h3, h4;
            uint32_t  nblocks;
            byte buf[64];
            int  count;
        };

    public:
        Rmd160();
        virtual ~Rmd160();

        void init() Q_DECL_OVERRIDE;
        void write( const byte* inbuf, int inlen ) Q_DECL_OVERRIDE;
        byte* final() Q_DECL_OVERRIDE;

        int hash_length() const Q_DECL_OVERRIDE { return RMD160_HASHLEN_BYTE; }

    protected:
        RMD160_CONTEXT* context;

    private:
        void burn_stack( int bytes );
        void transform( const byte* data );
};

#endif
