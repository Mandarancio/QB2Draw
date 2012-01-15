#include "qb2draw.h"
#include <qglobal.h>

#include <QPen>
//LINE ALPHA
#define ALPHA 100
//LINE WIDTH
#define WIDTH 4


QB2Draw::QB2Draw(QRect displayGeometry,QPainter *p)
{
    this->geometry=displayGeometry; //Set the display geometry (for convert the coordinate system)
    this->painter=p; //For setting the painter
}

void QB2Draw::setPainter(QPainter *p){
    painter=p;//Set the painter
}

void QB2Draw::updateGeometry(QRect displayGeometry){
    geometry=displayGeometry;//For update the geometry (ex:resizing of the windows)
}

void QB2Draw::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color){
    if (painter==NULL) return; //Check the painter

    QColor c=toQColor(color); //Convert the color
    QPen pen;//Configure the pen
    pen.setBrush(c); //Set the pen color
    pen.setWidth(WIDTH); //Set pen width
    painter->setPen(pen); //Assign the pen
    painter->setBrush(Qt::transparent); //Set brush trasparent
    QPolygon pol; //Calculate the polygon
    for (int i=0;i<vertexCount;i++){ //Add all points to the polygon
        pol.insert(i,toQPoint(vertices[i]));
    }
    painter->drawPolyline(pol); //Draw the polyline
}

void QB2Draw::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color){
    if (painter==NULL) return; //Check the painter

    QColor c=toQColor(color); //Convert the color
    painter->setPen(c); //set the pen color
    painter->setBrush(c); //set the brush color
    QPolygon pol; //Calculate the polygon
    for (int i=0;i<vertexCount;i++){ //Add all points to polygon
        pol.insert(i,toQPoint(vertices[i]));
    }
    painter->drawPolygon(pol); //Draw the polygon
}

void QB2Draw::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color){
    if (painter==NULL) return; //Check the painter

    QColor c=toQColor(color); //Convert the color
    painter->setPen(c); //Set pen color
    painter->setBrush(Qt::transparent); //set brush color
    painter->drawEllipse(toQPoint(center),qRound(radius),qRound(radius)); //draw circonference
}

void QB2Draw::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color){
    //What is axis??
    if (painter==NULL) return; //Check the painter
    QColor c=toQColor(color); //Convert the color
    painter->setPen(c); //set pen color
    painter->setBrush(c); //set brush color
    painter->drawEllipse(toQPoint(center),qRound(radius),qRound(radius)); //Draw circle
}

void QB2Draw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color){
    if (painter==NULL) return; //Check if painter is setted
    QColor c=toQColor(color); //set color
    //c.setAlpha(ALPHA); //set alpha
    QPen pen;//Configure the pen
    pen.setBrush(c); //Set the pen color
    pen.setWidth(WIDTH); //Set pen width
    painter->setPen(pen); //Assign the pen
    painter->drawLine(toQPoint(p1),toQPoint(p2)); //Draw the line
}

void QB2Draw::DrawTransform(const b2Transform &xf){
    painter->translate(toQPoint(xf.p)); //Translate
    painter->rotate(xf.q.GetAngle()*180.0/3.141628); //Rotate
}

QColor QB2Draw::toQColor(b2Color color){
    return QColor(color.r,color.g,color.b); //Convert color
}

QPoint QB2Draw::toQPoint(b2Vec2 vec){
    QPoint p(-vec.x,vec.y); //Convert in qpoint
    return geometry.center()-p; //change the coordinate system
}
