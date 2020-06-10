#ifndef TEXTURE_BRUSH_H
#define TEXTURE_BRUSH_H

#include <QPixmap>
#include "brush.h"

class TextureBrush : public Brush {
    Q_OBJECT
public:
    TextureBrush(const QString& brush_name, QString pixmap_path);
    virtual ~TextureBrush() {}

    QRect mousePress(QPainter &painter, const QPoint &pos) override;
    QRect mouseMove(QPainter &painter, const QPoint &oldPos,
                            const QPoint &newPos) override;
    QRect mouseRelease(QPainter &painter, const QPoint &pos) override;
    void setBrushColor(const QColor& color) override;
    void setBrushTransparency(double transparency) override;
    void setBrushWidth(int width) override;

private:
    void changePixmapColor();
    void setupPainter(QPainter& painter);
    void drawLine(QPainter &painter, const QPoint &oldPos,
                  const QPoint &newPos);
//    double distance(const QPoint &from, const QPoint &to);

//    QPoint nextPointWithinDistance(const QPoint& from, double distance);

    QPixmap* pixmap_;

};

#endif // TEXTURE_BRUSH_H
