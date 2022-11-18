#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <utilitarios.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Utilitarios>("com.piInformatica.utilitarios", 1.0, 0.0, "Utilitarios");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/MinhaIdadeDetalhada2/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
