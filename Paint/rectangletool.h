#include <shape.h>
class Line : public Shape {
public:
    Line() : m_start(QPointF(0, 0)), m_end(QPointF(0, 0)) {}

    Line(QPointF start, QPointF end) : m_start(start), m_end(end) {}

    void serializeToJson(QJsonObject& json) const override {
        json["type"] = "line";
        json["x1"] = m_start.x();
        json["y1"] = m_start.y();
        json["x2"] = m_end.x();
        json["y2"] = m_end.y();
        json["penColor"] = pen.color().name();
    }

    void deserializeFromJson(const QJsonObject& json) override {
        qDebug() << "Deserializing Line";
        if (json.contains("x1") && json.contains("y1") && json.contains("x2") && json.contains("y2")) {
            m_start.setX(json["x1"].toDouble());
            m_start.setY(json["y1"].toDouble());
            m_end.setX(json["x2"].toDouble());
            m_end.setY(json["y2"].toDouble());

            setPenColor(QColor(json["penColor"].toString()));
            qDebug() << "Deserialized Line: " << m_start << m_end;
        } else {
            qWarning() << "Invalid JSON format for Line object";
        }
    }

    Line(const QJsonObject& json) : Shape(json) {
        m_start = QPointF(json["x1"].toDouble(), json["y1"].toDouble());
        m_end = QPointF(json["x2"].toDouble(), json["y2"].toDouble());
        setPenColor(QColor(json["penColor"].toString()));
    }


    QRectF boundingRect() const {
        qreal penWidth = pen.widthF();
        return QRectF(m_start, m_end).normalized().adjusted(-penWidth, -penWidth, penWidth, penWidth);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        painter->setPen(pen);
        painter->drawLine(m_start, m_end);
    }

    void setPen(const QPen &newPen) {
        pen = newPen;
        update();
    }

private:
    QPen pen;
    QPointF m_start;
    QPointF m_end;
};
