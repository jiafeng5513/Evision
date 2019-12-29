#include "EvisionView.h"
#include <QtWidgets/QApplication>
#include <iostream>
/*
 * magic
 */
static int __ = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();
/*
VS输入
*/
int main(int argc, char* argv[])
{
#ifdef WIN32
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
	QApplication a(argc, argv);
	EvisionView w;
	w.show();

	return a.exec();
}
