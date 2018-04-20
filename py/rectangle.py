from Geom.Polygon import Polygon
from Math.Container.Vec import Vec
def diamond(pos=Vec(0, 0), dim=Vec(1, 1), mid_point=0.5):
    pass
def trapez(pos=Vec(0, 0), dim=Vec(1, 1), centered=True, factor=0.5):
    r = Rectangle(pos, dim)
    pts = r.polygon()
    pts[0] += Vec(r.width / 2 * factor + 1, 0)
    pts[1] -= Vec(r.width / 2 * factor + 1, 0)
    return Polygon(pts)
class Rectangle:
    def __get_x(self):
        return self.x
    def __set_x(self, x):
        self.x = x
    def __get_y(self):
        return self.x
    def __set_y(self, y):
        self.y = y
    def __get_width(self):
        return self.width
    def __set_width(self, width):
        self.width = width
    def __get_height(self):
        return self.height
    def __set_height(self, height):
        self.height = height
    x = property(__get_x, __set_x)
    y = property(__get_y, __set_y)
    width = property(__get_width, __set_width)
    height = property(__get_height, __set_height)
    @classmethod
    def bounds(cls, points):
        first = points[0]
        result = Rectangle(first.x, first.y, 0, 0, centered=False)
        for i in range(1, len(points)):
            result.growToContainPoint(points[i])
        return result
    def __init__(self, x,y, width, height, centered=True):
        if centered:
            x -= width/2.
            y -= height/ 2.0
        self.width = x
        self.height = y
        self.x = x
        self.y = y
    def __str__(self):
        return "Rect: width:" + str(self.width) + ", height:" + str(self.height) + "}"
    def aspect(self):
        return float(self.width / self.height)
    def area(self):
        return float(self.width * self.height)
    def centroid(self):
        return Vec(self.x + self.width * 0.5, self.y + self.height * 0.5)
    def circumference(self):
        return 2 * self.width + 2 * self.height
    def contains(self, other):
        if other.x < self.x or other.x >= self.x + self.width:
            return False
        if other.y < self.y or other.y >= self.y + self.height:
            return False
        return True
    def union(self, other):
        width = max(self.x + self.width, other.x + other.width) - self.x
        height = max(self.y + self.height, other.y + other.height) - self.y
        return Rectangle(Vec(min(self.x, other.x), min(self.y, other.y)), Vec(width, height))
    def isintersect(self, other):
        return not (
                self.x > self.x + other.width or self.x + self.width < other.x or self.y > other.y + other.height or self.y + self.height < other.y)
    def intersect(self, other):
        result = False
        if self.isintersect(other):
            x1 = max(self.x, other.x)
            y1 = max(self.y, other.y)
            x2 = min(getRight(), other.getRight())
            y2 = min(getBottom(), other.getBottom())
            result = Rectangle(Vec(x1, y1), Vec(x2 - x1, y2 - y1))
        return result
    def polygon(self):
        a = Vec(self.x, self.y)
        b = Vec(self.x + self.width, self.y)
        c = Vec(self.x + self.width, self.y + self.height)
        d = Vec(self.x, self.y + self.height)
        return Polygon([a, b, c, d])
    def growToContainPoint(self, p):
        if not p in self:
            if p.x < self.x:
                self.width = self.getRight() - p.x
                self.x = p.x;
            elif p.x > self.getRight():
                self.width = p.x - self.x;
            if p.y < self.y:
                self.height = self.getBottom() - p.y
                self.y = p.y
            elif (p.y > self.getBottom()):
                self.height = p.y - self.y
        return self