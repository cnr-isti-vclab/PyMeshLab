#include "color.h"

Eigen::Vector3f pymeshlab::Color::toArray3f(const QColor& c)
{
	Eigen::Vector3f v;
	v << c.redF(), c.greenF(), c.blueF();
	return v;
}

Eigen::Vector4f pymeshlab::Color::toArray4f(const QColor& c)
{
	Eigen::Vector4f v;
	v << c.redF(), c.greenF(), c.blueF(), c.alphaF();
	return v;
}

Eigen::Vector3i pymeshlab::Color::toArray3i(const QColor& c)
{
	Eigen::Vector3i v;
	v << c.red(), c.green(), c.blue();
	return v;
}

Eigen::Vector4i pymeshlab::Color::toArray4i(const QColor& c)
{
	Eigen::Vector4i v;
	v << c.red(), c.green(), c.blue(), c.alpha();
	return v;
}

pymeshlab::Color::Color()
{
}
