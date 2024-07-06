#include "rhombus.h"

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widhet) {
    QPolygonF rhombus;
    rhombus << QPointF(boundingRect().center().x(), boundingRect().top())
            << QPointF(boundingRect().right(), boundingRect().center().y())
            << QPointF(boundingRect().center().x(), boundingRect().bottom())
            << QPointF(boundingRect().left(), boundingRect().center().y());

    painter -> setPen(pen);
    painter -> drawPolygon(rhombus);
}

void Rhombus::setPenColor(const QColor &color) {
    pen.setColor(color);
}

void Rhombus::serializeToJson(QJsonObject& json) const {
    Shape::serializeToJson(json);
    json["type"] = "rhombus";
}

void Rhombus::deserializeFromJson(const QJsonObject& json) {
    Shape::deserializeFromJson(json);
}
