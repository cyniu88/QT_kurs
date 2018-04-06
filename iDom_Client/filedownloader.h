#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QUrl imageUrl, QObject *parent = nullptr);
    ~FileDownloader() = default;
    QByteArray downloadedData() const;
    void getSnap();
    void setAddress(QString address);

signals:
    void downloaded( QByteArray d);

private slots:
    void fileDownloaded(QNetworkReply* pReply);

private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
    QNetworkRequest request;
};

#endif // FILEDOWNLOADER_H
