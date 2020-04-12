/********************************************************************************
** Form generated from reading UI file 'QtChess.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCHESS_H
#define UI_QTCHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtChessClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtChessClass)
    {
        if (QtChessClass->objectName().isEmpty())
            QtChessClass->setObjectName(QStringLiteral("QtChessClass"));
        QtChessClass->resize(600, 400);
        menuBar = new QMenuBar(QtChessClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtChessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtChessClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtChessClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtChessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtChessClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtChessClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtChessClass->setStatusBar(statusBar);

        retranslateUi(QtChessClass);

        QMetaObject::connectSlotsByName(QtChessClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtChessClass)
    {
        QtChessClass->setWindowTitle(QApplication::translate("QtChessClass", "QtChess", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtChessClass: public Ui_QtChessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCHESS_H
