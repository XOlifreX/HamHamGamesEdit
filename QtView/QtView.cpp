#include "QtView.h"

QtView::QtView(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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
	return true;
}

// We string check purely to check if the fields have changed, not if the field are valid.
bool QtView::isModified() {

	if (strcmp(std::to_string(this->sv->getSeedCount()).c_str(), ui.txtSeeds->text().toStdString().c_str()) != 0)
		return true;

	if (strcmp(this->sv->getUsername().c_str(), ui.txtUsername->text().toStdString().c_str()) != 0)
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



void QtView::openFile() {

	if (!this->handleOnClose())
		return;

	std::string fileName = this->showLoadDialog("Open Ham Ham Games .save file.", "GBA Save (*.sav);;All Files (*)", "");

	if (fileName == "")
		return;

	if (this->sv == nullptr)
		this->sv = new SaveManager(fileName);
	else
		this->sv->loadSave(fileName);

	ui.txtSeeds->setText(QString::number(this->sv->getSeedCount()));
	ui.txtUsername->setText(QString::fromStdString(this->sv->getUsername()));

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