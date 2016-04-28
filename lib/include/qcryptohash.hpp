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

#ifndef QCRYPTOHASH_HPP
#define QCRYPTOHASH_HPP

#include <QByteArray>
#include <QIODevice>
#include <QtGlobal>

#ifdef QTCRYPTOHASH_STATIC
#define LIBSHARED_EXPORT
#elif defined(QTCRYPTOHASH_EXPORT)
#define LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#define LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

class HashAlgorithm;

/**
 * @brief The **QCryptoHash** class provides a way to generate cryptographic hashes.
 *
 * It can be used to generate cryptographic hashes of binary or text data.<br/>
 * Currently **Tiger-192**, **RipeMD-160** and **Whirlpool** are supported.
 */
class LIBSHARED_EXPORT QCryptoHash {
    public:
        /**
         * @brief The Algorithm enum specifies the hashing algorithms supported by QCryptoHash
         */
        enum Algorithm { TIGER, ///< Generate a Tiger-192 hash sum
                         RMD160, ///< Generate a RipeMD-160 hash sum
                         WHIRLPOOL ///< Generate a Whirlpool hash sum
                       };

        /**
         * @brief Constructs an object that can be used to create a cryptographic hash from data using @a method.
         * @param method The method/algorithm used to create the hash
         */
        explicit QCryptoHash( Algorithm method );

        /**
         * @brief Destroys the object.
         */
        ~QCryptoHash();

        /**
         * @brief Resets the object.
         */
        void reset();

        /**
         * @brief Adds the first @a length chars of @a data to the cryptographic hash.
         * @param data an array of chars to be added to the hash
         * @param length The number of chars to be added
         */
        void addData( const char* data, int length );

        /**
         * @brief Adds the bytes of @a data to the cryptographic hash
         * @param data a byte array to be added to the hash
         */
        void addData( const QByteArray &data );

        /**
         * @brief Reads the data from the open QIODevice @a device until it ends and hashes it.
         * @param device QIODevice to be read
         * @return true if reading was successful.
         */
        bool addData( QIODevice* device );

        /**
         * @return the final hash value.
         */
        QByteArray result() const;

        /**
         * @param data      the byte array to be hashed
         * @param method    the algorithm/method to be used to hash the data
         * @return the hash of @a data using @a method.
         */
        static QByteArray hash( const QByteArray &data, Algorithm method );

    private:
        Q_DISABLE_COPY( QCryptoHash )

        HashAlgorithm* hash_algorithm;
};

#endif // QCRYPTOHASH_HPP
