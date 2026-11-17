#pragma once

class Object
{
	public:
 	virtual bool IUpdate() { return true; }
	virtual bool IRender() { return true; }
	virtual bool IInit() { return true; }
	
	protected:
	Object()
	{
		IInit();
	}
};
