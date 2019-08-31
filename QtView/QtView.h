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
	void toggleEditWidgets(bool state);
	void loadInValues();

	bool isModified();
	bool handleOnClose();
	bool checkUserInputs();
	void handleSaveAs();
public:
	QtView(QWidget *parent = Q_NULLPTR);

private slots:
	// General
	bool setSeeds();

	// Profile
	bool setUsername();
	bool setGreetingMessage();
	bool setGoodbyeMessage();
	bool setGratitudeMessage();
	bool setReasoningMessage();
	bool setJobMessage();
	bool setLanguageMessage();
	bool setFoodMessage();
	bool setVacationMessage();

	// IO
	void openFile();
	void saveFile();
	void saveFileAs();
	void quit();
};
