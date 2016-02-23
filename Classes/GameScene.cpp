//
//  GameScene.cpp
//  Sample
//
//  Created by Kouhei Suzuki on 2016/02/24.
//
//

#include "GameScene.hpp"

USING_NS_CC;

Scene* Game::createScene()
{
    auto scene = Scene::create();
    auto layer = Game::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Game::init()
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
    // トランプ配置
    
    touchTrumpCards();
    
    return true;
}

void Game::touchTrumpCards()
{
    // カードの番号の取りうる値を設定する
    
    // numbersをシャッフルする
    
    // カードを4x4に配置する
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            //ランダムで1つの値を取得する
            int index = rand() % 52 + 1;
            
            //カードを生成する
            std::string normalCardImageName = StringUtils::format("images/trump/trump%03d.png", index);
            std::string highlightedCardImageName = StringUtils::format("images/trump/trump%03d.png", index);
            
            auto trumpCard = MenuItemImage::create(normalCardImageName,
                                                   highlightedCardImageName,
                                                   CC_CALLBACK_1(Game::trumpCardButtonCallback, this));
            trumpCard->setPosition(Vec2((x + 0.5) * 30 + 160, (y + 0.5) * 30));
            trumpCard->setScaleX(0.2);
            trumpCard->setScaleY(0.2);
            auto trumpCardMenu = Menu::create(trumpCard, NULL);
            trumpCardMenu->setPosition(Vec2::ZERO);
            trumpCardMenu->setTag(index);
            this->addChild(trumpCardMenu, 2);
        }
    }
}

void Game::trumpCardButtonCallback(Ref* pSender)
{
    // 開いてあるカードが無ければ、
    // 開いてあるカードとして保存
    // int openCardIndex = pSender->tag();
}