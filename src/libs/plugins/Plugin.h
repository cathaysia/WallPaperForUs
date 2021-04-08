#pragma once

#include <QtPlugin>
#include <utility>

namespace WallPaper {
/*
 * WallPaperItem: 第一个参数代表壁纸的标题，第二个参数代表壁纸的地址
 */
typedef std::pair<QString, QString> WallPaperItem;

/**
 * 壁纸的类型：
 * Image = 0
 * Video = 2
 * HTML = 4
 * ALL = Image | Video | HTML
 */
enum class Type : uint8_t { Image = 0, Video = 2, HTML = 4, ALL = Image | Video | HTML };
}    // namespace WallPaper

class PluginInterface {
public:
    virtual QList<WallPaper::WallPaperItem> Query(const QString name) const = 0;
    virtual WallPaper::WallPaperItem        OnNext() const                  = 0;
    virtual QWidget*                        Settings()                      = 0;
    virtual bool                            OnInit()                        = 0;
    virtual void                            OnClose() noexcept              = 0;
    virtual QIcon                           icon()                          = 0;
    virtual ~PluginInterface()                                              = 0;
};
