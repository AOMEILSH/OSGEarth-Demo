﻿#ifndef MAP_OSG_BASEVIEWER_H
#define MAP_OSG_BASEVIEWER_H

/// MAP_OSG_BaseViewer
/// 继承于QGLWidget->osgEarth::QtGui::ViewWidget的基本组件。
/// 由于需要控制刷新地图，因此通过MAP_OSG_ViewController创建和管理，而不是自己new。
/// 可以通过函数getView()获取osgViewer::View*来操作视图。
/// 参考MAP_OSG_ExampleWindow以使用该组件。

#include <osgEarthQt/ViewWidget>
#include <osgEarth/Terrain>

class MAP_OSG_LayerControlWidget;
#ifndef MAP_OSG_LAYERCONTROLWIDGET_H
#include "map_osg_layercontrolwidget.h"
#endif

class MAP_OSG_BaseViewer : public osgEarth::QtGui::ViewWidget
{
    Q_OBJECT

public:
    explicit MAP_OSG_BaseViewer(osgViewer::View* view, osg::GraphicsContext* gcToShare = nullptr);
    explicit MAP_OSG_BaseViewer(osgViewer::View* view, const QGLFormat& format);
    ~MAP_OSG_BaseViewer();

    void setControllWidget(MAP_OSG_LayerControlWidget *controller);

    /**
     * @brief getHeight
     * 获取经纬度对应的高度
     * @param longitude
     * 经度
     * @param latitude
     * 纬度
     * @return
     */
    double getHeight(double longitude, double latitude);

private:
    MAP_OSG_LayerControlWidget *m_controller;
};

#endif // MAP_OSG_BASEVIEWER_H
