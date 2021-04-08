#pragma once

#include <QLabel>
#include <QUrl>
#include <QtWebEngineWidgets/QWebEngineView>
#include <memory>

#include "Plugin.h"
namespace QtAV {
class WidgetRenderer;
}
class QLabel;
/**
 * 插件管理是一个单例对象，Ui 通过插件管理器从插件中获取数据
 */
class PluginManager : QObject {
    Q_OBJECT
private:
    PluginManager();

public:
    PluginManager(PluginManager&)  = delete;
    PluginManager(PluginManager&&) = delete;
    static PluginManager* instance();

    ~PluginManager();
    void SetWallPaper(const WallPaper::WallPaperItem item);
    void getWallPaperItem(WallPaper::Type);

private:
    static PluginManager* mInstance;
    QtAV::WidgetRenderer* video   = nullptr;
    QWebEngineView* webpage = nullptr;
};
