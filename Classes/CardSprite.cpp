//
//  CardSprite.cpp
//  trump
//
//  Created by Kouhei Suzuki on 2016/03/03.
//
//

#include "CardSprite.hpp"
#include <boost/format.hpp>

USING_NS_CC;

CardSprite* CardSprite::create(Card card, PositionIndex PositionIndex)
{
    CardSprite* cardSprite = CardSprite::create();
    
    cardSprite->setCard(card);
    cardSprite->setPositionIndex(PositionIndex);
    cardSprite->setTexture(cardSprite->getFileName(card));
    
    return cardSprite;
}

bool CardSprite::init()
{
    if (!Sprite::init()) {
        return false;
    }
    
    return true;
}

void CardSprite::onEnter()
{
    Sprite::onEnter();
}

std::string CardSprite::getFileName(Card card)
{
    // ファイル名の取得
    std::string filename;
    
    switch (card.type) {
        case Clubs: {
            filename = (boost::format("images/trump/c%02d.png") % card.number).str();
            break;
        }
        case Diamonds: {
            filename = (boost::format("images/trump/d%02d.png") % card.number).str();
            break;
        }
        case Hearts: {
            filename = (boost::format("images/trump/h%02d.png") % card.number).str();
            break;
        }
        case Spades: {
            filename = (boost::format("images/trump/s%02d.png") % card.number).str();
            break;
        }
    }
    
    return filename;
}