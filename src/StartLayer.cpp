#include "includes.h"
#include "StartLayer.h"
#include "WHGGameLayer.h"

StartLayer* StartLayer::create() {
	auto ret = new StartLayer();
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

CCScene* StartLayer::scene()
{
	auto scene = CCScene::create();
	scene->addChild(StartLayer::create());
	return scene;
}

bool StartLayer::init() {

	auto label = CCMenuItemSpriteExtra::create(CCLabelBMFont::create("Hello world!", "bigFont.fnt"), this, menu_selector(StartLayer::onGame));
	
	addChild(CCMenu::create(label, nullptr));

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
		menu_selector(StartLayer::backButtonCallback)
	);

	auto menu = CCMenu::create();
	menu->addChild(button);
	menu->setPosition({25, winSize.height - 25});

	addChild(menu);

	setKeypadEnabled(true);

	return true;
}

void StartLayer::backButtonCallback(CCObject*) {
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, MenuLayer::scene(false)));
}

void StartLayer::onGame(CCObject*) {
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, WHGGameLayer::scene()));
}
