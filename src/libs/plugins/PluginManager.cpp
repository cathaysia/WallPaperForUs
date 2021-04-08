#include "PluginManager.h"

#include <WidgetRenderer.h>
#include <spdlog/spdlog.h>

#include <QtAV>
#include <QtAVWidgets>

namespace win {
#include <Windows.h>
}

QStringList PICTURE { QStringLiteral("png"), QStringLiteral("jpg"), QStringLiteral("tif") };
QStringList VIDEO { QStringLiteral("mp4"), QStringLiteral("avi"), QStringLiteral("flv") };
bool isImage(const WallPaper::WallPaperItem& item) {
    for(auto& format: PICTURE) {
        if(item.second.endsWith(format)) return true;
    }
    return false;
}
bool isVideo(const WallPaper::WallPaperItem& item) {
    for(auto& format: VIDEO) {
        if(item.second.endsWith(format)) return true;
    }
    return false;
}

void setFather(QWidget* obj) {
    obj->setWindowFlag(Qt::FramelessWindowHint);
    auto handle = FindWindow("Progman", nullptr);
    spdlog::debug("window hand is {}", (long long)handle);
    SetParent((HWND)obj->winId(), handle);
    obj->setGeometry(0, 0, 1920, 1080);
    obj->show();
}

PluginManager::PluginManager() { }

PluginManager* PluginManager::mInstance = nullptr;
PluginManager* PluginManager::instance() {
    if(!mInstance) mInstance = new PluginManager;
    return mInstance;
}

PluginManager::~PluginManager() {
    if(video) {
        delete video;
        video = nullptr;
    }
    if(webpage) {
        delete webpage;
        webpage = nullptr;
    }
}

void PluginManager::getWallPaperItem(WallPaper::Type) { }

void PluginManager::SetWallPaper(const WallPaper::WallPaperItem item) {
    // item->second 代表的 url 这里认为必定有效
    spdlog::info("{} will be displayer", item.second.toStdString());
    // 首先判断壁纸的类型
    if(isImage(item)) {
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (PVOID)item.second.toStdString().c_str(),
                              SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
    } else if(isVideo(item)) {
        if(!this->video) {
            // 先删除 this->video 以防止 player 发生内存泄漏
            delete this->video;
            this->video = new QtAV::WidgetRenderer;
        }
        auto player = new QtAV::AVPlayer(this->video->widget());
        //  使用硬件加速
        player->setVideoDecoderPriority(QStringList() << "D3D11");
        player->addVideoRenderer(this->video);
        player->play(item.second);
        // HOOK 到壁纸

        setFather(video->widget());
        // 删除以前的壁纸
        if(this->webpage) {
            delete webpage;
            webpage = nullptr;
        }

    } else {
        // 判断网页的 URL 是否合法
        // 这里不应该在这里检查
        if(!QUrl(item.second).isValid()) {
            spdlog::info("url {} invalid", item.second.toStdString());
            return;
        }
        // 这就代表是网页了
        webpage = new QWebEngineView;
        webpage->load(item.second);
        // 这里用 connect 保证观感
        connect(this->webpage, &QWebEngineView::loadFinished, [this]() {
            setFather(webpage);
        });
        // 删除以前的壁纸
        if(video) {
            delete video;
            video = nullptr;
        }
    }
}
