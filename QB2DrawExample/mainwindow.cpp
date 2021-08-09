#include "mainwindow.h"
#include <QTimer>
#include <QPaintEvent>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(700,500);


    world=new b2World(b2Vec2(0,-100)); //b2World object
    world->SetContinuousPhysics(true); //Some flag
    draw=new QB2Draw(this->geometry());//Create the drawer

    uint32 flags = 0;//Set the flags
    flags += 1	* b2Draw::e_shapeBit;
    flags += 1	* b2Draw::e_jointBit;

    draw->SetFlags(flags); //Set drawer flags
    world->SetDebugDraw(draw); //Set the drawer in the world

    QTimer *t=new QTimer(this); //Timer refresh
    t->start(1.0/30.0*1000.0); //30fps
    connect(t,SIGNAL(timeout()),this,SLOT(repaint()));//Repaint windows evry timer clock

    //Define some bodies
    b2BodyDef def;
    def.type=b2_dynamicBody;
    def.position.Set(30,300);
    b2Body *body=world->CreateBody(&def);//First circle
    b2CircleShape shape;
    shape.m_p.SetZero();
    shape.m_radius=10;
    b2FixtureDef fd;
    fd.density=1.0;
    fd.restitution=0.5;
    fd.shape=&shape;
    body->CreateFixture(&fd);


    def.position.Set(100,300);
    b2Body* body3=world->CreateBody(&def);//Second circle
    body3->CreateFixture(&shape,1.0);
    def.type=b2_staticBody;
    def.position.Set(130,90);
    def.angle=0.3;
    b2PolygonShape sh;
    sh.SetAsBox(100,10,b2Vec2(0,0),0);

    b2Body * body2=world->CreateBody(&def);//Set the box
    body2->CreateFixture(&sh,0.0);

    b2DistanceJointDef jd;//Set up the joint
    jd.Initialize(body3,body,body3->GetPosition(),body->GetPosition());
    world->CreateJoint(&jd);

}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter p(this);//Create the painter
    p.setRenderHint(QPainter::Antialiasing);
    draw->setPainter(&p); //Assign the painter at the drawer
    world->Step(1.0/30.0,10,10); //Update world
    world->DebugDraw(); //Draw world
    if (p.end()) e->accept(); //Close painter
}
