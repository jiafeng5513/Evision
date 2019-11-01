#include "EvisionView.h"
#include <QtWidgets/QApplication>
#include <iostream>
/*
 * magic
 */
static int __=[]()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

int main(int argc, char *argv[])
{	
	ShowWindow(GetConsoleWindow(), SW_HIDE);//Òþ²Ø¿ØÖÆÌ¨
	QApplication a(argc, argv);
	EvisionView w;
	w.show();

	return a.exec();
}
