
#include "Errors.hpp"
#include "AtmosphereRegulator.hpp"

AtmosphereRegulator::AtmosphereRegulator()
{
  throw *(new NasaError("Not implemented.", "AtmosphereRegulator"));
}

AtmosphereRegulator::~AtmosphereRegulator()
{
}
