#ifndef BRUSH_H
#define BRUSH_H

#include <string>

#include <QMap>
#include <QObject>
#include <QStringList>

#include "brush_factory.h"

class QPainter;
class QPoint;
class QRect;
class QString;

class Brush : public QObject
{
    Q_OBJECT
public:

    Brush(const QString& brush_name);
    virtual ~Brush() {}

    inline virtual QString brushName() const { return brush_name_; }
    virtual QRect mousePress(QPainter &painter, const QPoint &pos) = 0;
    virtual QRect mouseMove(QPainter &painter, const QPoint &oldPos,
                            const QPoint &newPos) = 0;
    virtual QRect mouseRelease(QPainter &painter, const QPoint &pos) = 0;

    static void registerType(const std::string& name, BrushFactory *factory);
    static QStringList getBrushNames();
    static QMap<QString, BrushFactory*>& getBrushRegistry() {
        static QMap<QString, BrushFactory*> brush_registry;
        return brush_registry;
    }
    static Brush* create(const QString& brush_name);

private:
    QString brush_name_;
};

#endif // BRUSH_H
