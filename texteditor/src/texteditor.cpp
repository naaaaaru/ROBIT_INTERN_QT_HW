#include "texteditor.h"
#include "./ui_texteditor.h"
#include <QFileDialog> // getOpenFileName,getSaveFileName
#include <fstream>//파일 읽고 쓰는 입출력 라이브러리
#include <iostream>

texteditor::texteditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::texteditor)
{
    ui->setupUi(this);
    currentFile = "";  // 현재 열려 있는 파일 경로
    showFilename();
}

texteditor::~texteditor()
{
    delete ui;
}

// 파일 열기 기능 구현
void texteditor::on_open_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if (filename.isEmpty()) return;  // 사용자가 파일 선택을 취소한 경우

    std::ifstream file(filename.toStdString());//파일 읽기 모드

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());//파일 문자열로 가져오기
    file.close();

    ui->textEdit->setPlainText(QString::fromStdString(content));//파일 문자열 출력
    currentFile = filename;//파일 이름 가져와 출력
    showFilename();
}

// 파일 저장 기능
void texteditor::on_save_clicked()
{
    std::ofstream file(currentFile.toStdString());

    std::string content = ui->textEdit->toPlainText().toStdString();
    file << content;
    file.close();
}

// 다른 이름으로 저장 기능
void texteditor::on_saveas_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save File As", "", "Text Files (*.txt);;All Files (*)");
    if (filename.isEmpty()) return;  // 사용자가 저장을 취소한 경우

    std::ofstream file(filename.toStdString());

    std::string content = ui->textEdit->toPlainText().toStdString();
    file << content;
    file.close();
    currentFile = filename;  // 현재 파일 경로 업
    showFilename();
}

// 프로그램 종료 기능
void texteditor::on_close_clicked()
{
    QApplication::quit();
}

void texteditor::showFilename()
{
    if (currentFile.isEmpty())
    {
        ui->filename->setText("No File Selected...");
    }
    else
    {
        ui->filename->setText(currentFile);
    }
}
