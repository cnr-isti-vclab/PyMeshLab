from pymeshlab import pymeshlabserver as pymls
import math

def test_point():
    print('\n')
    #test constructor , str and get methods
    p0 = pymls.Point()
    print('p0: ' + str(p0))
    assert p0.x() == p0.y() == p0.z() == 0
    p1 = pymls.Point(0, 3, 5)
    print('p1: ' + str(p1))
    assert p1.x() == 0
    assert p1.y() == 3
    assert p1.z() == 5

    #test set methods
    p2 = pymls.Point(1, 1, 1)
    p2.set_x(2)
    p2.set_y(0)
    p2.set_z(-1)
    assert p2.x() == 2
    assert p2.y() == 0
    assert p2.z() == -1

    # test norm, normalize and normalized methods
    p0 = p1.normalized()
    print("p1's norm: " + str(p1.norm()))
    p1.normalize()
    print('p0: ' + str(p0))
    print('p1: ' + str(p1))
    assert p1.norm() == 1
    print("p1's norm: " + str(p1.norm()))

    #test equals
    assert p0 == p1
    assert p0 != p2

    #test scalar product
    p1 = p1 * 2
    print('p1: ' + str(p1))
    print("p1's norm: " + str(p1.norm()))
    assert p1.norm() == 2
    p1 = p1 / 2
    assert p1.norm() == 1

    #test dot product
    px = pymls.Point(1, 0, 0)
    py = pymls.Point(0, 1, 0)
    dot1 = px * py
    dot2 = px.dot(py)
    print('px dot py: ' + str(dot1))
    assert dot1 == dot2 == 0

    #test cross product
    pz = px.cross(py)
    pz1 = px ** py
    print('px cross py: ' + str(pz))
    assert pz == pz1 == pymls.Point(0, 0, 1)

    #test unary and binary operators
    mpx = -px
    assert mpx == pymls.Point(-1, 0, 0)
    pxy = px + py
    assert pxy == pymls.Point(1, 1, 0)
    assert py == (pxy - px)

    #test comparison operators
    #vcg points use the reverse z prioritized ordering
    assert px < py < pz
    assert pz > py > px
    assert pz1 >= pz >= py
    assert px <= pz1 <= pz

    #test static member functions
    one = pymls.Point.one()
    zero = pymls.Point.zero()
    assert one == pymls.Point(1, 1, 1)
    assert zero == pymls.Point(0, 0, 0)
    polar_coord = pymls.Point.from_polar_coordinates(1, math.pi/2, 0)
    print('polar coord: ' + str(polar_coord))

    #test assignment operators
    p3 = pymls.Point(2, 2, 2)
    p3 += one
    assert p3 == pymls.Point(3, 3, 3)
    p3 -= one
    assert p3 == pymls.Point(2, 2, 2)
    p3 *= 2
    assert p3 == pymls.Point(4, 4, 4)
    p3 /= 2
    assert p3 == pymls.Point(2, 2, 2)
    pa = pymls.Point(1, 0, 0)
    pa **= py
    assert pa == pz


