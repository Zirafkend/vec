from cmath import sqrt, cos, exp
class Interpolation:
    def __init__(self):
        pass
    @staticmethod
    def Sigmoid(a, b, f, sharpness=2.0):
        f = (f * 2 - 1) * sharpness
        f = (1.0 / (1.0 + exp(-f)))
        return Interpolation.Linear(a, b, f)
    @staticmethod
    def Linear(a, b, f):
        return a + (b - a) * f
    @staticmethod
    def exponential(a, b, f, exponent=2.0):
        return Interpolation.Linear(a, b, pow(f, exponent))
    @staticmethod
    def threshold(a, b, f, threshold):
        if f < threshold:
            return a
        else:
            return b
    @staticmethod
    def cosine(a, b, f):
        return b + (a - b) * (0.5 + 0.5 * cos(f * PI))
    @staticmethod
    def circular(a, b, f, flipped=False):
        if not flipped:
            return a - (b - a) * (sqrt(1 - f * f) - 1)
        else:
            f = 1 - f
            return a + (b - a) * (sqrt(1 - f * f))
