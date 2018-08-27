#include "EvisionView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EvisionView w;
	w.show();
	return a.exec();
}
