#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "diagramitem.h"

#include <QMainWindow>

class DiagramScene;

QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();
 private slots:
     void backgroundButtonGroupClicked(QAbstractButton *button);
     void buttonGroupClicked(int id);
     void deleteItem();
     void pointerGroupClicked(int id);
     void bringToFront();
     void sendToBack();
     void itemInserted(DiagramItem *item);
     void textInserted(QGraphicsTextItem *item);
     void currentFontChanged(const QFont &font);
     void fontSizeChanged(const QString &size);
     void sceneScaleChanged(const QString &scale);
     void textColorChanged();
     void itemColorChanged();
     void lineColorChanged();
     void textButtonTriggered();
     void fillButtonTriggered();
     void lineButtonTriggered();
     void handleFontChange();
     void itemSelected(QGraphicsItem *item);
     void about();
private:
    void createToolBox();
    void createActions();
    void createMenus();
    void createToolbars();

    QMenu *createColorMenu(const char *slot, QColor defaultColor);
    QIcon createColorToolButtonIcon(const QString &image, QColor color);
    QIcon createColorIcon(QColor color);
    QWidget *createCellWidget(const QString &text,
                              DiagramItem::DiagramType type);
    QWidget *createBackgroundCellWidget(const QString &text,
                                        const QString &image);
    DiagramScene *scene;
    QGraphicsView *view;

    QAction *exitAction;
    QAction *addAction;
    QAction *deleteAction;

    QAction *toFrontAction;
    QAction *sendBackAction;
    QAction *aboutAction;

    QMenu *fileMenu;
    QMenu *itemMenu;
    QMenu *aboutMenu;

    QToolBar *textToolBar;
    QToolBar *editToolBar;
    QToolBar *colorToolBar;
    QToolBar *pointerToolbar;

    QComboBox *sceneScaleCombo;
    QComboBox *itemColorCombo;
    QComboBox *textColorCombo;
    QComboBox *fontSizeCombo;
    QFontComboBox *fontCombo;

    QToolBox *toolBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *pointerTypeGroup;
    QButtonGroup *backgroundButtonGroup;
    QToolButton *fontColorToolButton;
    QToolButton *fillColorToolButton;
    QToolButton *lineColorToolButton;
    QAction *boldAction;
    QAction *underlineAction;
    QAction *italicAction;
    QAction *textAction;
    QAction *fillAction;
    QAction *lineAction;
};
#endif // MAINWINDOW_H

