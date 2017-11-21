#ifndef JENKINSIMPL_H
#define JENKINSIMPL_H

#include <QObject>

class QNetworkReply;
class JenkinsImpl : public QObject
{
    Q_OBJECT
public:
    explicit JenkinsImpl(QObject *parent = 0);
    bool init();
    void triggerJob(const QString &jobId,const QString &data);
    virtual ~JenkinsImpl();
signals:

public slots:
    void onPostRequestfinished(QNetworkReply *reply);
private:
     QString mServerUrl;
     QString mAPIKey;
     QString mUserName;
     QString mPassword;
     bool inited;
    friend class QJenkins;

protected:
    bool readSettings();
    bool post(const QUrl &aUrl,const QByteArray *args);
    bool setToken(const QString &token)
    {
        mAPIKey=token;
    }

};

#endif // JENKINSIMPL_H
