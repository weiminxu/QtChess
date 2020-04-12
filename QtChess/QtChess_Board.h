#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtChess.h"
#include <QPainter>
#include "QtChess_Pieces.h"

class QtChess_Board : public QMainWindow
{
	Q_OBJECT

public:
	QtChess_Board(QWidget *parent = Q_NULLPTR);
	~QtChess_Board();

public:
	int distance = 40;
	int r = 20;
	int selected_id;
	//QtChess_Pieces chesspieces[32];

	virtual void paintEvent(QPaintEvent*);
	virtual void mouseReleaseEvent(QMouseEvent*);
	bool QtChess_Board::GetRowCol(QPoint, int&, int&);
	void DrawChessPieces(QPainter& painter, int id);
	QPoint center(int row, int col);
	QPoint center(int id);

private:
	Ui::QtChessClass ui;
	
};
