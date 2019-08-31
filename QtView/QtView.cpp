#include "QtView.h"

QtView::QtView(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	// this->sv = new SaveManager();
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(ui.actionSave_As, SIGNAL(triggered()), this, SLOT(saveFileAs()));
	connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(quit()));

	QValidator* validator = new QIntValidator(0, 32767, this);
	ui.txtSeeds->setValidator(validator);

}


/************************************************************************/
/************************************************************************/
/************************************************************************/


QMessageBox::StandardButton QtView::showYesNoDialog(std::string question) {

	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Warning",
		question.c_str(),
		QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

	return reply;

}

std::string QtView::showLoadDialog(std::string menu, std::string fileType, std::string directory) {

	return QFileDialog::getOpenFileName(this,
		tr(menu.c_str()), directory.c_str(), tr(fileType.c_str())).toStdString();

}

std::string QtView::showSaveDialog(std::string menu, std::string fileType, std::string directory) {

	return QFileDialog::getSaveFileName(this,
		tr(menu.c_str()), directory.c_str(), tr(fileType.c_str())).toStdString();

}

void QtView::showWarningDialog(std::string message) {

	QMessageBox::warning(
		this,
		tr("Warning!"),
		tr(message.c_str()));

}


bool QtView::checkUserInputs() {
	if (!this->setSeeds())
		return false;
	if (!this->setUsername())
		return false;
	if (!this->setGreetingMessage())
		return false;
	if (!this->setGoodbyeMessage())
		return false;
	if (!this->setGratitudeMessage())
		return false;
	if (!this->setReasoningMessage())
		return false;
	if (!this->setJobMessage())
		return false;
	if (!this->setLanguageMessage())
		return false;
	if (!this->setFoodMessage())
		return false;
	if (!this->setVacationMessage())
		return false;
	return true;
}

// We string check purely to check if the fields have changed, not if the field are valid.
bool QtView::isModified() {

	// General
	if (strcmp(std::to_string(this->sv->getSeedCount()).c_str(), ui.txtSeeds->text().toStdString().c_str()) != 0)
		return true;

	// Profile
	if (strcmp(this->sv->getUsername().c_str(), ui.txtUsername->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getGreetingMessage().c_str(), ui.txtGreeting->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getGoodbyeMessage().c_str(), ui.txtGoodbye->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getGratitudeMessage().c_str(), ui.txtGratitude->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getReasoningMessage().c_str(), ui.txtReasoning->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getJobMessage().c_str(), ui.txtJob->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getLanguageMessage().c_str(), ui.txtLanguage->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getFoodMessage().c_str(), ui.txtFood->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getVacationMessage().c_str(), ui.txtVacation->text().toStdString().c_str()) != 0)
		return true;


	return false;

}

bool QtView::handleOnClose() {

	if (this->sv && this->isModified()) {

		switch (this->showYesNoDialog("Do you want to save your changes?")) {
		case QMessageBox::Yes:
			this->handleSaveAs();
			break;
		case QMessageBox::Cancel:
			return false;
		default:
			break;
		}

	}

	return true;

}

void QtView::toggleEditWidgets(bool state) {

	// Menu actions
	ui.actionSave->setEnabled(state);
	ui.actionSave_As->setEnabled(state);

	// General
	ui.txtSeeds->setEnabled(state);

	// Profile
	ui.txtUsername->setEnabled(state);

	ui.txtGreeting->setEnabled(state);
	ui.txtGoodbye->setEnabled(state);
	ui.txtGratitude->setEnabled(state);
	ui.txtReasoning->setEnabled(state);
	ui.txtJob->setEnabled(state);
	ui.txtLanguage->setEnabled(state);
	ui.txtFood->setEnabled(state);
	ui.txtVacation->setEnabled(state);

}

void QtView::loadInValues() {

	// General
	ui.txtSeeds->setText(QString::number(this->sv->getSeedCount()));

	// Profile
	ui.txtUsername->setText(QString::fromStdString(this->sv->getUsername()));

	ui.txtGreeting->setText(QString::fromStdString(this->sv->getGreetingMessage()));
	ui.txtGoodbye->setText(QString::fromStdString(this->sv->getGoodbyeMessage()));
	ui.txtGratitude->setText(QString::fromStdString(this->sv->getGratitudeMessage()));
	ui.txtReasoning->setText(QString::fromStdString(this->sv->getReasoningMessage()));
	ui.txtJob->setText(QString::fromStdString(this->sv->getJobMessage()));
	ui.txtLanguage->setText(QString::fromStdString(this->sv->getLanguageMessage()));
	ui.txtFood->setText(QString::fromStdString(this->sv->getFoodMessage()));
	ui.txtVacation->setText(QString::fromStdString(this->sv->getVacationMessage()));


}

void QtView::handleSaveAs() {

	if (this->sv && !this->checkUserInputs())
		return;

	std::string source = this->showSaveDialog("Save Ham Ham Games .save file", "GBA Save (*.sav);;All Files (*)", "");

	if (source == "")
		return;

	this->sv->saveChanges(source);

}

void QtView::closeEvent(QCloseEvent* event)
{
	if (!this->handleOnClose()) {
		event->ignore();
	}
	else {
		event->accept();
	}
}


/************************************************************************/
/************************************************************************/
/************************************************************************/


bool QtView::setSeeds() {

	int seeds = 0;
	std::istringstream iss(ui.txtSeeds->text().toStdString().c_str());
	iss >> seeds;
	
	if (iss.fail()) {
		this->showWarningDialog("Failed setting seed count! Make sure the field only contains numbers.");
		return false;
	}

	if (seeds > 32767 || seeds < 0) {
		this->showWarningDialog("Failed setting seed count! Make sure the value is lower than 32767 and higher or equal than 0.");
		return false;
	}

	this->sv->setSeedCount(seeds);
	return true;

}

bool QtView::setUsername() {

	std::string value = ui.txtUsername->text().toStdString();

	if (value.size() > 7) {
		this->showWarningDialog("Failed setting usernae! The maximum size of the username is 7.");
		return false;
	}

	this->sv->setUsername(value);
	return true;

}

bool QtView::setGreetingMessage() {

	std::string value = ui.txtGreeting->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting greeting message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setGreetingMessage(value);
	return true;

}

bool QtView::setGoodbyeMessage() {

	std::string value = ui.txtGoodbye->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting goodbye message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setGoodbyeMessage(value);
	return true;

}

bool QtView::setGratitudeMessage() {

	std::string value = ui.txtGratitude->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting gratitude message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setGratitudeMessage(value);
	return true;

}

bool QtView::setReasoningMessage() {

	std::string value = ui.txtReasoning->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting reasoning message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setReasoningMessage(value);
	return true;

}

bool QtView::setJobMessage() {

	std::string value = ui.txtJob->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting job message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setJobMessage(value);
	return true;

}

bool QtView::setLanguageMessage() {

	std::string value = ui.txtLanguage->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting language message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setLanguageMessage(value);
	return true;

}

bool QtView::setFoodMessage() {

	std::string value = ui.txtFood->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting food message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setFoodMessage(value);
	return true;

}

bool QtView::setVacationMessage() {

	std::string value = ui.txtVacation->text().toStdString();

	if (value.size() > 15) {
		this->showWarningDialog("Failed setting vacation message! The maximum size of any message is 15.");
		return false;
	}

	this->sv->setVacationMessage(value);
	return true;

}



void QtView::openFile() {

	if (!this->handleOnClose())
		return;

	std::string fileName = this->showLoadDialog("Open Ham Ham Games .save file.", "GBA Save (*.sav);;All Files (*)", "");

	if (fileName == "")
		return;

	this->toggleEditWidgets(false);

	if (this->sv == nullptr)
		this->sv = new SaveManager(fileName);
	else
		this->sv->loadSave(fileName);

	this->loadInValues();
	this->toggleEditWidgets(true);

}


void QtView::saveFile() {
	
	if (this->sv && !this->checkUserInputs())
		return;

	this->sv->saveChanges();

}


void QtView::saveFileAs() {

	this->handleSaveAs();

}


void QtView::quit() {

	if (!this->handleOnClose())
		return;

	QApplication::exit();

}