# QtCryptoHash [![Build Status](https://ci.appveyor.com/api/projects/status/bg4it7o8d5chbfvm?svg=true&passingText=build%20OK&pendingText=building...&failingText=build%20failed)](https://ci.appveyor.com/project/rikyoz/qtcryptohash)

**QtCryptoHash** is a Qt C++ library providing a way to calculate some of the cryptographic hashes not supported by the *QCryptographicHash* class from the Qt library.

[![](http://img.shields.io/badge/version-v0.1.1-blue.png?style=flat)](https://github.com/rikyoz/qtcryptohash/releases/latest)
![](http://img.shields.io/badge/compiler-MSVC%20|%20MinGW%20|%20GCC%20|%20Clang-red.png?style=flat)
![](http://img.shields.io/badge/architecture-x86%20|%20x64-yellow.png?style=flat)
[![](http://img.shields.io/badge/license-GNU%20GPL%20v2-lightgrey.png?style=flat)](/LICENSE)

## Features
+ Supports **Tiger-192**, **RipeMD-160** and **Whirlpool** algorithms
+ Simple interface, identical to the <a href="http://doc.qt.io/qt-5/qcryptographichash.html">QCryptographicHash</a> class, but renamed [**QCryptoHash**](https://github.com/rikyoz/QtCryptoHash/wiki/QCryptoHash)
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
	QCryptoHash ripemdHash( QCryptoHash::RMD160 );
	while( !file.atEnd() ){
		ripemdHash.addData( file.read( 8192 ) );
	}
	QByteArray fileHash = ripemdHash.result();	
	qInfo() << fileHash.toHex(); //RipeMD hash of 'filename' file content
}
```

For a complete description of the QCryptoHash API, see the relative [wiki](https://github.com/rikyoz/QtCryptoHash/wiki/QCryptoHash-class).

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