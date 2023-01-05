#include "HelloWorldScene.h"
#include "NewScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    auto backgroundSprite = Sprite::create("menu2.jpg");
    backgroundSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgroundSprite->setScale(1.90);

    auto texture = Director::getInstance()->getTextureCache()->addImage("menu2.jpg");
    if (backgroundSprite->initWithTexture(texture))
    {
        this->addChild(backgroundSprite);
    }
   

    auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::Play, this));
    auto menu_item_2 = MenuItemFont::create("Highscores", CC_CALLBACK_1(HelloWorld::Highscores, this));
    auto menu_item_3 = MenuItemFont::create("Settings", CC_CALLBACK_1(HelloWorld::Settings, this));
   

    menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 4));
    menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 3));
    menu_item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 2));
   

    auto* menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);


    return true;
}

void HelloWorld::Play(cocos2d::Ref* pSender)
{
    CCLOG("Play");

    auto scene = NewScene::createScene();

    Director::getInstance()->pushScene(scene);
}

void HelloWorld::Highscores(cocos2d::Ref* pSender)
{
    CCLOG("Highscores");
}

void HelloWorld::Settings(cocos2d::Ref* pSender)
{
    CCLOG("Settings");
}


/**
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}**/



