#ifndef QB2DRAW_H
#define QB2DRAW_H
#include <QObject>
#include <QPainter>
#include <box2d/box2d.h>

class QB2Draw : public b2Draw, QObject
{

public:
    QB2Draw(QRect displayGeometry,QPainter * p=NULL); //Constructor: Display geometry and painter

    //void setScale(float sx=1.0, float sy=1.0); TODO
    void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color); //Draw a polyline
    void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color); //Draw a polygone
    void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color); //Draw a circonference
    void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color); //Draw a circle
    void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color); //Draw a line
    void DrawTransform(const b2Transform &xf); //Set a transformate (translate and rotate)
    void DrawPoint(const b2Vec2& p, float size, const b2Color& color); // Draw a point

private:
    QPainter * painter; //The painter
    QRect geometry; //The geometry

    QPoint toQPoint(b2Vec2 vec); //To convert b2vec2 in QPoint (and also change the coordinate system)
    QColor toQColor(b2Color color); //To convert b2Color in QColor

public slots:
    void updateGeometry(QRect displayGeometry); //Update the geometry
    void setPainter(QPainter * p); //Set the painter
};

#endif // QB2DRAW_H

