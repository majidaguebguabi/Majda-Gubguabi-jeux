#include "NewScene.h"
#include "cocos2d.h"
USING_NS_CC;

Scene* NewScene::createScene()
{
    return NewScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in NewSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool NewScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //setting image bg
    auto fade = TransitionFade::create(2.0f, NewScene::createScene());
    Director::getInstance()->replaceScene(fade);
    auto backgroundSprite = Sprite::create("firstbackround.jpg");
    
    backgroundSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgroundSprite->setScale(1.50);

    auto texture = Director::getInstance()->getTextureCache()->addImage("firstbackround.jpg");
    if (backgroundSprite->initWithTexture(texture))
    {
        this->addChild(backgroundSprite);
    }
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // 4
    Sprite* mySprite;
    mySprite = Sprite::create("classic copy1.png");
    this->addChild(mySprite);
    mySprite->setPosition(Vec2(visibleSize.width * 0.09, visibleSize.height * 0.18));
     
    Sprite* wall;
    wall = Sprite::create("tuyauRouge.png");
    this->addChild(wall);
    wall->setPosition(Vec2(visibleSize.width * 0.82, visibleSize.height * 0.216));
    wall->setScale(3.0);
   
    auto eventListener = EventListenerKeyboard::create();



    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) mutable {
        Vec2 velocity = Vec2(0, 200);
        Vec2 loc = event->getCurrentTarget()->getPosition();

        auto newPosition = loc + Vec2(0, 100);
        auto jumpHeight = 100;
        auto jumpDuration = 0.5;
        auto jumpAction = MoveTo::create(jumpDuration, loc + Vec2(50, jumpHeight));

        auto downDuration = 0.5;
        auto downAction = MoveTo::create(downDuration, loc + Vec2(100, 0));
        auto sequence = Sequence::create(jumpAction, downAction, NULL);

        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            event->getCurrentTarget()->setPosition(----------loc.x, loc.y);
            event->getCurrentTarget()->setScaleX(-1);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->setPosition(++++++++++loc.x, loc.y);

            event->getCurrentTarget()->setScaleX(1);
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            event->getCurrentTarget()->runAction(sequence);;
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
            event->getCurrentTarget()->runAction(sequence);;
            break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, mySprite);

    return true;
  
}
