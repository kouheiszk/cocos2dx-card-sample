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
    static cocos2d::Scene* createScene(); // Titleクラスのシーン作成
    virtual bool init(); // 初期化処理
    
    CREATE_FUNC(Title); // create関数作成マクロ
    
private:
    void startButtonCallback(cocos2d::Ref* pSender);
};

#endif /* TitleScene_hpp */
