#include "qjenkins.h"
#include "jenkinsimpl.h"


QJenkins::QJenkins(QObject *parent) : QObject(parent),mImpl(new JenkinsImpl(parent))
{

}
bool QJenkins::init()
{
    return mImpl->init();
}

bool QJenkins::setToken(const QString &token)
{
    if(!mImpl->inited)
        return false;

    return mImpl->setToken(token);
}
bool  QJenkins::setServerURL(const QString &server)
{
    if(!mImpl->inited)
        return false;

    mImpl->mServerUrl=server;

}

QStringList  QJenkins::getAllJobs()
{
    if(!mImpl->inited)
        return QStringList();
}

bool  QJenkins::triggerJob(const QString &aJobName,const QStringList &aParams)
{
    if(!mImpl->inited)
        return false;
    return true;
}
