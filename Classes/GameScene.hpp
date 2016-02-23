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

class Game : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(Game);
    
private:
    void touchTrumpCards();
    void trumpCardButtonCallback(cocos2d::Ref* pSender);
};

#endif /* GameScene_hpp */
