#ifndef BRUSHFACTORY_H
#define BRUSHFACTORY_H

class Brush;
class QString;

class BrushFactory
{
public:
    virtual Brush* create(const QString& brush_name) = 0;
};

#define REGISTER_TYPE(klass) \
    class klass##Factory : public BrushFactory { \
    public: \
        klass##Factory() \
        { \
            Brush::registerType(#klass, this); \
        } \
        virtual Brush* create(const QString& brush_name) { \
            return new klass(brush_name); \
        } \
    }; \
    static klass##Factory global_##klass##Factory;
#endif // BRUSHFACTORY_H
