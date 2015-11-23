# QCryptoHash Class

The **QCryptoHash** class provides a way to generate cryptographic hashes. It can be used to generate cryptographic hashes of binary or text data.

Currently **Tiger-192**, **RipeMD-160** and **Whirlpool** are supported.

## List of all members

### Public Types
| Type | Name                                                                 |
|-----:|----------------------------------------------------------------------|
| enum | [Algorithm](#enum-qcryptohashalgorithm) { TIGER, RMD160, WHIRLPOOL } |

### Public Members
| Return Type | Name                                                                                              |
|------------:|---------------------------------------------------------------------------------------------------|
|             | [QCryptoHash](#qcryptohashqcryptohash-algorithm-method-)( Algorithm method )                      |
|             | [~QCryptoHash](#qcryptohashqcryptohash)()                                                         |
| void        | [addData](#void-qcryptohashadddata-const-char--data-int-length-)( const char * data, int length ) |
| void        | [addData](#void-qcryptohashadddata-const-qbytearray--data-)( const QByteArray & data )            |
| bool        | [addData](#bool-qcryptohashadddata-qiodevice--device-)( QIODevice * device )                      |
| void        | [reset](#void-qcryptohashreset)()                                                                 |
| QByteArray  | [result](#qbytearray-qcryptohashresult-const)() const                                             |

### Static Public Members
| Return Type | Name                                              |
|------------:|---------------------------------------------------|
| QByteArray  | [hash](#static-qbytearray-qcryptohashhash-const-qbytearray--data-algorithm-method-)( const QByteArray & data, Algorithm method ) |

## Member Type Documentation

#### enum QCryptoHash::Algorithm
| Constant               | Description                         |
|------------------------|-------------------------------------|
| QCryptoHash::TIGER     | Generate a Tiger-192 hash sum       |
| QCryptoHash::RMD160    | Generate a RipeMD-160 hash sum      |
| QCryptoHash::WHIRLPOOL | Generate a Whirlpool hash sum       |

## Member Function Documentation

#### QCryptoHash::QCryptoHash( [Algorithm](#enum-qcryptohashalgorithm) method )
Constructs an object that can be used to create a cryptographic hash from data using method.

<br/>
#### QCryptoHash::~QCryptoHash()
Destroys the object.

<br/>
#### void QCryptoHash::addData( const char * data, int length )
Adds the first length chars of data to the cryptographic hash.

<br/>
#### void QCryptoHash::addData( const <a href="http://doc.qt.io/qt-5/qbytearray.html" target="_blank">QByteArray</a> & data )
This function overloads addData().

<br/>
#### bool QCryptoHash::addData( <a href="http://doc.qt.io/qt-5/qiodevice.html" target="_blank">QIODevice</a> * device )
Reads the data from the open <a href="http://doc.qt.io/qt-5/qiodevice.html" target="_blank">QIODevice</a> device until it ends and hashes it. Returns true if reading was successful.

<br/>
#### void QCryptoHash::reset()
Resets the object.

<br/>
#### <a href="http://doc.qt.io/qt-5/qbytearray.html" target="_blank">QByteArray</a> QCryptoHash::result() const
Returns the final hash value.

<br/>
#### [static] <a href="http://doc.qt.io/qt-5/qbytearray.html" target="_blank">QByteArray</a> QCryptoHash::hash( const <a href="http://doc.qt.io/qt-5/qbytearray.html" target="_blank">QByteArray</a> & data, [Algorithm](#enum-qcryptohashalgorithm) method )
Returns the hash of data using method.