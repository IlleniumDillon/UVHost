#ifndef UVUI_H
#define UVUI_H

#include <QMainWindow>
#include <QTimerEvent>
/*#include "DockManager.h"
#include "DockWidget.h"*/
#include "uvhost.hpp"

namespace Ui {
class UVUI;
}

class UVUI : public QMainWindow
{
    Q_OBJECT

public:
    UVUI(QWidget *parent = nullptr);
    ~UVUI();
    void updateUI();
    void timerEvent(QTimerEvent *e);

private slots:
    void on_pushButtonRefresh_clicked();

private:
    Ui::UVUI *ui;
    std::shared_ptr<UVHostNode> node;
    int timerUIID;
    int timerROSID;
    int timerJoy;
};

#endif // UVUI_H
