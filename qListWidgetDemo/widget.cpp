#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemButton_clicked()
{
    ui->listWidget->addItem("MyItem");

}

void Widget::on_deleteItemButton_clicked()
{
    //Deleting Items
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::on_selectedItemsButton_clicked()
{
    QList<QListWidgetItem *> list = ui->listWidget->selectedItems();

    for(int i=0; i<list.count(); i++)
    {
        qDebug() << "Selected item : "<<list.at(i)->text()<<", row number id :" <<
                    ui->listWidget->row(list.at(i));
    }
}
