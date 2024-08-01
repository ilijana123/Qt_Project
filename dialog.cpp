#include "dialog.h"
#include "ui_dialog.h"
#include <QComboBox>
#include <QFileSystemModel>
#include <QTableView>
#include <QTextStream>
#include <QStandardItem>
#include <QFile>
#include <QTextEdit>
#include <QSize>
#include <QLineEdit>
#include <QDebug>
#include <QHeaderView>
#include <QSortFilterProxyModel>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMaximizeButtonHint;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags( flags );
    QStandardItemModel *model=new QStandardItemModel(830,5,this);
        for(int i=0;i<=830;i++)
        {
                QStandardItem *itm=new QStandardItem();
                itm->setIcon(QIcon("C:/Users/User/Documents/test2/resources/countries/flags/"+QString::number(i+1)+".jpg"));
                model->setItem(i,0,itm);
        } 
        QFile file("C:/Users/User/Documents/test2/resources/countries/countries.txt");
        if(file.open(QIODevice::ReadOnly))
        {
            int lineindex = 0;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                 QString fileLine = in.readLine();
                 QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);
                 for (int j = 1; j < lineToken.size(); j++)
                 {
                     QString value ="+"+lineToken.at(j);
                     QStandardItem *item = new QStandardItem(value);
                     model->setItem(lineindex, j, item);
                  }
                 for (int j = 2; j < lineToken.size(); j++)
                 {
                     QString value =lineToken.at(j);
                     QStandardItem *item = new QStandardItem(value);
                     model->setItem(lineindex, j, item);
                  }       
                   lineindex++;
             }
                  file.close();
        }
        ui->comboBox->setModel(model);
        ui->comboBox->setModelColumn(1);
        QTableView *view = new QTableView;
        ui->comboBox->setView(view);
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        view->setFixedWidth(500);
        view->setShowGrid(false);
        view->verticalHeader()->setVisible(false);
        view->horizontalHeader()->setVisible(false);
        QString text = ui->textEdit_2->toPlainText();
}
 Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_textEdit_textChanged()
{
    QString textContent = ui->textEdit->toPlainText();
    int length = textContent.count();
    int i=length/160;
    int p=length-160*i;
     ui->label_5->setText(QString("%1/%2").arg(160-p).arg(i+1));
}

void Dialog::on_textEdit_2_textChanged()
{

}

