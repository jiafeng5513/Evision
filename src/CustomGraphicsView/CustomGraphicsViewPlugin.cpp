#include "CustomGraphicsView.h"
#include "CustomGraphicsViewPlugin.h"

#include <QtCore/QtPlugin>

CustomGraphicsViewPlugin::CustomGraphicsViewPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void CustomGraphicsViewPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool CustomGraphicsViewPlugin::isInitialized() const
{
	return initialized;
}

QWidget *CustomGraphicsViewPlugin::createWidget(QWidget *parent)
{
	return new CustomGraphicsView(parent);
}

QString CustomGraphicsViewPlugin::name() const
{
	return "CustomGraphicsView";
}

QString CustomGraphicsViewPlugin::group() const
{
	return "My Plugins";
}

QIcon CustomGraphicsViewPlugin::icon() const
{
	return QIcon();
}

QString CustomGraphicsViewPlugin::toolTip() const
{
	return QString();
}

QString CustomGraphicsViewPlugin::whatsThis() const
{
	return QString();
}

bool CustomGraphicsViewPlugin::isContainer() const
{
	return false;
}

QString CustomGraphicsViewPlugin::domXml() const
{
	return "<widget class=\"CustomGraphicsView\" name=\"customGraphicsView\">\n"
		" <property name=\"geometry\">\n"
		"  <rect>\n"
		"   <x>0</x>\n"
		"   <y>0</y>\n"
		"   <width>100</width>\n"
		"   <height>100</height>\n"
		"  </rect>\n"
		" </property>\n"
		"</widget>\n";
}

QString CustomGraphicsViewPlugin::includeFile() const
{
	return "CustomGraphicsView.h";
}
