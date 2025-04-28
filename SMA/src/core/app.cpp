#include "app.h"

Gui* IApplication::getGui() const
{
	return gui.get();
}
