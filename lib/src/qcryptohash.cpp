/* QCryptoHash.cpp - The QCryptoHash class
 * Copyright (C) 2015 Riccardo Ostani <rik20@live.it>
 *
 * This file is part of QtCryptoHash library.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "qcryptohash.hpp"

#include "tiger.hpp"
#include "rmd160.hpp"
#include "whirlpool.hpp"

#include <stdexcept>

QCryptoHash::QCryptoHash( Algorithm method ) {
    switch ( method ) {
        case QCryptoHash::TIGER:
            hash_algorithm = new Tiger();
            break;
        case QCryptoHash::RMD160:
            hash_algorithm = new Rmd160();
            break;
        case QCryptoHash::WHIRLPOOL:
            hash_algorithm = new Whirlpool();
            break;
        default:
            throw std::invalid_argument( "Algorithm not supported" );
    }
    reset();
}

QCryptoHash::~QCryptoHash() {
    if ( !hash_algorithm ) {
        delete hash_algorithm;
        hash_algorithm = NULL;
    }
}

void QCryptoHash::reset() {
    hash_algorithm->init();
}

void QCryptoHash::addData( const char* data, int length ) {
    hash_algorithm->write( reinterpret_cast< const byte* >( data ), length );
}

void QCryptoHash::addData( const QByteArray &data ) {
    addData( data.constData(), data.length() );
}

bool QCryptoHash::addData( QIODevice* device ) {
    if ( !device->isReadable() || !device->isOpen() )
        return false;

    char buffer[1024];
    int length;

    while ( ( length = device->read( buffer, sizeof( buffer ) ) ) > 0 )
        addData( buffer, length );

    return device->atEnd();
}

QByteArray QCryptoHash::result() const {
    byte* hash_array = hash_algorithm->final();
    return QByteArray( reinterpret_cast<char*>( hash_array ), hash_algorithm->hash_length() );
}

QByteArray QCryptoHash::hash( const QByteArray &data, QCryptoHash::Algorithm method ) {
    QCryptoHash hash( method );
    hash.addData( data );
    return hash.result();
}
