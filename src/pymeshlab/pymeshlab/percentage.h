#ifndef PYMESHLAB_PERCENTAGE_H
#define PYMESHLAB_PERCENTAGE_H

#include <exception>
#include <string>

namespace pymeshlab {

/**
 * @brief The Percentage class
 * Simple class that permits to discriminate between absolute
 * float values (just floats) and percentage values
 */
class Percentage
{
public:
	Percentage(float value = 0);

	void setValue(float v);
	float value() const;
private:
	float val;
};

}

#endif // PYMESHLAB_PERCENTAGE_H
