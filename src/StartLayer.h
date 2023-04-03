#pragma once
#include "includes.h"

class StartLayer : public cocos2d::CCLayer
{
public:
	static StartLayer* create();
	static cocos2d::CCScene* scene();
	bool init();
	void backButtonCallback(cocos2d::CCObject*);
	void onGame(cocos2d::CCObject*);
};