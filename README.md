# QtCryptoHash

**QtCryptoHash** is a Qt C++ library providing a way to calculate some cryptographic hashes not supported by the *QCryptographicHash* class of the Qt library.

[![](http://img.shields.io/badge/version-v0.1.0-blue.png?style=flat)](https://github.com/rikyoz/qtcryptohash/releases/latest)
![](https://img.shields.io/badge/platform-Windows%20|%20Linux%20|%20Mac%20OS%20X-red.png?style=flat)
![](http://img.shields.io/badge/architecture-x86%20|%20x64-yellow.png?style=flat)
[![](http://img.shields.io/badge/license-GNU%20GPL%20v2-lightgrey.png?style=flat)](/LICENSE)

## Features
+ Supports **Tiger-192**, **RipeMD-160** and **Whirlpool** algorithms
+ Simple interface, identical to the [QCryptographicHash](http://doc.qt.io/qt-5/qcryptographichash.html) class, but renamed [**QCryptoHash**](https://github.com/rikyoz/QtCryptoHash/wiki/API)
+ Works with **Qt 5.x**
+ Supports **MSVC**, **MinGW**, **GCC** and **Clang**

## Basic Usage

### String Hash Calculation
```cpp
#include "qcryptohash.hpp"
...
QByteArray stringHash = QCryptoHash::hash( "abc", QCryptoHash::TIGER );
qInfo() << stringHash.toHex(); //f258c1e88414ab2a527ab541ffc5b8bf935f7b951c132951
```

### File Hash Calculation
```cpp
#include "qcryptohash.hpp"
...
QFile file( filename );
if ( file.open( QFile::ReadOnly ) ) {
	QCryptoHash cryptoHash( QCryptoHash::RMD160 );
	while( !file.atEnd() ){
		cryptoHash.addData( file.read( 8192 ) );
	}
	QByteArray fileHash = cryptoHash.result();	
	qInfo() << fileHash.toHex(); //hash of 'filename' file content
}
```

For a complete description of the QCryptoHash API, see the relative [wiki](https://github.com/rikyoz/QtCryptoHash/wiki/API).

## Dependencies
QtCryptoHash needs only **QtCore** library to be linked to the program.

## Building
A complete guide to build this library is available [here](https://github.com/rikyoz/QtCryptoHash/wiki/Building).

## License (GPL v2)
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.