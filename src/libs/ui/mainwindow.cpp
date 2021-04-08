//
// Created by Drago on 2021/4/7.
//

#include "mainwindow.h"

#include <plugins/PluginManager.h>
#include <spdlog/spdlog.h>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {
    ui->setupUi(this);
    spdlog::set_level(spdlog::level::debug);
}
MainWindow::~MainWindow() { }

void MainWindow::on_pushButton_clicked() {
    auto manager = PluginManager::instance();
    //    WallPaper::WallPaperItem item("title", (R"(D:\Videos\1.mp4)"));
    WallPaper::WallPaperItem item("title", R"(https://www.baidu.com/)");
    //    WallPaper::WallPaperItem item("title", (R"(D:\Pictures\13.jpg)"));

    manager->SetWallPaper(item);
}
