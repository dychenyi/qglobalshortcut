#include "qglobalshortcut.h"
#include "test_label.h"
#ifdef Q_OS_WIN32
#include <QApplication>
#else
#include <QtWidgets/QApplication>
#endif
#include <QKeySequence>


int main(int argc, char** argv) {
    QApplication app(argc, argv);
    TestLabel l;
    l.setText("Label1");
    QGlobalShortcut* gs = new QGlobalShortcut(QKeySequence("Alt+Ctrl+A"), &l);
    QObject::connect(gs, SIGNAL(activated()),
                     &l, SLOT(success()));
    l.move(100, 100);
    l.resize(150, 50);
    l.show();

    TestLabel l2;
    l2.setText("Label2");
    QGlobalShortcut* gs2 = new QGlobalShortcut(&l2);
    gs2->setKey(QKeySequence("Ctrl+F2"));
    QObject::connect(gs2, SIGNAL(activated()),
                     &l2, SLOT(success()));
    l2.move(150, 150);
    l2.resize(150, 50);
    l2.show();

    TestLabel l3;
    l3.setText("Label3");
    QGlobalShortcut* gs3 = new QGlobalShortcut(&l3);
    gs3->setKey(QKeySequence("Shift+Esc"));
    QObject::connect(gs3, SIGNAL(activated()),
                     &l3, SLOT(success()));
    l3.move(200, 200);
    l3.resize(150, 50);
    l3.show();

    return app.exec();
}
