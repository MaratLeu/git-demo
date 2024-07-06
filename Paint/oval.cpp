#include "oval.h"

void Oval::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter -> setPen(pen);
    painter -> drawEllipse(boundingRect());
}

void Oval::setPenColor(const QColor &color) {
    pen.setColor(color);
}

void Oval::serializeToJson(QJsonObject& json) const {
    Shape::serializeToJson(json);
    json["type"] = "oval";
}

void Oval::deserializeFromJson(const QJsonObject& json) {
    Shape::deserializeFromJson(json);
}
