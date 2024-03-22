#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("代码转图片"));
    setWindowIcon(QIcon(":/res/icon.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_select_clicked()
{
    file = QFileDialog::getSaveFileName(this,"图片保存","","Images (*.png)");
    qDebug() << file;
}


void MainWindow::on_generate_clicked()
{
    QString text = ui->textEdit->toPlainText();
    if(file.size()){
        QPixmap pixmap(ui->textEdit->size());
        QPainter painter(&pixmap);
        ui->textEdit->render(&painter);
        pixmap.save(file);
        QMessageBox::information(this,tr("提示"),"图片生成完成",QMessageBox::Yes);
    } else {
        QMessageBox::warning(this,"警告","请先选择路径",QMessageBox::Yes);
    }
}

