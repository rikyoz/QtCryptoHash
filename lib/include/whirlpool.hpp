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

#ifndef WHIRLPOOL_HPP
#define WHIRLPOOL_HPP

#include "hashalgorithm.hpp"

#include <QtGlobal>

#define WHIRLPOOL_DIGEST_SIZE 64
#define WHIRLPOOL_DIGEST_BITSIZE ( 8 * WHIRLPOOL_DIGEST_SIZE ) /* 512 */

#define WHIRLPOOL_BLOCK_SIZE 64
#define WHIRLPOOL_BLOCK_BITSIZE ( 8 * WHIRLPOOL_BLOCK_SIZE ) /* 512 */

#define WHIRLPOOL_SIZE 32
#define WHIRLPOOL_BITSIZE  ( 8 * WHIRLPOOL_SIZE ) /* 256 */

class Whirlpool : public HashAlgorithm {
        typedef struct whirlpool_ctx {
            uint8_t bitLength[ WHIRLPOOL_SIZE ];        /* global number of hashed bits (256-bit counter) */
            uint8_t buffer[ WHIRLPOOL_BLOCK_SIZE ];     /* buffer of data to hash */
            int bufferBits;                             /* current number of bits on the buffer */
            int bufferPos;                              /* current (possibly incomplete) byte slot on the buffer */
            uint64_t hash[ WHIRLPOOL_DIGEST_SIZE / 8 ]; /* the hashing state */
        } WHIRLPOOL_CONTEXT;

    public:
        Whirlpool();
        virtual ~Whirlpool();

        void init() Q_DECL_OVERRIDE;
        void write( const byte* data, int length ) Q_DECL_OVERRIDE;
        byte* final() Q_DECL_OVERRIDE;

        unsigned int hash_length() const Q_DECL_OVERRIDE { return WHIRLPOOL_DIGEST_SIZE; }

    protected:
        WHIRLPOOL_CONTEXT* context;

    private:
        void processBuffer();
};

#endif
