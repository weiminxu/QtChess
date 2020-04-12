#include "stdafx.h"
#include "QtChess_Board.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtChess_Board w;
	w.show();
	return a.exec();
}
