#include <QApplication>
#include <QtWebView/QtWebView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWebView::initialize();
    QtWebView view;
    view.show();
    view.load(QUrl("http://google.com"));

    return a.exec();
}
