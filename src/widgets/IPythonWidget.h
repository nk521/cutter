#ifndef IPYTHONWIDGET_H
#define IPYTHONWIDGET_H

#include "core/MainWindow.h"
#include "CutterDockWidget.h"

namespace Ui {
class IPythonWidget;
}

class IPythonWidget : public CutterDockWidget
{
	Q_OBJECT

public:
	// explicit IPythonWidget(MainWindow *main, QAction *action = nullptr);
	explicit IPythonWidget(MainWindow *main, QAction *action = nullptr);
	~IPythonWidget();

private:
    std::unique_ptr<Ui::IPythonWidget> ui;

};

#endif // IPYTHONWIDGET_H