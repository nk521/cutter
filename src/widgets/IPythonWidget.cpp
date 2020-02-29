#include <QMainWindow>
#include <QAction>
#include <iostream>
#include "core/Cutter.h"
#include "IPythonWidget.h"
#include "ui_IPythonWidget.h"
#include "common/Helpers.h"
#include "core/MainWindow.h"
#include "python.h"

IPythonWidget::IPythonWidget(MainWindow *main, QAction *action) :
    CutterDockWidget(main, action),
    ui(new Ui::IPythonWidget)
{
    ui->setupUi(this);
    
    ui->ipythonLineEdit->setTextMargins(10, 0, 0, 0);

}

IPythonWidget::~IPythonWidget() { }
