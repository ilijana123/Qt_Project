#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
       Q_OBJECT
       Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
       Q_PROPERTY(int maxLenght READ maxLenght WRITE setMaxLenght)
       Q_PROPERTY(int length READ length)
public:

       Dialog(QWidget *parent = nullptr);

       ~Dialog();
       QString content();
       void setMaxWordNum(const int maxNum);
       void setTitle(const QString& title);
       void setContent(const QString& content);
signals:

private slots:
       void on_textEdit_textChanged();
       void slot_handleInput();
       void on_textEdit_2_textChanged();

private:
       Ui::Dialog *ui;
       int m_maxWordNum;


#endif // DIALOG_H
};
