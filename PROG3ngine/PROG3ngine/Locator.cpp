#include "Locator.h"

Locator::Locator()
{
}

Audio* Locator::getAudio()
{
	return service_;
}

void Locator::provide(Audio* service)
{
	service_ = service;
}


Locator::~Locator()
{
}

Audio* Locator::service_;