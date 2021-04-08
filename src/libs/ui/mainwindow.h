#pragma once
#include <QMainWindow>

namespace Ui{
class MainWindow;
}
/**
 * 这里我假定壁纸有两种壁纸： 在线壁纸和本地壁纸。然后增加筛选按钮：静态壁纸、视频壁纸和网页壁纸
 * 除了静态壁纸外，视频壁纸和网页壁纸可以 发出/禁止 声音
 *
 *
 */
class MainWindow final : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
