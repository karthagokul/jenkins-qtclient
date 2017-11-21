#ifndef QJENKINS_H
#define QJENKINS_H

#include <QObject>

class JenkinsImpl;

class QJenkins : public QObject
{
    Q_OBJECT
public:
    explicit QJenkins(QObject *parent = 0);
    bool init();
signals:

public slots:

private:
    JenkinsImpl *mImpl;
};

#endif // QJENKINS_H
