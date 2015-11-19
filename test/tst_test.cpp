#include <QString>
#include <QMap>
#include <QtTest>
#include <QDebug>

#include "qcryptohash.hpp"

static QMap<QByteArray, QByteArray> tigerTests = {
    {"", "24f0130c63ac933216166e76b1bb925ff373de2d49584e7a"},
    {"abc", "f258c1e88414ab2a527ab541ffc5b8bf935f7b951c132951"},
    {"Tiger", "9f00f599072300dd276abb38c8eb6dec37790c116f9d2bdf"},
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefgh"
        "ijklmnopqrstuvwxyz0123456789+-", "87fb2a9083851cf7470d2cf810e6df9eb586445034a5a386"
    },
    {
        "Tiger - A Fast New Hash Function, "
        "by Ross Anderson and Eli Biham, proc"
        "eedings of Fast Software Encryption "
        "3, Cambridge, 1996.", "3d9aeb03d1bd1a6357b2774dfd6d5b24dd68151d503974fc"
    }
};

static QMap<QByteArray, QByteArray> ripemdTests = {
    {"", "9c1185a5c5e9fc54612808977ee8f548b2258d31"},
    {"a", "0bdc9d2d256b3ee9daae347be6f4dc835a467ffe"},
    {"abc", "8eb208f7e05d987a9b044a8e98c6b087f15a0bfc"},
    {"message digest", "5d0689ef49d2fae572b881b123a85ffa21595f36"},
    {"abcdefghijklmnopqrstuvwxyz", "f71c27109c692c1b56bbdceb5b9d2865b3708dbc"},
    {
        "abcdbcdecdefdefgefghfghi"
        "ghijhijkijkljklmklmnlmno"
        "mnopnopq", "12a053384a9c0c88e405a06c27dcf49ada62eb2b"
    },
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefgh"
        "ijklmnopqrstuvwxyz0123456789", "b0e20b6e3116640286ed3a87a5713079b21f5189"
    },
    {
        "123456789012345678901234567890"
        "123456789012345678901234567890"
        "12345678901234567890", "9b752e45573d4b39f4dbd3323cab82bf63326bfb"
    }
};

static QMap<QByteArray, QByteArray> whirlpoolTests = {
    {
        "", "19fa61d75522a4669b44e39c1d2e1726c530232130d407f89afee0964997f7a73e"
        "83be698b288febcf88e3e03c4f0757ea8964e59b63d93708b138cc42a66eb3"
    },
    {
        "a", "8aca2602792aec6f11a67206531fb7d7f0dff59413145e6973c45001d0087b42d1"
        "1bc645413aeff63a42391a39145a591a92200d560195e53b478584fdae231a"
    },
    {
        "abc", "4e2448a4c6f486bb16b6562c73b4020bf3043e3a731bce721ae1b303d97e6d4c"
        "7181eebdb6c57e277d0e34957114cbd6c797fc9d95d8b582d225292076d4eef5"
    },
    {
        "message digest", "378c84a4126e2dc6e56dcc7458377aac838d00032230f53ce1f5700c0ffb4d3b"
        "8421557659ef55c106b4b52ac5a4aaa692ed920052838f3362e86dbd37a8903e"
    },
    {
        "abcdefghijklmnopqrstuvwxyz",
        "f1d754662636ffe92c82ebb9212a484a8d38631ead4238f5442ee13b8054e41b"
        "08bf2a9251c30b6a0b8aae86177ab4a6f68f673e7207865d5d9819a3dba4eb3b"
    },
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
        "dc37e008cf9ee69bf11f00ed9aba26901dd7c28cdec066cc6af42e40f82f3a1e"
        "08eba26629129d8fb7cb57211b9281a65517cc879d7b962142c65f5a7af01467"
    },
    {
        "12345678901234567890123456789012345678901234567890123456789012345678901234567890",
        "466ef18babb0154d25b9d38a6414f5c08784372bccb204d6549c4afadb601429"
        "4d5bd8df2a6c44e538cd047b2681a51a2c60481e88c5a20b2c2a80cf3a9a083b"
    },
    {
        "abcdbcdecdefdefgefghfghighijhijk",
        "2a987ea40f917061f5d6f0a0e4644f488a7a5a52deee656207c562f988e95c69"
        "16bdc8031bc5be1b7b947639fe050b56939baaa0adff9ae6745b7b181c3be3fd"
    }
};

class Test : public QObject {
        Q_OBJECT

    public:
        Test();

    private Q_SLOTS:
        void initTestCase();
        void cleanupTestCase();
        void testTigerHash();
        void testRipeMDHash();
        void testWhirlpoolHash();

    private:
        void genericHashTest( const QMap<QByteArray, QByteArray> &tests, QCryptoHash::Algorithm method );
};

Test::Test() {}

void Test::initTestCase() {}

void Test::cleanupTestCase() {}

void Test::testTigerHash() {
    genericHashTest( tigerTests, QCryptoHash::TIGER );
}

void Test::testRipeMDHash() {
    genericHashTest( ripemdTests, QCryptoHash::RMD160 );
}

void Test::testWhirlpoolHash() {
    genericHashTest( whirlpoolTests, QCryptoHash::WHIRLPOOL );
}

void Test::genericHashTest( const QMap<QByteArray, QByteArray> &tests, QCryptoHash::Algorithm method ) {
    int current_test = 1;
    auto it_end = tests.cend();
    for ( auto it_start = tests.cbegin(); it_start != it_end; ++it_start ) {
        QByteArray hash = QCryptoHash::hash( it_start.key(), method ).toHex();
        auto error_message = QString( "Failed Test %1" ).arg( current_test ).toStdString();
        QVERIFY2( hash == it_start.value(), error_message.c_str() );
        ++current_test;
    }
}

QTEST_APPLESS_MAIN( Test )

#include "tst_test.moc"
