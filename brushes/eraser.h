#ifndef ERASER_H
#define ERASER_H

#include "brush.h"

#include <QImage>
#include <QObject>
#include <QPainter>
#include <QRect>

class QString;

class Eraser : public Brush {
    Q_OBJECT
public:
    Eraser(const QString& brush_name);
    virtual ~Eraser() {}

    QRect mousePress(QPainter &painter, const QPoint &pos) override;
    QRect mouseMove(QPainter &painter, const QPoint &oldPos,
                            const QPoint &newPos) override;
    QRect mouseRelease(QPainter &painter, const QPoint &pos) override;
private:
    void setupPainter(QPainter &painter);
};
#endif // ERASER_H
