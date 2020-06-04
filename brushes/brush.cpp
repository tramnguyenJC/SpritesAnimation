#include "brush.h"

Brush::Brush(const QString& brush_name) : brush_name_(brush_name) {}

void Brush::registerType(const std::string& name, BrushFactory *factory){
    getBrushRegistry()[QString::fromUtf8(name.c_str())] = factory;
}

QStringList Brush::getBrushNames() {
    QStringList brush_names(getBrushRegistry().keys());
    return brush_names;
}

Brush* Brush::create(const QString& brush_name)
{
    return getBrushRegistry()[brush_name]->create(brush_name);
}
