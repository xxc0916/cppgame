#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto back = Sprite::create("pan1.png");
	back->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	back->setScale(0.5);
	addChild(back);
	auto clipNode = ClippingNode::create(back);

	addChild(clipNode);

	clipNode->setInverted(false);

	clipNode->setAlphaThreshold(0.5);

	auto light = Sprite::create("light.png");

	clipNode->addChild(light);

	light->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));

	light->runAction(RepeatForever::create(Sequence::create(MoveBy::create(2.0, Vec2(200, 0)),
		MoveBy::create(0.01, Vec2(-200, 0))
		, NULL)));
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
