# QtCryptoHash

**QtCryptoHash** is a Qt C++ library providing a way to calculate some cryptographic hashes not supported by the *QCryptographicHash* class of the Qt library.

[![](http://img.shields.io/badge/version-v0.1.0-blue.png?style=flat)](https://github.com/rikyoz/mrhash/releases/latest)
![](https://img.shields.io/badge/platform-Windows%20|%20Linux%20|%20Mac-red.png?style=flat)
![](http://img.shields.io/badge/architecture-x86%20|%20x64-yellow.png?style=flat)
[![](http://img.shields.io/badge/license-GNU%20GPL%20v2-lightgrey.png?style=flat)](/LICENSE)

## Basic Usage
The interface of this library is the same of the [QCryptographicHash](http://doc.qt.io/qt-5/qcryptographichash.html) class, renamed *QCryptoHash*. QtCryptoHash supports both dynamic and static linking.

### String Hash Calculation
~~~~~~~~~~~~~{.cpp}
#include "qcryptohash.hpp"
...
QByteArray stringHash = QCryptoHash::hash( "abc", QCryptoHash::TIGER );
qInfo() << stringHash.toHex(); //f258c1e88414ab2a527ab541ffc5b8bf935f7b951c132951
~~~~~~~~~~~~~
   
### File Hash Calculation
~~~~~~~~~~~~~{.cpp}
#include "qcryptohash.hpp"
...
QFile file( filename );
if ( file.open( QFile::ReadOnly ) ) {
	QCryptoHash cryptoHash( QCryptoHash::TIGER );
	while( !file.atEnd() ){
		cryptoHash.addData( file.read( 8192 ) );
	}
	QByteArray fileHash = cryptoHash.result();	
	qInfo() << fileHash.toHex(); //hash of 'filename'
}
~~~~~~~~~~~~~

## Building
*TODO*

### Dynamic Library
*TODO*

### Static Library
*TODO*

## Supported Algorithms
+ Tiger
+ RIPEMD-160
+ Whirlpool

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