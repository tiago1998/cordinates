/****************************************************************************
** Meta object code from reading C++ file 'webview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/webview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WebView_t {
    QByteArrayData data[13];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebView_t qt_meta_stringdata_WebView = {
    {
QT_MOC_LITERAL(0, 0, 7), // "WebView"
QT_MOC_LITERAL(1, 8, 12), // "mouseClicked"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 35, 10), // "keyPressed"
QT_MOC_LITERAL(5, 46, 13), // "deletePressed"
QT_MOC_LITERAL(6, 60, 12), // "enterPressed"
QT_MOC_LITERAL(7, 73, 13), // "onShowPressed"
QT_MOC_LITERAL(8, 87, 18), // "onPTerminalPressed"
QT_MOC_LITERAL(9, 106, 11), // "onCompleted"
QT_MOC_LITERAL(10, 118, 7), // "popBack"
QT_MOC_LITERAL(11, 126, 6), // "onHelp"
QT_MOC_LITERAL(12, 133, 6) // "onExit"

    },
    "WebView\0mouseClicked\0\0QMouseEvent*\0"
    "keyPressed\0deletePressed\0enterPressed\0"
    "onShowPressed\0onPTerminalPressed\0"
    "onCompleted\0popBack\0onHelp\0onExit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    0,   70,    2, 0x06 /* Public */,
       6,    0,   71,    2, 0x06 /* Public */,
       7,    0,   72,    2, 0x06 /* Public */,
       8,    0,   73,    2, 0x06 /* Public */,
       9,    0,   74,    2, 0x06 /* Public */,
      10,    0,   75,    2, 0x06 /* Public */,
      11,    0,   76,    2, 0x06 /* Public */,
      12,    0,   77,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WebView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->keyPressed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->deletePressed(); break;
        case 3: _t->enterPressed(); break;
        case 4: _t->onShowPressed(); break;
        case 5: _t->onPTerminalPressed(); break;
        case 6: _t->onCompleted(); break;
        case 7: { QString _r = _t->popBack();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->onHelp(); break;
        case 9: _t->onExit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WebView::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::mouseClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WebView::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::keyPressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::deletePressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::enterPressed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::onShowPressed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::onPTerminalPressed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::onCompleted)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = QString (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::popBack)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::onHelp)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (WebView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebView::onExit)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WebView::staticMetaObject = { {
    &QWebView::staticMetaObject,
    qt_meta_stringdata_WebView.data,
    qt_meta_data_WebView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebView.stringdata0))
        return static_cast<void*>(this);
    return QWebView::qt_metacast(_clname);
}

int WebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WebView::mouseClicked(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WebView::keyPressed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WebView::deletePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WebView::enterPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WebView::onShowPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WebView::onPTerminalPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WebView::onCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
QString WebView::popBack()
{
    QString _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
    return _t0;
}

// SIGNAL 8
void WebView::onHelp()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void WebView::onExit()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
