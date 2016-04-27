The **QCryptoHash** class provides a way to generate cryptographic hashes. 
It can be used to generate cryptographic hashes of binary or text data.

 Currently **Tiger-192**, **RipeMD-160** and **Whirlpool** are supported. 

~~~~{.cpp}
#include "qcryptohash.hpp"
~~~~

## List of all members

### Public Types
| Type | Name |
|-----:|------|
| enum | [Algorithm](#enum-algorithm) { TIGER, RMD160, WHIRLPOOL } |

### Public Members
| Return type | Name     |
|------------:|----------|
|  | [QCryptoHash](#qcryptohashqcryptohash-algorithm-method-)( Algorithm method ) |
|  | [~QCryptoHash](#qcryptohashqcryptohash)() |
| void | [reset](#void-qcryptohashreset)() |
| void | [addData](#void-qcryptohashadddata-const-char-data-int-length-)( const char *data, int length ) |
| void | [addData](#void-qcryptohashadddata-const-qbytearray-data-)( const QByteArray &data ) |
| bool | [addData](#bool-qcryptohashadddata-qiodevice-device-)( QIODevice *device ) |
| QByteArray | [result](#qbytearray-qcryptohashresult-const)() const  |

### Static Public Members
| Return type | Name     |
|------------:|----------|
| QByteArray | [hash](#static-qbytearray-qcryptohashhash-const-qbytearray-data-algorithm-method-)( const QByteArray &data, Algorithm method ) |


## Member Type Documentation

#### enum Algorithm

The Algorithm enum specifies the hashing algorithms supported by QCryptoHash.

| Constant | Value | Description |
|----------|-------|-------------|
| QCryptoHash::TIGER | 0 | Generate a Tiger-192 hash sum. |
| QCryptoHash::RMD160 | 1 | Generate a RipeMD-160 hash sum. |
| QCryptoHash::WHIRLPOOL | 2 | Generate a Whirlpool hash sum. |

<br/>

## Member Function Documentation

####  [QCryptoHash](./QCryptoHash)::[QCryptoHash](./QCryptoHash)( [Algorithm](./[QCryptoHash](./QCryptoHash)) method )
Constructs an object that can be used to create a cryptographic hash from data using *method*.

<br/>
####  [QCryptoHash](./QCryptoHash)::~[QCryptoHash](./QCryptoHash)()
Destroys the object.

<br/>
#### void [QCryptoHash](./QCryptoHash)::reset()
Resets the object.

<br/>
#### void [QCryptoHash](./QCryptoHash)::addData( const char *data, int length )
Adds the first *length* chars of *data* to the cryptographic hash.

<br/>
#### void [QCryptoHash](./QCryptoHash)::addData( const <a href="https://doc.qt.io/qt-5/qbytearray.html" target="_blank">QByteArray</a> &data )
Adds the bytes of *data* to the cryptographic hash.

<br/>
#### bool [QCryptoHash](./QCryptoHash)::addData( <a href="https://doc.qt.io/qt-5/qiodevice.html" target="_blank">QIODevice</a> *device )
Reads the data from the open QIODevice *device* until it ends and hashes it.

Returns true if reading was successful. 

<br/>
#### QByteArray [QCryptoHash](./QCryptoHash)::result() const 
Returns the final hash value. 

<br/>
#### [static] <a href="https://doc.qt.io/qt-5/qbytearray.html" target="_blank">QByteArray</a> [QCryptoHash](./QCryptoHash)::hash( const <a href="https://doc.qt.io/qt-5/qbytearray.html" target="_blank">QByteArray</a> &data, [Algorithm](./[QCryptoHash](./QCryptoHash)) method )
Returns the hash of *data* using *method*. 

<br/>
