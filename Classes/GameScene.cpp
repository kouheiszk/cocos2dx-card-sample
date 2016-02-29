//
//  GameScene.cpp
//  Sample
//
//  Created by Kouhei Suzuki on 2016/02/24.
//
//

#include "GameScene.hpp"
#include <random>

#define CARD_SUIT_TYPE_NUM 4 // カードの種類
#define CARD_NUM_OF_SUIT 13 // 1種類あたりのカード枚数

#define CARD_X_NUM 4 // 横方向のカードの枚数
#define CARD_Y_NUM 5 // 縦方向のカードの枚数
#define CARD_MARGIN 10 // カード間の最小間隔

#define CARD_SHOWING_ZORDER 1

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
    
    this->initGame();
    
    return true;
}

void Game::initGame()
{
    this->initCards();
    this->showInitCards();
}

void Game::initCards()
{
    // カードの全パターンを列挙
    std::vector<Card> cards;
    for (int type = 0; type < CARD_SUIT_TYPE_NUM; type++) {
        for (int number = 0; number < CARD_NUM_OF_SUIT; number++) {
            // カードを生成
            Card card;
            card.number = number;
            card.type = (CardType)type;
            
            // カードを追加
            cards.push_back(card);
        }
    }
    
    // 必要な枚数、組み合わせに絞る
    _cards.clear();
    for (int i = 0; i < CARD_X_NUM * CARD_Y_NUM / 2; i++) {
        std::random_device rd;
        std::mt19937 rand = std::mt19937(rd());
        
        int index = std::uniform_int_distribution<int>(0, (int)cards.size() - 1)(rand);
        auto card = cards[index];
        cards.erase(cards.begin() + index);
        
        // 神経衰弱なので同じカードを2枚しこむ
        _cards.push_back(card);
        _cards.push_back(card);
    }
}

Card Game::getCard()
{
    std::random_device rd;
    std::mt19937 rand = std::mt19937(rd());
    
    int index = std::uniform_int_distribution<int>(0, (int)_cards.size() - 1)(rand);
    auto card = _cards[index];
    _cards.erase(_cards.begin() + index);
    
    return card;
}

void Game::createCard(PositionIndex positionIndex, int tag)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    double cardScale = this->cardScale();
    
    auto card = Sprite::create("images/trump/z01.png");
    
    Size cardSize = Size(card->getContentSize().width * cardScale,
                         card->getContentSize().height * cardScale);
    
    card->setPosition(Vec2(origin.x + cardSize.width / 2 + positionIndex.x * cardSize.width + CARD_MARGIN * (positionIndex.x + 1),
                           origin.y + cardSize.height / 2 + positionIndex.y * cardSize.height + CARD_MARGIN * (positionIndex.y + 1)));
    card->setScaleX(cardScale);
    card->setScaleY(cardScale);
    card->setTag(tag);
    
    this->addChild(card, CARD_SHOWING_ZORDER);
}

void Game::showInitCards()
{
    for (int tag = 0; tag < CARD_X_NUM * CARD_Y_NUM; tag++) {
        auto card = this->getChildByTag(tag);
        if (card) {
            // カードが画面に残っている場合は消す
            card->removeFromParentAndCleanup(true);
        }
    }
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    for (int x = 0; x < CARD_X_NUM; x++) {
        for (int y = 0; y < CARD_Y_NUM; y++) {
            PositionIndex positionIndex;
            positionIndex.x = x;
            positionIndex.y = y;
            this->createCard(positionIndex, x + y);
        }
    }
}

double Game::cardScale()
{
    static double cardScale = 0;
    
    if (cardScale == 0) {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        auto card = Sprite::create("images/trump/z01.png");
        double scaleX = ((visibleSize.width - CARD_MARGIN * (CARD_X_NUM + 1)) / CARD_X_NUM) / card->getContentSize().width;
        double scaleY = ((visibleSize.height - CARD_MARGIN * (CARD_Y_NUM + 1)) / CARD_Y_NUM) / card->getContentSize().height;
        
        cardScale = MIN(scaleX, scaleY);
    }
    
    return cardScale;
}

