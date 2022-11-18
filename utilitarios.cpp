#include "utilitarios.h"

#include <QDateTime>
#include <QDate>
#include <string>

using namespace std;

Utilitarios::Utilitarios(QObject *parent)
    : QObject{parent},
      idadeExata_var("Idade detalhada")
{

}

QString Utilitarios::idadeExata()
{
    return idadeExata_var;
}

void Utilitarios::setIdadeExata(QString dataNascimentoUser)
{
    auto ano = std::stoi(dataNascimentoUser.split(",")[0].toStdString());
    auto mes = std::stoi(dataNascimentoUser.split(",")[1].toStdString());
    auto dia = std::stoi(dataNascimentoUser.split(",")[2].toStdString());

    QDateTime *dataNascimento = new QDateTime(QDate(ano, mes, dia), QTime(0,0,0));
    QDateTime dataAtual = QDateTime::currentDateTime();

    qint64 tempoDecorridoEmMS = dataNascimento->msecsTo(dataAtual);

    auto anoEmMS = 31536000000;
    auto mesEmMS = 2628002880;
    auto diaEmMS = 86400000;
    auto horaEmMS = 3600000;
    auto minEmMS = 60000;
    auto segEmMS = 1000;

    auto anos = tempoDecorridoEmMS/anoEmMS;
    auto restoAnosParaMes = tempoDecorridoEmMS%anoEmMS;

    auto meses = restoAnosParaMes/mesEmMS;
    auto restoMesesParaDias = restoAnosParaMes%mesEmMS;

    auto dias = restoMesesParaDias/diaEmMS;
    auto restoDiaParaHoras = restoMesesParaDias%diaEmMS;

    auto horas = restoDiaParaHoras/horaEmMS;
    auto restoHoraParaMinutos = restoDiaParaHoras%horaEmMS;

    auto minutos = restoHoraParaMinutos/minEmMS;
    auto restoMinutosParaSegundos = restoHoraParaMinutos%minEmMS;

    auto segundos = restoMinutosParaSegundos/segEmMS;

    /* Essas atribuições somem, e vão diretamente para o metodo append abaixo. Por algum motivo, ao fim da expressão o objeto é destruido
         * auto textoAno = to_string(anos).data();
        auto textoMeses = to_string(meses).data();
        auto textoDias = to_string(dias).data();
        auto textoHoras = to_string(horas).data();
        auto textoMinutos = to_string(minutos).data();
        auto textoSegundos = to_string(segundos).data();
        */

    QString idadeExata("");
    idadeExata.append(to_string(anos).data()).append(" ano(s) ")
            .append(to_string(meses).data()).append(" mes(es) ")
            .append(to_string(dias).data()).append(" dia(s) ")
            .append(to_string(horas).data()).append(" hora(s) ")
            .append(to_string(minutos).data()).append(" minuto(s) ")
            .append(to_string(segundos).data()).append(" segundo(s)");
    //string idadeExataStringSTD = idadeExata.toStdString();

    idadeExata_var = idadeExata;
    emit idadeExataChanged();

}

