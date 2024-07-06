#include "shape.h"
#include <rectangle.h>
#include <oval.h>
#include <rhombus.h>
void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::red, 2));
    painter->setBrush(Qt::blue);

    if (dynamic_cast<Rectangle*>(this) != nullptr) {

        painter->drawRect(boundingRect());
    } else if (dynamic_cast<Oval*>(this) != nullptr) {

        painter->drawEllipse(boundingRect());
    } else if (dynamic_cast<Rhombus*>(this) != nullptr) {

        QPolygonF rhombus;
        rhombus << QPointF(boundingRect().center().x(), boundingRect().top())
                << QPointF(boundingRect().right(), boundingRect().center().y())
                << QPointF(boundingRect().center().x(), boundingRect().bottom())
                << QPointF(boundingRect().left(), boundingRect().center().y());
        painter->drawPolygon(rhombus);
    }
}

void Shape::setPosition(QPointF position) {
    this -> m_pos = position;
}

void Shape::setSize(qreal x, qreal y) {
    prepareGeometryChange();
    m_width = qAbs(x);
    m_height = qAbs(y);
    if (x < 0) m_pos.setX(m_pos.x() + x);
    if (y < 0) m_pos.setY(m_pos.y() + y);

}

void Shape::setPenColor(const QColor &color) {
    pen.setColor(color);
}

QPen Shape::getPenColor() const {
    return pen;
}

void Shape::serializeToJson(QJsonObject& json) const {
    json["position"] = QJsonArray({m_pos.x(), m_pos.y()});
    json["size"] = QJsonArray({m_width, m_height});
    json["penColor"] = pen.color().name();
}

void Shape::deserializeFromJson(const QJsonObject& json) {
    if (json.contains("position")) {
        QJsonArray positionArray = json["position"].toArray();
        m_pos = QPointF(positionArray[0].toDouble(), positionArray[1].toDouble());
    }

    if (json.contains("size")) {
        QJsonArray sizeArray = json["size"].toArray();
        m_width = sizeArray[0].toDouble();
        m_height = sizeArray[1].toDouble();
    }

    if (json.contains("penColor")) {
        QColor penColor = QColor(json["penColor"].toString());
        pen.setColor(penColor);
    }
}

Shape::Shape(const QJsonObject& json) {
    QJsonArray positionArray = json["position"].toArray();
    m_pos = QPointF(positionArray[0].toDouble(), positionArray[1].toDouble());

    QJsonArray sizeArray = json["size"].toArray();
    m_width = sizeArray[0].toDouble();
    m_height = sizeArray[1].toDouble();

    QColor penColor = QColor(json["penColor"].toString());
    pen.setColor(penColor);
}



