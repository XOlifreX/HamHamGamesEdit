#pragma once

#include <sstream>
#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QCloseEvent>

#include "ui_QtView.h"
#include "SaveManager.h"

class QtView : public QMainWindow
{
	Q_OBJECT

private:
	Ui::QtViewClass ui;
	SaveManager* sv;

	QMessageBox::StandardButton showYesNoDialog(std::string question);
	std::string showLoadDialog(std::string menu, std::string fileType, std::string directory);
	std::string showSaveDialog(std::string menu, std::string fileType, std::string directory);
	void showWarningDialog(std::string message);
	void closeEvent(QCloseEvent* event);

	bool isModified();
	bool handleOnClose();
	bool checkUserInputs();
	void handleSaveAs();
public:
	QtView(QWidget *parent = Q_NULLPTR);

private slots:
	bool setSeeds();
	bool setUsername();

	void openFile();
	void saveFile();
	void saveFileAs();
	void quit();
};
