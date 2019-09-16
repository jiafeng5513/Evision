#include "EvisionView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{	
	ShowWindow(GetConsoleWindow(), SW_HIDE);//Òþ²Ø¿ØÖÆÌ¨
	QApplication a(argc, argv);
	EvisionView w;
	w.show();

	return a.exec();
}
