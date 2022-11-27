#include "idom_client.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>
int main(int argc, char *argv[])
{

    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Unset);
  //  QGuiApplication::highDpiScaleFactorRoundingPolicy();
    QApplication a(argc, argv);
    auto devpr = a.devicePixelRatio();
qDebug() << "rozdzialka = " << devpr;
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "iDom_client2_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    iDom_client w;
    w.show();
    return a.exec();
}
