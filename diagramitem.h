#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QVector>

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsSceneContextMenuEvent;
class QMenu;
class QPolygonF;
QT_END_NAMESPACE

class Arrow;
//QGraphicsPolygonItem类提供了多边形项，可以将其添加到QGraphicScene中
class DiagramItem : public QGraphicsPolygonItem
{
public:
    enum { Type = UserType + 15 };
    enum DiagramType { Step, Conditional, StartEnd, Io };

    DiagramItem(DiagramType diagramType, QMenu *contextMenu, QGraphicsItem *parent = nullptr);

    void removeArrow(Arrow *arrow);
    void removeArrows();
    DiagramType diagramType() const { return myDiagramType; }
    QPolygonF polygon() const { return myPolygon; }
    void addArrow(Arrow *arrow);
    QPixmap image() const;
    int type() const override { return Type; }

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    //对于一个Item来说，我们需要知道它的形状，各个点的值，右键菜单，连接情况
    //图形类型，只是我们前面自己定义的枚举量
    DiagramType myDiagramType;
    //点的数据集合QVector<QPointF>
    QPolygonF myPolygon;
    //右键菜单
    QMenu *myContextMenu;
    //Item与其他ITem的连接关系
    QVector<Arrow *> arrows;
};

#endif // DIAGRAMITEM_H
