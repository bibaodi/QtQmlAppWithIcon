#include <QDebug>
#include <QList>
#include <QPixmap>
#include <QWindow>
#include <QtCore/qglobal.h>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QCoreApplication::setApplicationName("appWithIcon");
  QIcon appIcon;
  // appIcon.addFile("/usr/share/pixmaps/siho128.png");
  QString iconpath1 = "qrc:/appWithIcon/siho128.png";
  appIcon.addFile(iconpath1);

  QPixmap pix(iconpath1);
  qDebug() << "pixSz=" << pix.size();
  pix.load(iconpath1);
  qDebug() << "2pixSz=" << pix.size();

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/appWithIcon/Main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); },
      Qt::QueuedConnection);
  engine.load(url);

  QList<QObject *> qmlist = engine.rootObjects();
  QObject *root_win = nullptr;
  QWindow *w = nullptr;
  for (QList<QObject *>::iterator i = qmlist.begin(); i != qmlist.end(); i++) {
    if ((*i)->objectName() == "root_window") {
      qDebug() << "get the root window:root_window";
      root_win = *i;
      w = (QWindow *)(root_win);
      w->setIcon(appIcon);
      /*
      QObject *im = (*i)->findChild<QObject *>("imgItem1");
      if (im) {
        qDebug() << "get Img item";
        (*i)->setProperty("source", "siho128.png");
      }*/
    }
  }

  return app.exec();
}
