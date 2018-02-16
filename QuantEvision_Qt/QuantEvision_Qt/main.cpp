#include "QuantEvision_Qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QuantEvision_Qt w;
	w.show();
	return a.exec();
}
