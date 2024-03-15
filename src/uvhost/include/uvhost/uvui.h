#ifndef UVUI_H
#define UVUI_H

#include <QMainWindow>
#include <QTimerEvent>
#include <QStandardItemModel>
/*#include "DockManager.h"
#include "DockWidget.h"*/
#include "joystick.hpp"
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
    void imgCallback(sensor_msgs::msg::Image::ConstSharedPtr msg);

private slots:
    void on_pushButtonRefresh_clicked();

    void on_checkBoxRemote_stateChanged(int arg1);

    void on_checkBoxSave_stateChanged(int arg1);

    void on_comboBoxSelect_currentIndexChanged(int index);

private:
    Ui::UVUI *ui;
    std::shared_ptr<UVHostNode> node;
    std::shared_ptr<Joystick> joy;
    std::shared_ptr<std::thread> joyJob;

    QStandardItemModel* model;

    int timerUIID;
    int timerROSID;
    int timerJoy;

    int cur_id = -1;
};

#endif // UVUI_H
