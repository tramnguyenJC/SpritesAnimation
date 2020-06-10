#include "brush_collection.h"

#include "pencil.h"
#include "eraser.h"
#include "texture_brush.h"

#include <QDebug>
const QString BrushCollection::DEFAULT_BRUSH_NAME = QString("Pencil");

BrushCollection::BrushCollection() {}

QMap<QString, Brush*>& BrushCollection::getBrushCollection()
{
    static QMap<QString, Brush*> brush_collection;
    if (brush_collection.empty()) {
        brush_collection.insert("Pencil", new Pencil("Pencil"));
        brush_collection.insert("Eraser", new Eraser("Eraser"));
        addTextureBrushToCollection(brush_collection);
    }
    return brush_collection;
}

void BrushCollection::addTextureBrushToCollection(
        QMap<QString, Brush*>& brush_collection)
{
    Brush* fluffy_watercolor = new TextureBrush("Fluffy Watercolor",
                                ":/images/brushpatterns/fluffy_watercolor.png");
    brush_collection.insert(fluffy_watercolor->brushName(), fluffy_watercolor);

    Brush* fluffy_watercolor_2 = new TextureBrush(
                "Fluffy Watercolor 2", ":/images/brushpatterns/fluffy_watercolor_2.png");
    brush_collection.insert(fluffy_watercolor_2->brushName(),
                            fluffy_watercolor_2);

    Brush* leaf = new TextureBrush("Leaf",
                                ":/images/brushpatterns/leaf.png");
    brush_collection.insert(leaf->brushName(), leaf);

    Brush* basket_hatching_brush = new TextureBrush(
                "Basket Hatching Brush",
                ":/images/brushpatterns/basket_hatching_brush.png");
    brush_collection.insert(basket_hatching_brush->brushName(),
                            basket_hatching_brush);

    Brush* flat_brush = new TextureBrush("Flat Brush",
                                ":/images/brushpatterns/flat_brush.png");
    brush_collection.insert(flat_brush->brushName(),
                            flat_brush);

    Brush* flat_brush_dry = new TextureBrush("Flat Brush",
                                ":/images/brushpatterns/flat_brush_dry.png");
    brush_collection.insert(flat_brush_dry->brushName(),
                            flat_brush_dry);

    Brush* flat_brush_wet = new TextureBrush("Flat Brush",
                                ":/images/brushpatterns/flat_brush_wet.png");
    brush_collection.insert(flat_brush_wet->brushName(),
                            flat_brush_wet);

    Brush* oil_paint = new TextureBrush("Oil Paint",
                                ":/images/brushpatterns/oil_paint.png");
    brush_collection.insert(oil_paint->brushName(),
                            oil_paint);

    Brush* watercolor = new TextureBrush("Watercolor",
                                ":/images/brushpatterns/watercolor.png");
    brush_collection.insert(watercolor->brushName(),
                            watercolor);

    Brush* acrylic_wet = new TextureBrush("Acrylic Wet",
                                ":/images/brushpatterns/acrylic_wet.png");
    brush_collection.insert(acrylic_wet->brushName(),
                            acrylic_wet);

    Brush* acrylic = new TextureBrush("Acrylic",
                                ":/images/brushpatterns/acrylic.png");
    brush_collection.insert(acrylic->brushName(),
                            acrylic);

    Brush* airbrush = new TextureBrush("Airbrush",
                                ":/images/brushpatterns/airbrush.png");
    brush_collection.insert(airbrush->brushName(),
                            airbrush);

    Brush* splatter = new TextureBrush("Splatter",
                                ":/images/brushpatterns/splatter.png");
    brush_collection.insert(splatter->brushName(),
                            splatter);




}
