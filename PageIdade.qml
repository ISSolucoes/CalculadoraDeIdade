import QtQuick 2.0
import QtQuick.Controls.Material
import QtQuick.Controls

Page {
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter

    Column {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label {
            text: qsTr("Diga sua data de nascimento")
            font.pixelSize: 16
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 10
        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Column {
                Dial {
                    id: dialDia
                    from: 1
                    to: 31
                    onMoved: {
                        campoTextoDia.text = dialDia.value.toFixed(0)
                    }
                }
                Label {
                    id: campoTextoDia
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Dia"
                }
            }


            Row {
                Column {
                    Dial {
                        id: dialMes
                        from: 1
                        to: 12
                        onMoved: {
                            campoTextoMes.text = dialMes.value.toFixed(0)
                        }
                    }
                    Label {
                        id: campoTextoMes
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Mês"
                    }
                }
            }
            Row {
                Column {
                    Dial {
                        id: dialAno
                        from: 1900
                        to: new Date().getFullYear().toString()
                        onMoved: {
                            //dialAno.to = new Date().getFullYear().toString();
                            campoTextoAno.text = dialAno.value.toFixed(0);
                        }
                    }
                    Label {
                        id: campoTextoAno
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Ano"
                    }
                }
            }
        }

        Button {

            id: botaoCalcularIdade
            anchors.horizontalCenter: parent.horizontalCenter
            flat: true
            text: qsTr("Calcular idade detalhada")

            //onClicked: utilitarios.setIdadeExata(dialAno.value.toFixed(0)+","+dialMes.value.toFixed()+","+dialDia.value.toFixed(0));

            onClicked: timerIniciarIdade.start();

            Timer {
                id: timerIniciarIdade
                interval: 1000; running: false; repeat: true; triggeredOnStart: true;
                onTriggered: utilitarios.setIdadeExata(dialAno.value.toFixed(0)+","+dialMes.value.toFixed()+","+dialDia.value.toFixed(0));
            }
        }

        Label {
            id: labelMinhaIdadeExata
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.Wrap
            text: utilitarios.idadeExata
            font.pixelSize: 18
        }

    }
}
