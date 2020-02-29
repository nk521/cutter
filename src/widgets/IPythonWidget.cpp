#include <QMainWindow>
#include <QAction>
#include <QScrollBar>
#include <iostream>
#include "core/Cutter.h"
#include "IPythonWidget.h"
#include "ui_IPythonWidget.h"
#include "common/Helpers.h"
#include "core/MainWindow.h"
// #include "python.h"

// execButton, ipythonLineEdit, outputTextEdit

IPythonWidget::IPythonWidget(MainWindow *main, QAction *action) :
    CutterDockWidget(main, action),
    ui(new Ui::IPythonWidget)
{
    ui->setupUi(this);
    
    ui->ipythonLineEdit->setTextMargins(10, 0, 0, 0);

}

IPythonWidget::~IPythonWidget() { }

void IPythonWidget::setupFont()
{
    ui->outputTextEdit->setFont(Config()->getFont());
}

void IPythonWidget::addOutput(const QString &msg)
{
    ui->outputTextEdit->appendPlainText(msg);
    scrollOutputToEnd();
}

void IPythonWidget::focusInputLineEdit()
{
    ui->ipythonLineEdit->setFocus();
}

void IPythonWidget::on_ipythonLineEdit_returnPressed()
{
    QString input = ui->ipythonLineEdit->text();
    if (input.isEmpty()) {
        return;
    }
    addOutput(input);
    ui->ipythonLineEdit->clear();
}

void IPythonWidget::on_execButton_clicked()
{
    on_ipythonLineEdit_returnPressed();
}

void IPythonWidget::scrollOutputToEnd()
{
    const int maxValue = ui->outputTextEdit->verticalScrollBar()->maximum();
    ui->outputTextEdit->verticalScrollBar()->setValue(maxValue);
}