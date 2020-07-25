from pymeshlab import pymeshlabserver as pymls

def test_point():
    #test constructor , str and get methods
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

    #test scalar product
    p1 = p1 * 2;
    print('p1: ' + str(p1))
    print("p1's norm: " + str(p1.norm()))
    assert p1.norm() == 2

    #test dot product
    px = pymls.Point(1, 0, 0)
    py = pymls.Point(0, 1, 0)
    dot1 = px * py
    dot2 = px.dot(py)
    print('px dot py: ' + str(dot1))
    assert dot1 == dot2 == 0
