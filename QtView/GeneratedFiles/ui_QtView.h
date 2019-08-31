/********************************************************************************
** Form generated from reading UI file 'QtView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTVIEW_H
#define UI_QTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtViewClass
{
public:
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *action;
    QAction *actionQuit;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QSplitter *splitter;
    QLineEdit *txtUsername;
    QLineEdit *txtSeeds;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtViewClass)
    {
        if (QtViewClass->objectName().isEmpty())
            QtViewClass->setObjectName(QString::fromUtf8("QtViewClass"));
        QtViewClass->resize(312, 143);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtViewClass->sizePolicy().hasHeightForWidth());
        QtViewClass->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../TheHackMap/Hamtaro/Ham-Ham Games/HamHamGamesEdit.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        QtViewClass->setWindowIcon(icon);
        actionAbout = new QAction(QtViewClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionOpen = new QAction(QtViewClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(QtViewClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(QtViewClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        action = new QAction(QtViewClass);
        action->setObjectName(QString::fromUtf8("action"));
        actionQuit = new QAction(QtViewClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(QtViewClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 50, 47, 13));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(110, 30, 133, 40));
        splitter->setOrientation(Qt::Vertical);
        txtUsername = new QLineEdit(splitter);
        txtUsername->setObjectName(QString::fromUtf8("txtUsername"));
        sizePolicy.setHeightForWidth(txtUsername->sizePolicy().hasHeightForWidth());
        txtUsername->setSizePolicy(sizePolicy);
        splitter->addWidget(txtUsername);
        txtSeeds = new QLineEdit(splitter);
        txtSeeds->setObjectName(QString::fromUtf8("txtSeeds"));
        sizePolicy.setHeightForWidth(txtSeeds->sizePolicy().hasHeightForWidth());
        txtSeeds->setSizePolicy(sizePolicy);
        splitter->addWidget(txtSeeds);
        QtViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtViewClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 312, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        QtViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtViewClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtViewClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtViewClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout);

        retranslateUi(QtViewClass);

        QMetaObject::connectSlotsByName(QtViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtViewClass)
    {
        QtViewClass->setWindowTitle(QApplication::translate("QtViewClass", "Ham Ham Games Edit", nullptr));
        actionAbout->setText(QApplication::translate("QtViewClass", "About...", nullptr));
        actionOpen->setText(QApplication::translate("QtViewClass", "Open...", nullptr));
        actionSave->setText(QApplication::translate("QtViewClass", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("QtViewClass", "Save As...", nullptr));
        action->setText(QApplication::translate("QtViewClass", "-", nullptr));
        actionQuit->setText(QApplication::translate("QtViewClass", "Quit", nullptr));
        label->setText(QApplication::translate("QtViewClass", "Username:", nullptr));
        label_2->setText(QApplication::translate("QtViewClass", "Seeds:", nullptr));
        menuFile->setTitle(QApplication::translate("QtViewClass", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("QtViewClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtViewClass: public Ui_QtViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTVIEW_H
