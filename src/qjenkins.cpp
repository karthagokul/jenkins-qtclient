#include "qjenkins.h"
#include "jenkinsimpl.h"

QJenkins::QJenkins(QObject *parent) : QObject(parent),mImpl(new JenkinsImpl(parent))
{

}
bool QJenkins::init()
{
    return mImpl->init();
}
