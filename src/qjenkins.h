#ifndef QJENKINS_H
#define QJENKINS_H

#include <QObject>
#include <QStringList>

class JenkinsImpl;

class QJenkins : public QObject
{
    Q_OBJECT
public:
    explicit QJenkins(QObject *parent = 0);
    bool init();

    //APIS
    bool setServerURL(const QString &server);
    bool setToken(const QString &token);
    QStringList getAllJobs();
    bool triggerJob(const QString &aJobName,const QStringList &aParams=QStringList());

signals:

public slots:

private:
    JenkinsImpl *mImpl;

};

#endif // QJENKINS_H
