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
#include <QDesktopServices>
#include <QUrl>
#include <QClipboard>
#include <QStandardItemModel>
#include <QFont>
#include <QScreen>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include "lib/JlCompress.h"
#include "Windows.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //显示窗体
    void dispForm();

private slots:

    void on_dragArea_textChanged();

    void on_downURL_clicked();

    void on_clipURL_clicked();

    void on_autoDownload_stateChanged(int arg1);

    void on_autoClip_stateChanged(int arg1);

    void on_opencsgocfg_clicked();

    void on_openlocalcfg_clicked();

    void on_manualBtn_clicked();

    void on_backupSetting_clicked();

    void on_openCNlocalcfg_clicked();

    void on_ManualSteamID_clicked();

    void on_getUserDataBtn_clicked();

    void on_getLauncherPathBtn_clicked();

    void on_antiHarmony_clicked();

    void on_reloadHarmony_clicked();

    void on_solveVAC_clicked();

    void onChooseBtnClicked();

    void onUserDeleteBtnClicked();

    void onRestoreBtnClicked();

    void onDeleteBtnClicked();

    void on_openBackupLoc_clicked();

    void on_zipBackupdata_clicked();

    void on_opencsgoDir_clicked();

    void on_manualCsgoBtn_clicked();

    void on_high_clicked();

    void on_balanced_clicked();

    void on_powersave_clicked();

    void on_Ryzen3000_clicked();

    void on_RyzenEtc_clicked();

    void on_allPlatform_clicked();

    void on_LaunchPwrd1_clicked();

    void on_LaunchWwd1_clicked();

    void on_LaunchPwrd2_clicked();

    void on_LaunchWwd2_clicked();

    void on_checkboxTray_stateChanged(int arg1);

    //对托盘图标操作的槽：本代码实现单机图标恢复窗口功能
    void TrayIconAction(QSystemTrayIcon::ActivationReason reason);
    //Kill进程csgo
    void killcsgo();

    void on_save_clicked();

    void on_screenshotClip_clicked();

    void launchWwd();
    void launchPwrd();

    void on_sliderLaunchFirst_valueChanged(int value);
    void changeLaunchOpt();

private:
    Ui::MainWindow *ui;
    //全局变量
    QString steamPath;
    QString launcherPath;
    QString csgoPath;
    QString steamID;
    QString userName;
    QString launchOption1;
    QString launchOption2;
    QStringList SteamIDList, PersonaNameList;
    bool autoClip;
    bool autoDownload;
    bool backupdataZipped;
    bool useTray;
    short cpuType;
    QSystemTrayIcon *tray;//托盘图标
    QMenu *menu;
    QMenu *menuLaunchOpt;
    /**
      * 程序的核心模块，是完成其他实际功能的基础
      * 1. 程序启动/关闭时调用
      * 2. 获取各种路径
      * 3. 获取SteamID
      */

    //程序启动/关闭时调用
    void setupUI();
    void readSetting();
    void writeSetting();
    void closeEvent(QCloseEvent *e);

    //获取各种路径
    bool getSteamPath();
    bool getLauncherPath();
    bool getCsgoPath();

    //获取SteamID
    void getSteamID();
    void setupUserdata();

    /**
     *  拓展功能，基于核心模块和封装好的功能模块，完成具体的功能
     *  包括：
     *  1. 转换DEMO分享代码 获得真实下载链接
     *  2. 修复VAC验证问题
     *  3. 备份和还原设置（个人cfg文件夹）
     *  4. 国服反和谐和反和谐恢复
     *  5. 打开各种cfg文件夹和csgo位置
     */

    //解决VAC验证问题
    void solveVacIssue();
    //分享代码转换直接下载链接
    void sharecodeTransform();
    //备份
    void refreshBackup();

    //获取电脑配置
    void getPCconfig();

    //创建系统托盘
    void createTray();

    /**
     *  功能模块封装，给其他功能调用，减少代码冗余
     */

    void stall(int time);
    bool isDigitStr(QString src);
    bool isSteamExisted(QString tPath = "default");
    bool isLauncherExisted(QString tPath = "default");
    bool isCsgoExisted(QString tPath = "default");
    QString getProcessPath(QString processName);
    QString cmd(QString command);
    QString cmd_dir(QString command, QString dir);
    QString wmic(QString name, QString info);

    //这三个函数封装用于读取 "关键字" "值"中的值 ->ID、启动项
    QString search_and_cut(QString &input, QString key);
    QString get_until(QString input, QString end);
    QString getValue(QString input, QString key);

    /**
     *  其他SLOT槽函数
     */

    void onSteamPathChanged();
    void onCsgoPathChanged();
    void onLauncherPathChanged();
    void onSteamIDChanged();

};
#endif // MAINWINDOW_H
