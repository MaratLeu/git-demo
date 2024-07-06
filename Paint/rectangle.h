#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <shape.h>
class Rectangle : public Shape
{
public:
    Rectangle() {}
    Rectangle(const QPointF& pos, qreal width, qreal height) : Shape(pos, width, height) {}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setPenColor(const QColor &color) override;
    virtual void serializeToJson(QJsonObject& json) const override;
    virtual void deserializeFromJson(const QJsonObject& json) override;
};

#endif // RECTANGLE_H
