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
    int xMax = 4;
    int yMax = 4;
    float cardMargin = 10;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // カードの番号の取りうる値を設定する
    std::vector<int> numbers;
    for (int i = 1; i <= 52; i++) {
        numbers.push_back(i);
    }
    
    // カードを配置する
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            //ランダムで1つの値を取得する
            int index = arc4random() % numbers.size();
            
            //カードを生成する
            std::string normalCardImageName = StringUtils::format("images/trump/trump%03d.png", numbers[index]);
            std::string highlightedCardImageName = StringUtils::format("images/trump/trump%03d.png", numbers[index]);
            auto trumpCard = MenuItemImage::create(normalCardImageName,
                                                   highlightedCardImageName,
                                                   CC_CALLBACK_1(Game::trumpCardButtonCallback, this));
            
            double xCardScale = ((visibleSize.width - cardMargin * (xMax + 1)) / xMax) / trumpCard->getContentSize().width;
            double yCardScale = ((visibleSize.height - cardMargin * (yMax + 1)) / yMax) / trumpCard->getContentSize().height;
            double cardScale = MIN(xCardScale, yCardScale);
            Size cardSize = Size(trumpCard->getContentSize().width * cardScale,
                                 trumpCard->getContentSize().height * cardScale);
            trumpCard->setScaleX(cardScale);
            trumpCard->setScaleY(cardScale);
            
            trumpCard->setPosition(Point(origin.x + cardSize.width / 2 + x * cardSize.width + cardMargin * (x + 1),
                                         origin.y + cardSize.height / 2 + y * cardSize.height + cardMargin * (y + 1)));
            
            
            auto trumpCardMenu = Menu::create(trumpCard, NULL);
            trumpCardMenu->setPosition(Vec2::ZERO);
            trumpCardMenu->setTag(index);
            
            this->addChild(trumpCardMenu, 2);
            
            // 数値配列から値を削除する
            numbers.erase(numbers.begin() + index);
        }
    }
}

void Game::trumpCardButtonCallback(Ref* pSender)
{
    // 開いてあるカードが無ければ、
    // 開いてあるカードとして保存
    // int openCardIndex = pSender->tag();
}