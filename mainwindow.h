﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QSettings>
#include <QCloseEvent>
#include <QApplication>
#include <QSplashScreen>
#include <QDateTime>
#include <QTextEdit>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void stall(int time);

private slots:

    void on_dragArea_textChanged();

private:
    Ui::MainWindow *ui;

    void readSetting();
    void writeSetting();
    void closeEvent(QCloseEvent *e);
    void getPaths();
    void solveVacIssue(QString Path);
    QString getProcessPath(QString processName);
    QString cmd(QString command);
    QString cmd_dir(QString command, QString dir);
    void sharecodeTransform();
    bool isDigitStr(QString src);
    void getSteamID();
    //这三个函数封装用于读取vdf
    QString search_and_cut(QString input, QString key);
    QString get_until(QString input, QString end);
    QString getValue(QString input, QString key);
};
#endif // MAINWINDOW_H
