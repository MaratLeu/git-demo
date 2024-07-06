#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

#include <shape.h>
#include <rectangle.h>
#include <oval.h>
#include <rhombus.h>
#include <rectangletool.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
class paintScene : public QGraphicsScene
{
public:
    enum DrawingMode {
        DRAWING_NONE,
        DRAWING_RECTANGLE,
        DRAWING_OVAL,
        DRAWING_RHOMBUS,
        DRAWING_LINE
    };

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
    void setPenColor(const QColor& color);
    void serializeToJson(QJsonObject& json) const;
    void deserializeFromJson(const QJsonObject& json);
    QColor penColor() const;
    DrawingMode drawingMode;

private:
    QPointF previousPoint;
    Shape* drawingShape;
    QPen pen;
    QVector<Line*> lines;


public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};
#endif // PAINTSCENE\_H
