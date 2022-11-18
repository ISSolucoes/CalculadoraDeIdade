#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include <QObject>

class Utilitarios : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString idadeExata READ idadeExata WRITE setIdadeExata NOTIFY idadeExataChanged)
public:
    explicit Utilitarios(QObject *parent = nullptr);
    QString idadeExata();

signals:
    void idadeExataChanged();

public slots:
    void setIdadeExata( QString );

private:
    QString idadeExata_var;

};

#endif // UTILITARIOS_H
