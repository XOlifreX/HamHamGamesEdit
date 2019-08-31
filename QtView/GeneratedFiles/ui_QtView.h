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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QTabWidget *tabWidget;
    QWidget *tabGeneral;
    QLabel *label_2;
    QLineEdit *txtSeeds;
    QWidget *tabProfile;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *txtGreeting;
    QLineEdit *txtGoodbye;
    QLineEdit *txtGratitude;
    QLineEdit *txtReasoning;
    QLineEdit *txtJob;
    QLineEdit *txtLanguage;
    QLineEdit *txtFood;
    QLineEdit *txtVacation;
    QLineEdit *txtUsername;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtViewClass)
    {
        if (QtViewClass->objectName().isEmpty())
            QtViewClass->setObjectName(QString::fromUtf8("QtViewClass"));
        QtViewClass->resize(248, 395);
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
        actionSave->setEnabled(false);
        actionSave_As = new QAction(QtViewClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSave_As->setEnabled(false);
        action = new QAction(QtViewClass);
        action->setObjectName(QString::fromUtf8("action"));
        actionQuit = new QAction(QtViewClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(QtViewClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 241, 341));
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QString::fromUtf8("tabGeneral"));
        label_2 = new QLabel(tabGeneral);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 47, 16));
        txtSeeds = new QLineEdit(tabGeneral);
        txtSeeds->setObjectName(QString::fromUtf8("txtSeeds"));
        txtSeeds->setEnabled(false);
        txtSeeds->setGeometry(QRect(100, 20, 131, 21));
        sizePolicy.setHeightForWidth(txtSeeds->sizePolicy().hasHeightForWidth());
        txtSeeds->setSizePolicy(sizePolicy);
        tabWidget->addTab(tabGeneral, QString());
        tabProfile = new QWidget();
        tabProfile->setObjectName(QString::fromUtf8("tabProfile"));
        label = new QLabel(tabProfile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 61, 16));
        label_3 = new QLabel(tabProfile);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 47, 21));
        label_4 = new QLabel(tabProfile);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 47, 20));
        label_5 = new QLabel(tabProfile);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 51, 21));
        label_6 = new QLabel(tabProfile);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 160, 61, 21));
        label_7 = new QLabel(tabProfile);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 190, 71, 16));
        label_8 = new QLabel(tabProfile);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 220, 81, 16));
        label_9 = new QLabel(tabProfile);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 250, 81, 16));
        label_10 = new QLabel(tabProfile);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 280, 81, 20));
        txtGreeting = new QLineEdit(tabProfile);
        txtGreeting->setObjectName(QString::fromUtf8("txtGreeting"));
        txtGreeting->setEnabled(false);
        txtGreeting->setGeometry(QRect(100, 70, 133, 21));
        txtGoodbye = new QLineEdit(tabProfile);
        txtGoodbye->setObjectName(QString::fromUtf8("txtGoodbye"));
        txtGoodbye->setEnabled(false);
        txtGoodbye->setGeometry(QRect(100, 100, 131, 21));
        txtGratitude = new QLineEdit(tabProfile);
        txtGratitude->setObjectName(QString::fromUtf8("txtGratitude"));
        txtGratitude->setEnabled(false);
        txtGratitude->setGeometry(QRect(100, 130, 131, 21));
        txtReasoning = new QLineEdit(tabProfile);
        txtReasoning->setObjectName(QString::fromUtf8("txtReasoning"));
        txtReasoning->setEnabled(false);
        txtReasoning->setGeometry(QRect(100, 160, 131, 21));
        txtJob = new QLineEdit(tabProfile);
        txtJob->setObjectName(QString::fromUtf8("txtJob"));
        txtJob->setEnabled(false);
        txtJob->setGeometry(QRect(100, 190, 131, 21));
        txtLanguage = new QLineEdit(tabProfile);
        txtLanguage->setObjectName(QString::fromUtf8("txtLanguage"));
        txtLanguage->setEnabled(false);
        txtLanguage->setGeometry(QRect(100, 220, 131, 21));
        txtFood = new QLineEdit(tabProfile);
        txtFood->setObjectName(QString::fromUtf8("txtFood"));
        txtFood->setEnabled(false);
        txtFood->setGeometry(QRect(100, 250, 131, 21));
        txtVacation = new QLineEdit(tabProfile);
        txtVacation->setObjectName(QString::fromUtf8("txtVacation"));
        txtVacation->setEnabled(false);
        txtVacation->setGeometry(QRect(100, 280, 131, 21));
        txtUsername = new QLineEdit(tabProfile);
        txtUsername->setObjectName(QString::fromUtf8("txtUsername"));
        txtUsername->setEnabled(false);
        txtUsername->setGeometry(QRect(100, 20, 131, 21));
        sizePolicy.setHeightForWidth(txtUsername->sizePolicy().hasHeightForWidth());
        txtUsername->setSizePolicy(sizePolicy);
        tabWidget->addTab(tabProfile, QString());
        QtViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtViewClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 248, 21));
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

        tabWidget->setCurrentIndex(0);


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
        label_2->setText(QApplication::translate("QtViewClass", "Seeds:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGeneral), QApplication::translate("QtViewClass", "General", nullptr));
        label->setText(QApplication::translate("QtViewClass", "Username:", nullptr));
        label_3->setText(QApplication::translate("QtViewClass", "Greeting:", nullptr));
        label_4->setText(QApplication::translate("QtViewClass", "Goodbye:", nullptr));
        label_5->setText(QApplication::translate("QtViewClass", "Gratitude:", nullptr));
        label_6->setText(QApplication::translate("QtViewClass", "Reasoning:", nullptr));
        label_7->setText(QApplication::translate("QtViewClass", "Future job:", nullptr));
        label_8->setText(QApplication::translate("QtViewClass", "Language:", nullptr));
        label_9->setText(QApplication::translate("QtViewClass", "Fevorite food:", nullptr));
        label_10->setText(QApplication::translate("QtViewClass", "Dream vacation:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProfile), QApplication::translate("QtViewClass", "Profile", nullptr));
        menuFile->setTitle(QApplication::translate("QtViewClass", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("QtViewClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtViewClass: public Ui_QtViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTVIEW_H
