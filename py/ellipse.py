from Math.Container.Vec import *
from Polygon import *


class Ellipse:
    @classmethod
    def from_2points(cls, p1, p2):
        center = p1.interpolate(p2, 0.5)
        radius = center.distance(p1) * 2
        return cls(center, Vec(radius, radius))

    @classmethod
    def from_3points(cls, p1, p2, p3):
        deltaA = p2 - p1
        deltaB = p3 - p2

        if abs(deltaA.x) <= 0.0000001 and abs(deltaB.y) <= 0.0000001:
            centroid = Vec(p2.x + p3.x, p1.y + p2.y) * 0.5
            radius = centroid.distance(p1)
            return cls(centroid, radius)
        else:
            aSlope = deltaA.y / deltaA.x
            bSlope = deltaB.y / deltaB.x
            if abs(aSlope - bSlope) > 0.0000001 and aSlope != 0:
                x = (aSlope * bSlope * (p1.y - p3.y) + bSlope * (p1.x + p2.x) - aSlope * (p2.x + p3.x)) / (
                        2 * (bSlope - aSlope))
                y = -(x - (p1.x + p2.x) / 2) / aSlope + (p1.y + p2.y) / 2
                centroid = Vec(x, y)
                radius = centroid.distance(p1)
                return cls(centroid, radius)

    def __init__(self, center=Vec(0, 0), radius=Vec(1, 1)):
        self.center = center
        self.radius = radius

    def __contains__(self, item):
        pass

    def circumference(self):
        return sqrt(0.5 * self.radius.squared()) * TWO_PI