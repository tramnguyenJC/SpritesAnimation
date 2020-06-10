#ifndef PENCIL_H
#define PENCIL_H

#include "brush.h"

#include <QImage>
#include <QObject>
#include <QPainter>
#include <QRect>

class QString;

class Pencil : public Brush {
    Q_OBJECT
public:
    Pencil(const QString& brush_name);
    virtual ~Pencil() {}

    QRect mousePress(QPainter &painter, const QPoint &pos) override;
    QRect mouseMove(QPainter &painter, const QPoint &oldPos,
                            const QPoint &newPos) override;
    QRect mouseRelease(QPainter &painter, const QPoint &pos) override;
private:
    void setupPainter(QPainter& painter);
};

#endif // PENCIL_H
