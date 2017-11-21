#include "jenkinsimpl.h"
#include <QSettings>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include <QDebug>

/*
 * Trigger Build : curl -X POST https://localhost:8080/job/Demo/build  --data token=Gokul
 * */

JenkinsImpl::JenkinsImpl(QObject *parent) : QObject(parent),inited(false)
{

}

JenkinsImpl::~JenkinsImpl()
{
    QSettings settings("QJenkins", "jenkins-configs");
    qDebug()<<"Saving Settings to "<<settings.fileName();
    settings.setValue(QString("Server/URL"),mServerUrl);
    settings.sync();
}

void JenkinsImpl::triggerJob(const QString &jobId,const QString &data)
{
    QString postUrl=mServerUrl+QString("/job/")+jobId+QString("/build");
    qDebug()<<postUrl;
    QUrl urlFormed(postUrl);
    QByteArray args("--data token=Gokul");
    post(urlFormed,&args);
}

void JenkinsImpl::onPostRequestfinished(QNetworkReply *reply)
{
    //lets do it later
    qDebug()<<reply->readAll();
}


bool JenkinsImpl::post(const QUrl &aUrl,const QByteArray *args)
{
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onPostRequestfinished(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    QNetworkRequest request(aUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/x-www-form-urlencoded"));
    mgr->post(request,*args);
    return true;
}

bool JenkinsImpl::init()
{
    inited=true;

    return readSettings();
}

bool JenkinsImpl::readSettings()
{
  /*  QSettings settings("QJenkins", "jenkins-configs");
    mServerUrl = settings.value("Server/URL").value<QString>();
    //if(mServerUrl.isEmpty())
    {
        mServerUrl="https://localhost:8080";
        qWarning()<<" Using Defaults";
    }*/

    //testing
    QString job="Demo";
    QString data="data";
    triggerJob(job,data);


    return true;
}
