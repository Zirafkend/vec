# from Geom import Line
from Geom import Rectangle
from Math.Container.Vec import Vec
from Math.Series.ScaleMap import Range
class Polygon(object):
    @classmethod
    def poly(cls, sides, dim):
        return cls([Vec(cos(x), sin(x)) * dim for x in Range.radian().decimate(sides)])
    def __init__(self, vertices=None, style=None, name=None):
        if vertices is None:
            vertices = []
        self.vertices = vertices
        self.style = style
        self.name = name
    def __str__(self):
        return str(self.vertices)
    def add_vertices(self, v):
        self.vertices += [v]
    def __getitem__(self, idx):
        return self.vertices[idx]
    def __setitem__(self, idx, v):
        self.vertices[idx] = v
    def __delitem__(self, idx):
        del self.vertices[idx]
    def __add__(self, vec):
        return Polygon([pt + vec for pt in self.vertices])
    def __sub__(self, vec):
        return Polygon([pt - vec for pt in self.vertices])
    def __mul__(self, factor):
        return Polygon([pt * factor for pt in self.vertices])
    # rotate
    def rotate(self, theta):
        return Polygon([pt ^ theta for pt in self.vertices])
    def getBounds(self):
        return Rectangle.bounds(self.vertices)
    def __contains__(self, other):
        if type(other) is Polygon:
            for i in range(len(self.vertices)):
                if not self.__contains__(other.vertices[i]):
                    return False
            return True
        elif type(other) is Vec:
            num = len(self.vertices)
            i = 0
            j = num - 1
            result = False
            px = other.x
            py = other.y
            for i in range(num):
                vi = self.vertices[i]
                vj = self.vertices[j]
                if vi.y < py <= vj.y or vj.y < py <= vi.y:
                    if vi.x + (py - vi.y) / (vj.y - vi.y) * (vj.x - vi.x) < px:
                        result = not result
                    j = i
            return result
    # todo
    def area(self):
        result = 0
        num = len(self.vertices)
        for i in range(num):
            a = self.vertices[i]
            b = self.vertices[(i + 1) % num]
            result += a.x * b.y
            result -= a.y * b.x
        result *= 0.5
        return result
    def center(self):
        result = Vec()
        numpoints = len(self.vertices)
        for i in range(numpoints):
            a = self.vertices[i]
            b = self.vertices[(i + 1) % numpoints],
            factor = a.x * b.y - b.x * a.y
            result.x += (a.x + b.x) * factor
            result.y += (a.y + b.y) * factor
        return result * (1 / (self.area() * 6))
    def circumference(self):
        result = 0
        num = len(self.vertices)
        for i in range(num):
            result += self.vertices[i].distance(self.vertices[(i + 1) % num])
        return result
    def increase(self, count):
        num = len(self.vertices)
        longestID = 0,
        maxD = 0
        while num < count:
            # //find longest edge
            longestID = 0
            maxD = 0
            for i in range(num):
                d = self.vertices[i].distanceToSquared(self.vertices[(i + 1) % num])
                if (d > maxD):
                    longestID = i
                    maxD = d
                m = self.vertices[longestID] + (self.vertices[(longestID + 1) % num]) * 0.5
                # //push this into the array inbetween the 2 points
                self.vertices.splice(longestID + 1, 0, m)
                num += 1
            return self
    def decrease(self, minEdgeLen):
        minEdgeLen *= minEdgeLen
        vs = self.vertices
        reduced = []
        prev = vs[0]
        num = vs.length - 1
        reduced.append(prev)
        for i in range(num):
            vec = vs[i]
            if ( prev.distanceToSquared(vec) >= minEdgeLen ):
                reduced.append(vec)
                prev = vec
        if vs[0].distanceToSquared(vs[num]) >= minEdgeLen:
            reduced.append(vs[num])
        self.vertices = reduced
        return self
    def edges(self):
        num = len(self.vertices)
        result = []
        for i in range(num):
            from Geom.Line import Line
            result += [Line(self.vertices[i], self.vertices[(i + 1) % num])]
        return result
    def edge(self, idx):
        return self.edges()[idx]
        ## P5
        # kind POINTS, LINES, TRIANGLES, TRIANGLE_FAN, TRIANGLE_STRIP, QUADS, or QUAD_STRIP
        # def draw(self, kind=LINE, noClose=True):
        #     if self.style != None:
        #         self.style.draw()
        #
        #     if kind != LINE:
        #         beginShape(kind)
        #     else:
        #         beginShape()
        #     for pt in self.vertices:
        #         vertex(pt.x, pt.y)
        #
        #     if noClose:
        #         endShape(CLOSE)
        #     else:
        #         endShape()
        #
        #     if self.name != None:
        #         pos = self.vertices[len(self.vertices) - 1]
        #         println(pos)
        #         text(self.name, pos.x, pos.y)
        # quad(self.a().x, self.a().y, self.b().x, self.b().y, self.c().x, self.c().y, self.d().x, self.d().y)