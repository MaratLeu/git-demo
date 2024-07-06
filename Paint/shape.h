#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QJsonArray>
#include <QJsonObject>
class Shape : public QGraphicsItem
{
public:
    Shape(const QPointF& pos, qreal width, qreal height) : m_pos(pos), m_width(width), m_height(height), pen(Qt::blue) {}
    Shape() {}
    Shape(const QJsonObject& json);
    QRectF boundingRect() const override {
        return QRectF(m_pos, QSizeF(m_width, m_height));
    }
    void setPosition(QPointF position);
    void setSize(qreal x, qreal y);
    virtual void setPenColor(const QColor& color);
    QPen getPenColor() const;
    virtual void serializeToJson(QJsonObject& json) const;
    virtual void deserializeFromJson(const QJsonObject& json) = 0;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPointF m_pos;
    qreal m_width;
    qreal m_height;
public:
    QPen pen;
};

#endif // SHAPE_H
