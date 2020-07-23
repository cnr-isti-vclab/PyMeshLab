from pymeshlab import pymeshlabserver as pymls

def test_point():
    p1 = pymls.Point(0, 3, 5)
    print(p1)
    assert p1.x() == 0
    assert p1.y() == 3
    assert p1.z() == 5

    print(p1.norm())
    p1.normalize()
    assert p1.norm() == 1
    print(p1.norm())

    p2 = pymls.Point(1, 1, 1)
    p2.set_x(2)
    p2.set_y(0)
    assert p2.x() == 2
    assert p2.y() == 0
    assert p2.z() == 1

    p3 = pymls.Point(2, 0, 1)
    print(p2)
    print(p3)

    assert p2 == p3
