#pragma once

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

const float PLAYER_ACC = 5000;
const float PLAYER_SPEED = 700;
const float TILT_THRESH = 400;
const int FIRE_SPEED = 150; //Lower is faster

const bool V_SYNC = false;
const bool DEBUG = true;

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const float gravity = 9.8f;
const float PI = 3.14159265359f;


enum {
	LASER,
	THWUMP,
	EXPLODE,
	MUSIC,
	ENGINE
};