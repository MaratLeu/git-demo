#include "rectangle.h"

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter -> setPen(pen);
    painter -> drawRect(boundingRect());
}

void Rectangle::setPenColor(const QColor &color) {
    pen.setColor(color);
}

void Rectangle::serializeToJson(QJsonObject& json) const {
    Shape::serializeToJson(json);
    json["type"] = "rectangle";
}

void Rectangle::deserializeFromJson(const QJsonObject& json) {
    Shape::deserializeFromJson(json);
}
