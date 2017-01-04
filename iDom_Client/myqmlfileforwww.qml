<<<<<<< HEAD
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
=======
//import QtQuick 2.3

//Rectangle {
//    width: 200
//    height: 100
//    color: "red"

//    Text {
//        anchors.centerIn: parent
//        text: "Hello, World!"
//    }
//}
import QtQuick 2.4
import QtQuick.Controls 1.4
import QtWebView 1.0
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0
import QtMultimedia 5.4
Rectangle {
    id: content
    width: 800
    height: 600
    color: "red"
    WebView {
        id: webView
        anchors.fill: parent
        url: "http://cyniu88.no-ip.pl"
>>>>>>> a75145b7cbdeab6f3daa4b2be3028d4ce1e3efda
    }
 }
