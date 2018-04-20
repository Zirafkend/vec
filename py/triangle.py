from cmath import acos
from Geom.Drawable import Drawable
from math import sqrt
from Geom.Ellipse import Ellipse
from Polygon import *
class Triangle(object):
    @classmethod
    def equilateral(cls, a, b, top_point=0.5):
        c = a.interpolate(b, top_point)
        direction = a - b
        n = direction.perpendicular()
        c = c + n.normalize(direction.magnitude() * sqrt(3) / 2)
        return cls(a, b, c)
    def __init__(self, a, b, c, *args):
        self.c = c
        self.b = b
        self.a = a
    def polygon(self):
        return Polygon(self.a, self.b, self.c)
    def __str__(self):
        return "Triangle: " + str(self.a) + "," + str(self.b) + "," + str(self.c)
    def area(self):
        return (self.b - self.a).cross(self.c - self.a) * 0.5
    def __contains__(self, p):
        v1 = p - self.a
        v2 = p - self.b
        v3 = p - self.c
        if v1 == Vec() or v2 == Vec() or v3 == Vec():
            return True
        v1.normalize()
        v2.normalize()
        v3.normalize()
        total_angles = acos(v1.dot(v2))
        total_angles += acos(v2.dot(v3))
        total_angles += acos(v3.dot(v1))
        return abs(total_angles - TWO_PI) <= 0.001
    def center(self):
        return (self.a + self.b + self.c) / 3
    def circle(self):
        cr = self.a.bisect(self.b).cross(self.b.bisect(self.c))
        pos = Vec(cr.x / cr.z, cr.y / cr.z)
        sa = self.a.distance(self.b)
        sb = self.b.distance(self.c)
        sc = self.c.distance(self.a)
        radius = sa * sb * sc / sqrt((sa + sb + sc) * (-sa + sb + sc) * (sa - sb + sc) * (sa + sb - sc))
        return Ellipse(pos, radius)
