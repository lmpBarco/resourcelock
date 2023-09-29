#include "resource.h"
#include <QDebug>
#include <QThread>


Resource::Resource(const QString &name):
    m_name(name),
    m_lock(name),
    m_rwLock(name + QStringLiteral("RW")),
    m_features({ QSharedPointer<Feature>(new Feature(m_rwLock)) })
{
}

QString Resource::name() const
{
    return m_name;
}

ResourceLock Resource::lock(int priority) const
{
    Q_UNUSED(priority);
    return ResourceLock(m_name);
}

ReadWriteLock& Resource::rwLock()
{
    return m_rwLock;
}

QList<QSharedPointer<Feature> > Resource::features() const
{
    return m_features;
}
