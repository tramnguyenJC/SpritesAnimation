#ifndef BRUSH_COLLECTION_H
#define BRUSH_COLLECTION_H

#include <QMap>

#include "brush.h"

class BrushCollection {
public:
    static QMap<QString, Brush*>& getBrushCollection();

    static Brush* getBrush(const QString& brush_name) {
        return getBrushCollection()[brush_name];
    }
    static const QString DEFAULT_BRUSH_NAME;
private:
    BrushCollection();
    static void addTextureBrushToCollection(
            QMap<QString, Brush*>& brush_collection);
};

#endif // BRUSH_COLLECTION_H
