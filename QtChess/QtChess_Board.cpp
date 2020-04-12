#include "stdafx.h"
#include "QtChess_Board.h"
#include <QPainter>
#include "QtChess_Pieces.h"
#include <QMouseEvent>
#include <QMessageBox>

extern QtChess_Pieces chesspieces[32];

QtChess_Board::QtChess_Board(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);

	selected_id = -1;

	for (int i = 0; i < 32; i++)
	{
		chesspieces[i].init(i);
	}
}

QtChess_Board::~QtChess_Board(){}

void QtChess_Board::paintEvent(QPaintEvent* qe)
{
	QPainter painter(this);

	for (int j = 0; j <= 10; j++)
	{
		painter.drawLine(QPoint(distance, distance * j), QPoint(9 * distance, distance * j));
	}

	for (int j = 0; j < 10; j++)
	{
		if (j == 1 || j == 9)
		{
			painter.drawLine(QPoint(distance * j, distance), QPoint(j * distance, distance * 10));
		}

		painter.drawLine(QPoint(distance * j, distance), QPoint(j * distance, distance * 5));
		painter.drawLine(QPoint(distance * j, distance * 6), QPoint(j * distance, distance * 10));
	}

	painter.drawLine(QPoint(distance * 4, distance), QPoint(distance * 6, distance * 3));
	painter.drawLine(QPoint(distance * 6, distance), QPoint(distance * 4, distance * 3));
	painter.drawLine(QPoint(distance * 4, distance * 8), QPoint(distance * 6, distance * 10));
	painter.drawLine(QPoint(distance * 6, distance * 8), QPoint(distance * 4, distance * 10));

	for (int id = 0; id < 32; id++)
	{
		DrawChessPieces(painter,id);
	}
}

void QtChess_Board::mouseReleaseEvent(QMouseEvent* qme)
{
	QPoint pt = qme->pos();//transfer pt to row and col, to ajust whether the position has pieces
	int row, col, i;
	
	bool bRet = GetRowCol(pt, row, col);
	if (bRet == false)//it means pieces are off the board
	{
		return;
	}

	for (i = 0; i < 32; ++i)
	{
		if (chesspieces[i]._row == row && chesspieces[i]._col == col && chesspieces[i]._dead == false)
		{
			QMessageBox::about(this, "this", "fewe");
			break;
			
		}
	}

	if (i < 32)
	{
		selected_id = i;
		update();
	}
}

bool QtChess_Board::GetRowCol(QPoint pt, int& row, int& col)
{
	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 8; col++)
		{
			QPoint c = center(row, col);
			int dx = c.x() - pt.x();
			int dy = c.y() - pt.y();
			int distance = dx * dx + dy * dy;
			if (distance < r * r) 
			{
				return true;
			}
		}
	}
	return false;
}

void QtChess_Board::DrawChessPieces(QPainter& painter, int id)
{
	QPoint c_point = center(id);
	QRect rect = QRect(c_point.x() - r, c_point.y() - r, r * 2, r * 2);

	if (id == selected_id)
	{
		painter.setBrush(QBrush(Qt::gray));
		/*painter.setBrush(QBrush(QColor(255, 255, 0)));
		painter.setBrush(QBrush(Qt::white));*/
	}
	else
	{
		painter.setBrush(QBrush(Qt::yellow));
	}

	//painter.setBrush(QBrush(QColor(255, 255, 0)));
	painter.setBrush(QBrush(Qt::yellow));
	painter.setPen(Qt::black);
	painter.drawEllipse(c_point, r, r);

	if (chesspieces[id]._red)
	{
		painter.setPen(Qt::red);
	}
	else
	{
		painter.setPen(Qt::black);
	}

	painter.setFont(QFont("system", r/2, 400));
	painter.drawText(rect, chesspieces[id].getText(), QTextOption(Qt::AlignCenter));
}

QPoint QtChess_Board::center(int row, int col)
{
	QPoint ret;
	/*ret.rx() = (col+1) * r * 2;
	ret.ry() = (row+1) * r * 2;*/

	ret.setX((col+1) * r * 2);
	ret.setY((row+1) * r * 2);

	return ret;
}

QPoint QtChess_Board::center(int id)
{
	return center(chesspieces[id]._row, chesspieces[id]._col);
}
