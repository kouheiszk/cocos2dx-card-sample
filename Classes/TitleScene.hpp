//
//  TitleScene.hpp
//  Sample
//
//  Created by Kouhei Suzuki on 2016/02/17.
//
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(Title);

    
private:
    void startButtonCallback(cocos2d::Ref* pSender);
};

#endif /* TitleScene_hpp */
