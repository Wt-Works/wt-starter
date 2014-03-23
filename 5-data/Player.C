// a simple widget, which can be reused
// Author: I. Lazaridis info@lazaridis.com

#include "Player.h"

#include <Wt/Dbo/Impl>

DBO_INSTANTIATE_TEMPLATES(Player);

using namespace Wt;
using namespace Ex;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Player::Player()
  : points(0)
{
}

