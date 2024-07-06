#include "paintscene.h"
#include <QFile>
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent), pen(Qt::red, 2), drawingMode (DRAWING_NONE), drawingShape(nullptr), lines()
{
}

paintScene::~paintScene()
{
    delete drawingShape;
    drawingShape = nullptr;
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    delete drawingShape;
    drawingShape = nullptr;

    if (drawingMode == DRAWING_NONE) {
        return;
    }

    switch (drawingMode) {
    case DRAWING_RECTANGLE:
        drawingShape = new Rectangle(event->scenePos(), 0, 0);
        drawingShape->setPenColor(pen.color());
        break;
    case DRAWING_OVAL:
        drawingShape = new Oval(event->scenePos(), 0, 0);
        drawingShape->setPenColor(pen.color());
        break;
    case DRAWING_RHOMBUS:
        drawingShape = new Rhombus(event->scenePos(), 0, 0);
        drawingShape->setPenColor(pen.color());
        break;
    case DRAWING_LINE:
        lines.append(new Line(previousPoint, event->scenePos()));
        lines.last()->setPen(pen);
        addItem(lines.last());
        previousPoint = event->scenePos();
        break;
    }

    if (drawingShape != nullptr) {
        addItem(drawingShape);
        previousPoint = event->scenePos();
    }

    QGraphicsScene::mousePressEvent(event);
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (drawingShape != nullptr) {
        QPointF currentPos = event->scenePos();
        QPointF delta;
        delta.setX(currentPos.x() - previousPoint.x());
        delta.setY(currentPos.y() - previousPoint.y());

        if (delta.x() < 0) {
            delta.setX(-qAbs(delta.x()));
        } else {
            delta.setX(qAbs(delta.x()));
        }

        if (delta.y() < 0) {
            delta.setY(-qAbs(delta.y()));
        } else {
            delta.setY(qAbs(delta.y()));
        }

        switch (drawingMode) {
        case DRAWING_RECTANGLE:
            drawingShape->setSize(delta.x(), delta.y());
            break;
        case DRAWING_OVAL:
            drawingShape->setSize(delta.x(), delta.y());
            break;
        case DRAWING_RHOMBUS:
            drawingShape->setSize(delta.x(), delta.y());
            break;
        case DRAWING_LINE:
            removeItem(lines.last());
            lines.last() = new Line(previousPoint, event->scenePos());
            lines.last()->setPen(pen);
            addItem(lines.last());
            break;
        default:
            break;
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}


void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    drawingShape = nullptr;
    update();
    QGraphicsScene::mouseReleaseEvent(event);
}

void paintScene::setPenColor(const QColor& color) {
    pen.setColor(color);
}

QColor paintScene::penColor() const {
    return pen.color();
}


void paintScene::serializeToJson(QJsonObject& json) const {
    QJsonArray shapesArray;
    for (const auto& shape : items()) {
        QJsonObject shapeJson;
        if (auto rectangle = qgraphicsitem_cast<Rectangle*>(shape)) {
            rectangle->serializeToJson(shapeJson);
        } else if (auto oval = qgraphicsitem_cast<Oval*>(shape)) {
            oval->serializeToJson(shapeJson);
        } else if (auto rhombus = qgraphicsitem_cast<Rhombus*>(shape)) {
            rhombus->serializeToJson(shapeJson);

        } else if (auto line = qgraphicsitem_cast<Line*>(shape)) {
            line->serializeToJson(shapeJson);
        }
        shapesArray.append(shapeJson);
    }
    json["shapes"] = shapesArray;
    json["penColor"] = penColor().name();
    json["drawingMode"] = static_cast<int>(drawingMode);
}

void paintScene::deserializeFromJson(const QJsonObject& json) {
    clear();
    QJsonArray shapesArray = json["shapes"].toArray();
    for (const auto& shapeValue : shapesArray) {
        QJsonObject shapeJson = shapeValue.toObject();
        QString type = shapeJson["type"].toString();
        Shape* shape = nullptr;

        qDebug() << "Shape type:" << type;

        if (type == "rectangle") {
            shape = new Rectangle;
        } else if (type == "oval") {
            shape = new Oval;
        } else if (type == "rhombus") {
            shape = new Rhombus;
        } else if (type == "line") {
            shape = new Line;
        }

        if (shape) {
            shape->deserializeFromJson(shapeJson);
            addItem(shape);
        } else {
            qWarning() << "Unknown shape type:" << type;
        }
    }

    if (json.contains("penColor")) {
        setPenColor(QColor(json["penColor"].toString()));
    }

    if (json.contains("drawingMode")) {
        drawingMode = static_cast<DrawingMode>(json["drawingMode"].toInt());
    }
}



