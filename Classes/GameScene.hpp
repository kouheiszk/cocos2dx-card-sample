//
//  GameScene.hpp
//  Sample
//
//  Created by Kouhei Suzuki on 2016/02/24.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "cocos2d.h"

enum CardType
{
    Clubs = 0,
    Diamonds,
    Hearts,
    Spades
};

struct Card
{
    int number;
    CardType type;
};

struct PositionIndex
{
    int x;
    int y;
};

class Game : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(); // Gameクラスのシーン作成
    virtual bool init(); // 初期化処理
    
    CREATE_FUNC(Game); // create関数作成マクロ
    
protected:
    std::vector<Card> _cards; // カード情報
    void initCards(); // カードを初期化する
    Card getCard(); // カードを取得
    
    void createCard(PositionIndex positionIndex, int tag); // positionにカードを作成する
    void showInitCards(); // カードを表示
    void initGame(); // ゲームの初期化
    double cardScale(); // カードのスケール
    
private:
    void touchTrumpCards();
    void trumpCardButtonCallback(cocos2d::Ref* pSender);
};

#endif /* GameScene_hpp */
