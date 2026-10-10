import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "include"))

from Vector import Vector, lerp
from Matrix import Matrix


def main():
    # lerp(u, v, t) = u + t * (v - u)
    print(lerp(0., 1., 0.))    # 0.0
    print(lerp(0., 1., 1.))    # 1.0
    print(lerp(0., 1., 0.5))   # 0.5
    print(lerp(21., 42., 0.3)) # 27.3

    print(lerp(Vector([2., 1.]), Vector([4., 2.]), 0.3))
    # [2.6]
    # [1.3]

    print(lerp(Matrix([[2., 1.], [3., 4.]]), Matrix([[20., 10.], [30., 40.]]), 0.5))
    # [11.0, 5.5]
    # [16.5, 22.0]


if __name__ == "__main__":
    main()
