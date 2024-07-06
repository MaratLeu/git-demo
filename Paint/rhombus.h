#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <shape.h>
#include <QPainter>
class Rhombus : public Shape
{
public:
    Rhombus() {}
    Rhombus(const QPointF& pos, qreal width, qreal height): Shape(pos, width, height) {}
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widhet = nullptr) override;
    void setPenColor(const QColor &color);
    virtual void serializeToJson(QJsonObject& json) const override;
    virtual void deserializeFromJson(const QJsonObject& json) override;
};

#endif // RHOMBUS_H
