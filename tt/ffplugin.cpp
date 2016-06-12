#include "ff.h"
#include "ffplugin.h"

#include <QtPlugin>

ffPlugin::ffPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ffPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ffPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ffPlugin::createWidget(QWidget *parent)
{
    return new ff(parent);
}

QString ffPlugin::name() const
{
    return QLatin1String("ff");
}

QString ffPlugin::group() const
{
    return QLatin1String("");
}

QIcon ffPlugin::icon() const
{
    return QIcon();
}

QString ffPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ffPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ffPlugin::isContainer() const
{
    return false;
}

QString ffPlugin::domXml() const
{
    return QLatin1String("<widget class=\"ff\" name=\"ff\">\n</widget>\n");
}

QString ffPlugin::includeFile() const
{
    return QLatin1String("ff.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(ffplugin, ffPlugin)
#endif // QT_VERSION < 0x050000
