#include "includes.h"
#include "WHGGameLayer.h"
#include "StartLayer.h"

WHGGameLayer* WHGGameLayer::create() {
	auto ret = new WHGGameLayer();
	if (ret && ret->init())
	{
		ret->autorelease();
	} 
	else
	{
		delete ret;
		ret = nullptr;
	}
	return ret;
}

CCScene* WHGGameLayer::scene()
{
	auto scene = CCScene::create();
	scene->addChild(WHGGameLayer::create());
	return scene;
}

bool WHGGameLayer::init() {

	auto label = CCLabelBMFont::create("Hello world!", "bigFont.fnt");

	label->setPosition({200, 100});
	label->setRotation(45);

	addChild(label);

	auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	auto size = backgroundSprite->getContentSize(); // this is the size of the sprite, in cocos units
	backgroundSprite->setScaleX(winSize.width / size.width);
	backgroundSprite->setScaleY(winSize.height / size.height);
	backgroundSprite->setAnchorPoint({0, 0});

	backgroundSprite->setColor({100, 100, 100});

	backgroundSprite->setZOrder(-1);
	addChild(backgroundSprite);

	auto button = CCMenuItemSpriteExtra::create(
		CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
		this,
		menu_selector(WHGGameLayer::backButtonCallback)
	);

	auto menu = CCMenu::create();
	menu->addChild(button);
	menu->setPosition({25, winSize.height - 25});

	addChild(menu);

	setKeypadEnabled(true);

	return true;
}

void WHGGameLayer::backButtonCallback(CCObject*) {
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, StartLayer::scene()));
}