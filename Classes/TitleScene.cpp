//
//  TitleScene.cpp
//  Sample
//
//  Created by Kouhei Suzuki on 2016/02/17.
//
//

#include "TitleScene.hpp"
#include "GameScene.hpp"

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
    
    /////////////////////////////
    // 背景
    
    auto backgroundImage = Sprite::create("images/background_title.jpg");
    backgroundImage->setPosition(Point(origin.x + visibleSize.width/2,
                                       origin.y + visibleSize.height/2));
    backgroundImage->setScaleX(visibleSize.width / backgroundImage->getContentSize().width);
    backgroundImage->setScaleY(visibleSize.height / backgroundImage->getContentSize().height);
    this->addChild(backgroundImage, -1);
    
    /////////////////////////////
    // タイトル
    
    auto label = Label::createWithTTF("ソリティア", "fonts/mplus-2c-light.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);
    
    /////////////////////////////
    // スタートボタン
    
    auto startButton = MenuItemImage::create("images/button_normal.png",
                                             "images/button_normal.png",
                                             CC_CALLBACK_1(Title::startButtonCallback, this));
    startButton->setPosition(Vec2(origin.x + visibleSize.width/2,
                                  origin.y + visibleSize.height/2));
    auto menu = Menu::create(startButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);
    
    return true;
}

void Title::startButtonCallback(Ref* pSender)
{
    auto gameScene = Game::createScene();
    Director::getInstance()->replaceScene(gameScene);
}