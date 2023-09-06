
#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer()
    : _water(0),
      _started(false)
{
}

void
WaterReclaimer::start()
{
  _started = true;
  if (_water < 10)
    throw *(new MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer"));
}

void
WaterReclaimer::useWater(int water)
{
  if (_started == false)
    throw *(new UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer"));
  else if (water < 0)
    throw *(new UserError("Water use should be positif.", "WaterReclaimer"));
  else if (_water - water < 10)
    throw *(new LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer"));
  _water -= water;
}

void
WaterReclaimer::generateWater()
{
  if (_water >= 100)
    throw *(new NasaError("Cannot generate water, reclaimer already full.", "WaterReclaimer"));
  _water += 10;
}
