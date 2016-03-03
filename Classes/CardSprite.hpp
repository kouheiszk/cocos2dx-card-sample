//
//  CardSprite.hpp
//  trump
//
//  Created by Kouhei Suzuki on 2016/03/03.
//
//

#ifndef CardSprite_hpp
#define CardSprite_hpp

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

class CardSprite : public cocos2d::Sprite
{
public:
    static CardSprite* create(Card card, PositionIndex PositionIndex);
    virtual bool init() override; // 初期化処理
    void onEnter() override; // 表示前処理
    
    CREATE_FUNC(CardSprite); // create関数作成マクロ
    
    CC_SYNTHESIZE(Card, _card, Card); // カード情報
    CC_SYNTHESIZE(PositionIndex, _positionIndex, PositionIndex); // 表示位置
    
private:
    std::string getFileName(Card card); // 表画像ファイル名取得
};

#endif /* CardSprite_hpp */
