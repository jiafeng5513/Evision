#include "Evision.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Evision w;
	w.show();
	return a.exec();
}
