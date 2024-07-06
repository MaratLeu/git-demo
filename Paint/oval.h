#ifndef OVAL_H
#define OVAL_H

#include <shape.h>
#include <QPainter>
class Oval : public Shape
{
public:
    Oval() {}
    Oval(const QPointF& pos, qreal width, qreal height) : Shape(pos, width, height) {}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setPenColor(const QColor &color) override;
    virtual void serializeToJson(QJsonObject& json) const override;
    virtual void deserializeFromJson(const QJsonObject& json) override;
};


#endif // OVAL_H
