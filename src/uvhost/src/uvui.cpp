#include "uvui.h"
#include "ui_uvui.h"

UVUI::UVUI(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::UVUI)
{
    ui->setupUi(this);
    node = std::make_shared<UVHostNode>();
    joy = std::make_shared<Joystick>("/dev/input/js0");
    joyJob = std::make_shared<std::thread>([this]()->void{while(1){joy->get();}});
    //this->showMaximized();
    for(auto uv : node->uvList)
    {
        ui->listWidgetUvList->addItem(QString(uv->name.c_str())+" @ "+QString(uv->ip.c_str()));
        ui->comboBoxSelect->addItem(QString(uv->name.c_str()));
    }

    model = new QStandardItemModel(this);

    QStandardItem *item00 = new QStandardItem("name");
    QStandardItem *item10 = new QStandardItem("ip");
    QStandardItem *item20 = new QStandardItem("voltage");
    QStandardItem *item30 = new QStandardItem("[hand,arm,base]");
    QStandardItem *item40 = new QStandardItem("[wheelL,wheelR]");
    QStandardItem *item50 = new QStandardItem("tripod");
    QStandardItem *item60 = new QStandardItem("[aX,aY,aZ]");
    QStandardItem *item70 = new QStandardItem("[vX,vY,vZ]");
    QStandardItem *item80 = new QStandardItem("[pX,pY,pZ]");
    QStandardItem *item90 = new QStandardItem("[r,p,y]");

    QStandardItem *item01 = new QStandardItem("-");
    QStandardItem *item11 = new QStandardItem("-");
    QStandardItem *item21 = new QStandardItem("-");
    QStandardItem *item31 = new QStandardItem("[-,-,-]");
    QStandardItem *item41 = new QStandardItem("[-,-]");
    QStandardItem *item51 = new QStandardItem("-");
    QStandardItem *item61 = new QStandardItem("[-,-,-]");
    QStandardItem *item71 = new QStandardItem("[-,-,-]");
    QStandardItem *item81 = new QStandardItem("[-,-,-]");
    QStandardItem *item91 = new QStandardItem("[-,-,-]");

    model->setItem(0,0,item00);
    model->setItem(1,0,item10);
    model->setItem(2,0,item20);
    model->setItem(3,0,item30);
    model->setItem(4,0,item40);
    model->setItem(5,0,item50);
    model->setItem(6,0,item60);
    model->setItem(7,0,item70);
    model->setItem(8,0,item80);
    model->setItem(9,0,item90);

    model->setItem(0,1,item01);
    model->setItem(1,1,item11);
    model->setItem(2,1,item21);
    model->setItem(3,1,item31);
    model->setItem(4,1,item41);
    model->setItem(5,1,item51);
    model->setItem(6,1,item61);
    model->setItem(7,1,item71);
    model->setItem(8,1,item81);
    model->setItem(9,1,item91);

    ui->tableViewStatus->setModel(model);
    //ui->tableViewStatus->setColumnWidth(0,ui->tableViewStatus->width()/3);

    timerUIID = startTimer(100);
    timerROSID = startTimer(0);
    timerJoy = startTimer(100);
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

    auto uv = node->uvList.at(ui->comboBoxSelect->currentIndex());

    model->item(0,1)->setText(uv->name.c_str());
    model->item(1,1)->setText(uv->ip.c_str());
    model->item(2,1)->setText(QString("%1").arg(uv->voltage));
    model->item(3,1)->setText(QString("[%1,%1,%1]").arg(uv->armHand,uv->armArm,uv->armBase));
    model->item(4,1)->setText(QString("[%1,%1]").arg(uv->wheelSpeedLeft,uv->wheelSpeedRight));
    model->item(5,1)->setText(QString("%1").arg(uv->tripod));
    model->item(6,1)->setText(QString("[%1,%1,%1]").arg(uv->acc_x,uv->acc_y,uv->acc_z));
    model->item(7,1)->setText(QString("[%1,%1,%1]").arg(uv->vel_x,uv->vel_y,uv->vel_z));
    model->item(8,1)->setText(QString("[%1,%1,%1]").arg(uv->pos_x,uv->pos_y,uv->pos_z));
    model->item(9,1)->setText(QString("[%1,%1,%1]").arg(uv->roll,uv->pitch,uv->yaw));
    if(cur_id==-1)
    {
        ui->labelImg->setText("NO SIGNAL");
    }
    else
    {
        cv::Mat* img_ptr = &node->uvList.at(cur_id)->image;
        QImage img = QImage(img_ptr->data,img_ptr->cols,img_ptr->rows,QImage::Format_RGB888);
        ui->labelImg->setPixmap(QPixmap::fromImage(img));
        // node->uvList.at(cur_id)->image
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
        /*RCLCPP_INFO(rclcpp::get_logger("main"),"Time:%8d A:%d B:%d X:%d Y:%d LBU:%d RBU:%d LBD:%d RBD:%d start:%d select:%d LO:%d RO:%d XX:%-6d YY:%-6d LX:%-6d LY:%-6d RX:%-6d RY:%-6d",
                    joy->time, joy->a, joy->b, joy->x, joy->y, joy->lbu, joy->rbu, joy->lbd, joy->rbd, joy->start, joy->select, joy->lo, joy->ro,
                    joy->xx, joy->yy, joy->lx, joy->ly, joy->rx, joy->ry);*/
        if(ui->checkBoxRemote->isChecked())
        {
            int id = ui->comboBoxSelect->currentIndex();
            if(node->uvList.at(id)->isUp)
            {
                node->pubCommandTo(id,joy);
            }
        }
    }
}

void UVUI::on_pushButtonRefresh_clicked()
{
    node->freshConnectStatus();
}


void UVUI::on_checkBoxRemote_stateChanged(int arg1)
{

}


void UVUI::on_checkBoxSave_stateChanged(int arg1)
{

}


void UVUI::on_comboBoxSelect_currentIndexChanged(int index)
{
    cur_id = index;
    node->subImg = rclcpp::create_subscription<sensor_msgs::msg::Image>(node,"/color/image_raw",1,std::bind(&UVUI::imgCallback,this,std::placeholders::_1));

}

void UVUI::imgCallback(sensor_msgs::msg::Image::ConstSharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("img"),"hurray!");
    if(cur_id!=-1)
    {
        node->uvList.at(cur_id)->image = cv::Mat(msg->height,msg->width,CV_8UC3,(uchar*)msg->data.data()).clone();
    }
}

