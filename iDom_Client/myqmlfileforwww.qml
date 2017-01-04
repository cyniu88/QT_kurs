import QtQuick 2.4
import QtQuick.Controls 1.4
import QtWebView 1.0
import QtQuick.Layouts 1.1

import QtMultimedia 5.4

Item {
    id: root
    WebView {
        id: webView
        url: "http://cyniu88.no-ip.pl/"
        anchors.fill: root

    }

    BusyIndicator {
        running: webView.loading
        anchors.centerIn: webView
    }
}