//
//  TitleScene.cpp
//  Sample
//
//  Created by Kouhei Suzuki on 2016/02/17.
//
//

#include "TitleScene.hpp"

USING_NS_CC;

Scene* Title::createScene()
{
    auto scene = Scene::create();
    auto layer = Title::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Title::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto backgroundImage = Sprite::create("background_title.jpg");
    backgroundImage->setPosition(Point(origin.x + visibleSize.width/2,
                                       origin.y + visibleSize.height/2));
    backgroundImage->setScaleX(visibleSize.width / backgroundImage->getContentSize().width);
    backgroundImage->setScaleY(visibleSize.height / backgroundImage->getContentSize().height);
    this->addChild(backgroundImage, -1);
    
    auto label = Label::createWithTTF("ソリティア", "fonts/mplus-2c-light.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    this->addChild(label, 1);
    
    return true;
}