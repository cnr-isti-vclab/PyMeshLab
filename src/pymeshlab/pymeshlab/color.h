#ifndef PYMESHLAB_COLOR_H
#define PYMESHLAB_COLOR_H

#include <pybind11/eigen.h>
#include <Eigen/Core>
#include <QColor>

namespace pymeshlab {

class Color
{
public:
	static void create(QColor& c);
	static Eigen::Vector3f toArray3f(const QColor& c);
	static Eigen::Vector4f toArray4f(const QColor& c);
	static Eigen::Vector3i toArray3i(const QColor& c);
	static Eigen::Vector4i toArray4i(const QColor& c);
private:
	Color();
};

}

#endif // PYMESHLAB_COLOR_H
