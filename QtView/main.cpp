#include "QtView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtView w;
	w.show();
	return a.exec();
}
