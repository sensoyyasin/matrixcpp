# compute cos(u,v), the cosine of the angle between the two vectors uand v.

import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "include"))

from Vector import Vector, angle_cos
from Matrix import Matrix


def main():
    u = Vector([1., 0.])
    v = Vector([1., 0.])
    print(angle_cos(u, v)) # 1.0

    u = Vector([1., 0.])
    v = Vector([0., 1.])
    print(angle_cos(u, v)) # 0.0

    u = Vector([-1., 1.])
    v = Vector([1., -1.])
    print(angle_cos(u, v)) # -1.0

    u = Vector([2., 1.])
    v = Vector([4., 2.])
    print(angle_cos(u, v)) # 1.0

    u = Vector([1., 2., 3.])
    v = Vector([4., 5., 6.])
    print(angle_cos(u, v)) # 0.974631846


if __name__ == "__main__":
    main()
