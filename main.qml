import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts

import com.piInformatica.utilitarios

ApplicationWindow {
    id:root
    width: 400
    height: 500
    visible: true
    title: qsTr("Idade Detalhada")

    Material.theme: Material.Light
    Material.accent: Material.Blue

    Utilitarios {
        id: utilitarios
    }

    header: ToolBar {
        width: parent.width
        Label {
            text: qsTr("Calculadora de Idade")
            anchors.centerIn: parent
            font.pixelSize: 20
        }
    }

    PageIdade {}

    /*footer: TabBar {
        id: tabBar
        width: parent.width

        TabButton {
            text: qsTr("Idade")
        }
        TabButton {
            text: qsTr("Ranking")
        }
    }*/

    /*StackLayout {
        id: pilhaLayout
        currentIndex: tabBar.currentIndex
        anchors.fill: parent

        Item {
            id: home
            PageIdade {}
        }
        Item {
            id: ranking

            Page {
                anchors.fill: parent
                ListView {
                    id: listView
                    anchors.fill: parent
                    anchors.margins: 18
                    clip: true

                    model: 5
                    delegate: Label {
                        text: "Index " + index
                        width: parent.width
                        anchors.centerIn: listView
                        wrapMode: Text.Wrap
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 22
                        color: "black"

                    }

                }
            }

        }
    }*/

}
