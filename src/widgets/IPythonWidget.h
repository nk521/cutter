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

public slots:
    void focusInputLineEdit();

    void addOutput(const QString &msg);

private slots:
	void setupFont();

	void on_ipythonLineEdit_returnPressed();
	void on_execButton_clicked();

private:
	void scrollOutputToEnd();
    std::unique_ptr<Ui::IPythonWidget> ui;

};

#endif // IPYTHONWIDGET_H