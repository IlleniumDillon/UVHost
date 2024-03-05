#include "uvui.h"
#include "ui_uvui.h"

UVUI::UVUI(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::UVUI)
{
    ui->setupUi(this);
    node = std::make_shared<UVHostNode>();
    //this->showMaximized();
    for(auto uv : node->uvList)
    {
        ui->listWidgetUvList->addItem(QString(uv->name.c_str())+" @ "+QString(uv->ip.c_str()));
    }
    timerUIID = startTimer(50);
    timerROSID = startTimer(0);
    timerJoy = startTimer(50);
}

UVUI::~UVUI()
{
    delete ui;
    rclcpp::shutdown();
}

void UVUI::updateUI()
{
    for(auto uv : node->uvList)
    {
        if(uv->isUp)
        {
            ui->listWidgetUvList->item(uv->id)->setBackground(QBrush(QColor(Qt::green)));
        }
        else
        {
            ui->listWidgetUvList->item(uv->id)->setBackground(QBrush(QColor(Qt::yellow)));
        }
    }
}

void UVUI::timerEvent(QTimerEvent *e)
{
    if(timerUIID == e->timerId())
    {
        updateUI();
    }
    else if(timerROSID == e->timerId())
    {
        rclcpp::spin_some(node);
    }
    else if(timerJoy == e->timerId())
    {

    }
}

void UVUI::on_pushButtonRefresh_clicked()
{
    node->freshConnectStatus();
}

